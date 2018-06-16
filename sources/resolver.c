/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:59:55 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 16:52:49 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	normitik_initik(t_filler filler, int *flag, int *y, int *x)
{
	*flag = 0;
	*y -= filler.start.y;
	*x -= filler.start.x;
}

static int	valid_piece(t_filler filler, int y, int x)
{
	int i;
	int j;
	int flag;

	normitik_initik(filler, &flag, &y, &x);
	i = filler.start.y - 1;
	while (++i <= filler.end.y)
	{
		j = filler.start.x - 1;
		while (++j <= filler.end.x)
			if (filler.piece[i][j] == '*')
			{
				if (y + i >= filler.size.y || x + j >= filler.size.x)
					return (0);
				if (filler.map[y + i][x + j] == ENEMY ||
						filler.map[y + i][x + j] == PLAYER)
				{
					flag += filler.map[y + i][x + j] == PLAYER ? 1 : 2;
					if (flag > 1)
						return (0);
				}
			}
	}
	return (flag);
}

static int	count_score(t_filler filler, int y, int x)
{
	int sum;
	int i;
	int j;

	i = filler.start.y - 1;
	sum = 0;
	while (++i <= filler.end.y)
	{
		j = filler.start.x - 1;
		while (++j <= filler.end.x)
		{
			if (filler.piece[i][j] == '*')
				sum += filler.map
					[y + i - filler.start.y]
					[x + j - filler.start.x];
		}
	}
	return (sum);
}

void		resolver(t_filler filler, t_result *result)
{
	int i;
	int j;
	int score;

	i = -1;
	result->score = MAX_VALUE;
	while (++i < filler.size.y)
	{
		j = -1;
		while (++j < filler.size.x)
		{
			if (valid_piece(filler, i, j))
			{
				score = count_score(filler, i, j);
				if (result->score > score)
				{
					result->score = score;
					result->y = i - filler.start.y;
					result->x = j - filler.start.x;
				}
			}
		}
	}
}

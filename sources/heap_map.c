/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:37:26 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/13 18:40:13 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		format_map(t_filler filler)
{
	int i;
	int j;

	i = -1;
	while (++i < filler.size.y)
	{
		j = -1;
		while (++j < filler.size.x)
		{
			if (filler.map[i][j] == '.')
				filler.map[i][j] = EMPTY_CELL;
			else if (filler.map[i][j] == GET_PLAYER_BY_ID(filler.id) ||
					filler.map[i][j] == GET_PLAYER_BY_ID(filler.id) + 32)
				filler.map[i][j] = PLAYER;
			else if (filler.map[i][j] == GET_ENEMY_BY_ID(filler.id) ||
					filler.map[i][j] == GET_ENEMY_BY_ID(filler.id) + 32)
				filler.map[i][j] = ENEMY;
		}
	}
}

static void	heap_map_initialize(t_filler filler, int i, int j, int k)
{
	if (i > 0 && filler.map[i - 1][j] == k)
		filler.map[i][j] = k + 1;
	if (j > 0 && filler.map[i][j - 1] == k)
		filler.map[i][j] = k + 1;
	if (i > 0 && j > 0 && filler.map[i - 1][j - 1] == k)
		filler.map[i][j] = k + 1;
	if (i < filler.size.y - 1 && filler.map[i + 1][j] == k)
		filler.map[i][j] = k + 1;
	if (j < filler.size.x - 1 && filler.map[i][j + 1] == k)
		filler.map[i][j] = k + 1;
	if (i < filler.size.y - 1 && j < filler.size.x - 1 &&
			filler.map[i + 1][j + 1] == k)
		filler.map[i][j] = k + 1;
	if (i < filler.size.y - 1 && j > 0 && filler.map[i + 1][j - 1] == k)
		filler.map[i][j] = k + 1;
	if (j < filler.size.x - 1 && i > 0 && filler.map[i - 1][j + 1] == k)
		filler.map[i][j] = k + 1;
}

void		heap_map(t_filler filler)
{
	int i;
	int j;
	int	k;

	k = -1;
	while (++k < filler.size.x)
	{
		i = -1;
		while (++i < filler.size.y)
		{
			j = -1;
			while (++j < filler.size.x)
				if (filler.map[i][j] == EMPTY_CELL)
					heap_map_initialize(filler, i, j, k);
		}
	}
}

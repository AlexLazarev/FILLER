/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:40:21 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/13 18:51:12 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	create_player(void)
{
	char	*buf;
	int		id;

	get_next_line(0, &buf);
	id = *(buf + 10) - 48;
	free(buf);
	return (id);
}

static void	init_start_end(t_filler *filler)
{
	int i;
	int j;

	init_point(&filler->start, MAX_VALUE);
	init_point(&filler->end, -1);
	i = -1;
	while (filler->piece[++i])
	{
		j = -1;
		while (filler->piece[i][++j])
		{
			if (filler->piece[i][j] == '*')
			{
				if (filler->start.x > j)
					filler->start.x = j;
				if (filler->start.y > i)
					filler->start.y = i;
				if (filler->end.x < j)
					filler->end.x = j;
				if (filler->end.y < i)
					filler->end.y = i;
			}
		}
	}
}

void		init_filler(t_filler *filler)
{
	int		more;
	int		i;

	more = filler->id;
	if (!more)
	{
		filler->id = create_player();
		filler->map = create_field(&filler->size.x, &filler->size.y);
	}
	if (more)
		skip();
	skip();
	init_field(filler->map, filler->size.y, 4);
	if (more)
	{
		i = -1;
		while (filler->piece[++i])
			free(filler->piece[i]);
		free(filler->piece);
	}
	filler->piece = create_field(&filler->end.x, &filler->end.y);
	init_field(filler->piece, filler->end.y, 0);
	init_start_end(filler);
}

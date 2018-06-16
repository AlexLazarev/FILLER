/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:44:48 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 16:49:24 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"

void	set_score(t_global *global)
{
	int i;
	int j;

	i = -1;
	global->players[0].score = 0;
	global->players[1].score = 0;
	while (++i < global->map->y)
	{
		j = -1;
		while (++j < global->map->x)
		{
			if (global->map->field[i][j] == FIRST_PLAYER ||
				global->map->field[i][j] == FIRST_PLAYER + 32)
				global->players[0].score++;
			if (global->map->field[i][j] == SECOND_PLAYER ||
				global->map->field[i][j] == SECOND_PLAYER + 32)
				global->players[1].score++;
		}
	}
}

void	init_player(t_global *global)
{
	char	*buf;
	char	*index;
	int		i;

	skip_n(5);
	i = -1;
	while (++i < 2)
	{
		get_next_line(0, &buf);
		index = ft_strrchr(buf, '/');
		free(buf);
		global->players[i].name = ft_strdup(index + 1);
		skip_n(1);
	}
}

char	**create_field(int *x, int *y)
{
	char *buf;
	char *index;

	get_next_line(0, &buf);
	index = ft_strchr(buf, ' ') + 1;
	*y = ft_atoi(index);
	index = ft_strchr(index, ' ') + 1;
	*x = ft_atoi(index);
	free(buf);
	return (ft_strmasnew(*x, *y));
}

void	init_field(char **field, int size, int padding)
{
	char	*buf;
	int		i;

	i = 0;
	while (i < size)
	{
		get_next_line(0, &buf);
		ft_strcpy(field[i], buf + padding);
		free(buf);
		i++;
	}
	field[i] = 0;
}

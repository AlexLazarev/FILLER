/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:44:48 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 16:57:58 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	skip_n(int n)
{
	while (n--)
		skip();
}

void	skip(void)
{
	char	*buf;
	int		n;

	get_next_line(0, &buf);
	if (ft_strstr(buf, "Piece"))
	{
		n = ft_atoi(buf + 6);
		free(buf);
		skip_n(n + 1);
	}
	free(buf);
}

void	init_point(t_point *point, int value)
{
	point->x = value;
	point->y = value;
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

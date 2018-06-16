/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:49:36 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 16:50:07 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"

void	skip_n(int n)
{
	char *buf;

	while (n--)
	{
		get_next_line(0, &buf);
		free(buf);
	}
}

int		skip_to_field(void)
{
	char *buf;

	get_next_line(0, &buf);
	while (!ft_strstr(buf, "Plateau"))
	{
		if (ft_strstr(buf, "fin") || ft_strstr(buf, "aborting"))
		{
			free(buf);
			return (1);
		}
		free(buf);
		get_next_line(0, &buf);
	}
	free(buf);
	return (0);
}

int		deal_key(int key)
{
	if (key == KEY_ESC)
		exit(1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:53 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 18:31:19 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"
#include <mlx.h>

int		exit_x(void)
{
	exit(1);
	return (1);
}

void	fill_image(t_image *image, int x, int y, int rgb)
{
	if (x > 0 && x < FIELD_WIDTH && y > 0 && y < FIELD_HEIGHT)
		*(int *)(image->ptr + ((x + y * FIELD_WIDTH) * image->bpp)) = rgb;
}

void	faq(t_global *global)
{
	char *str;

	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - ((WINDOW_WIDTH - FIELD_WIDTH) / 1.8),
			(float)WINDOW_HEIGHT * 0.1, 0x00FF00, "FILLER");
	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - (WINDOW_WIDTH - FIELD_WIDTH) / 1.2,
			(float)WINDOW_HEIGHT * 0.2, 0x6600FF, global->players[0].name);
	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - (WINDOW_WIDTH - FIELD_WIDTH) / 2.6,
			WINDOW_HEIGHT * 0.2, 0xFF00FF, global->players[1].name);
	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - (WINDOW_WIDTH - FIELD_WIDTH) / 1.2,
			(float)WINDOW_HEIGHT * 0.3,
			0x6600FF, (str = ft_itoa(global->players[0].score)));
	free(str);
	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - (WINDOW_WIDTH - FIELD_WIDTH) / 2.6,
			(float)WINDOW_HEIGHT * 0.3,
			0xFF00FF, (str = ft_itoa(global->players[1].score)));
	free(str);
}

void	win_info(t_global *global)
{
	char *name;

	if (global->players[0].score > global->players[1].score)
		name = global->players[0].name;
	else if (global->players[0].score < global->players[1].score)
		name = global->players[1].name;
	else
	{
		mlx_string_put(global->mlx, global->window,
				(float)WINDOW_WIDTH - ((WINDOW_WIDTH - FIELD_WIDTH) / 1.8),
				(float)WINDOW_HEIGHT * 0.6, 0x00FF00, "DRAW");
		return ;
	}
	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - ((WINDOW_WIDTH - FIELD_WIDTH) / 1.8),
			(float)WINDOW_HEIGHT * 0.6, 0x00FF00, "WINNER");
	mlx_string_put(global->mlx, global->window,
			(float)WINDOW_WIDTH - ((WINDOW_WIDTH - FIELD_WIDTH) / 1.56),
			(float)WINDOW_HEIGHT * 0.65, 0x00FF00, name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:41 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 18:13:47 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"
#include <mlx.h>
#include <stdlib.h>

static int	get_color(t_map *map, int i, int j)
{
	t_rgb color;

	if (map->field[i][j] == EMPTY)
		color.rgba = 0xFFFFFF;
	else if (map->field[i][j] == FIRST_PLAYER)
		color.rgba = 0x6600FF;
	else if (map->field[i][j] == SECOND_PLAYER)
		color.rgba = 0xFF00FF;
	else if (map->field[i][j] == FIRST_PLAYER + 32)
		color.rgba = 0x6000CC;
	else if (map->field[i][j] == SECOND_PLAYER + 32)
		color.rgba = 0xFF00CC;
	return (color.rgba);
}

static void	draw_rectangle(t_global *global, int i, int j)
{
	int w;
	int h;

	h = -1;
	while (++h < FIELD_HEIGHT / global->map->y - PADDING)
	{
		w = -1;
		while (++w < FIELD_WIDTH / global->map->x - PADDING)
		{
			fill_image(global->image,
					w + PADDING + (j * FIELD_WIDTH / global->map->x),
					h + PADDING + (i * FIELD_HEIGHT / global->map->y),
					get_color(global->map, i, j));
		}
	}
}

static int	draw(t_global *global)
{
	int i;
	int j;

	if (!global->finish)
	{
		skip_n(1);
		init_field(global->map->field, global->map->y, 4);
		set_score(global);
		global->finish = skip_to_field();
		i = -1;
		while (++i < global->map->y)
		{
			j = -1;
			while (++j < global->map->x)
				draw_rectangle(global, i, j);
		}
		mlx_clear_window(global->mlx, global->window);
		faq(global);
		mlx_put_image_to_window(global->mlx, global->window,
				global->image->img,
				(float)WINDOW_HEIGHT * 0.02, (float)WINDOW_WIDTH * 0.01);
		if (global->finish)
			win_info(global);
	}
	return (0);
}

int			main(void)
{
	t_global	*global;

	global = (t_global*)malloc(sizeof(t_global));
	global->mlx = mlx_init();
	global->window = mlx_new_window(global->mlx,
									WINDOW_WIDTH, WINDOW_HEIGHT, "FILLER");
	global->image = (t_image*)malloc(sizeof(t_image));
	global->image->img = mlx_new_image(global->mlx,
			FIELD_WIDTH, FIELD_HEIGHT);
	global->image->ptr = mlx_get_data_addr(global->image->img,
			&global->image->bpp,
			&global->image->size_line, &global->image->endian);
	global->image->bpp /= 8;
	global->map = (t_map*)malloc(sizeof(t_map));
	global->finish = 0;
	init_player(global);
	global->map->field = create_field(&global->map->x, &global->map->y);
	mlx_loop_hook(global->mlx, draw, global);
	mlx_hook(global->window, 17, 0, exit_x, NULL);
	mlx_hook(global->window, 2, 0, deal_key, global);
	mlx_loop(global->mlx);
	return (0);
}

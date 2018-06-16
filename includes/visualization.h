/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:11:43 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 18:49:34 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUALIZATION_H
# define FILLER_VISUALIZATION_H

# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"

# define KEY_ESC 53
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 625
# define FIELD_WIDTH 750
# define FIELD_HEIGHT 600
# define X 0
# define Y 1
# define ALPHA 3
# define R 2
# define G 1
# define B 0
# define PADDING 3
# define FIRST_PLAYER 'O'
# define SECOND_PLAYER 'X'
# define EMPTY '.'

typedef union	u_rgb
{
	int				rgba;
	unsigned char	c[4];
}				t_rgb;

typedef struct	s_image
{
	void			*img;
	char			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
}				t_image;

typedef struct	s_map
{
	char	**field;
	int		x;
	int		y;
}				t_map;

typedef struct	s_player
{
	char	*name;
	int		score;
}				t_player;

typedef struct	s_global
{
	void			*mlx;
	t_image			*image;
	void			*window;
	t_map			*map;
	t_player		players[2];
	int				finish;
}				t_global;

void			skip_n(int n);
int				skip_to_field();
char			**create_field(int *x, int *y);
void			init_field(char **field, int size, int padding);
void			init_player(t_global *global);
void			fill_image(t_image *image, int x, int y, int rgb);
int				exit_x(void);
void			faq(t_global *global);
void			win_info(t_global *global);
void			set_score(t_global *global);
int				deal_key(int key);

#endif

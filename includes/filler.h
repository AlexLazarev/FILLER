/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:26:56 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 17:11:12 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"

# define GET_PLAYER_BY_ID(id) (id == 1 ? 'O' : 'X')
# define GET_ENEMY_BY_ID(id) (id == 1 ? 'X' : 'O')
# define EMPTY_CELL -2
# define ENEMY 0
# define PLAYER -1
# define MAX_VALUE 100000

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_filler
{
	int		id;
	char	**map;
	t_point	size;
	char	**piece;
	t_point start;
	t_point	end;
}				t_filler;

typedef struct	s_result
{
	int score;
	int x;
	int y;
}				t_result;

void			format_map(t_filler filler);
void			heap_map(t_filler filler);
void			init_filler(t_filler *filler);
void			resolver(t_filler filler, t_result *result);
void			skip();
void			init_point(t_point *point, int value);
char			**create_field(int *x, int *y);
void			init_field(char **field, int size, int padding);

#endif

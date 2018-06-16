/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:03:41 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/13 19:08:24 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/visualization.h"

t_result	*create_result(void)
{
	t_result	*result;

	if (!(result = (t_result*)malloc(sizeof(t_result))))
		return (NULL);
	result->x = 0;
	result->y = 0;
	result->score = 0;
	return (result);
}

int			main(void)
{
	t_filler *filler;
	t_result *result;

	filler = (t_filler*)malloc(sizeof(t_filler));
	filler->id = 0;
	result = create_result();
	while (result->score != MAX_VALUE)
	{
		init_filler(filler);
		format_map(*filler);
		heap_map(*filler);
		resolver(*filler, result);
		ft_printf("%d %d\n", result->y, result->x);
	}
	return (0);
}

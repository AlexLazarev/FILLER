/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ranknumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:12:03 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/09 16:12:23 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ranknumber_base(intmax_t value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		count++;
	}
	return (count);
}

int	ft_rankunumber_base(uintmax_t value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		count++;
	}
	return (count);
}

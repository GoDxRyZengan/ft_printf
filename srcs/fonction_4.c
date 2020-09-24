/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:06:12 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/18 18:12:32 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					nb_cara_hexa(int nb)
{
	int				res;
	long long int	tmp;
	long long int	neg;

	res = 1;
	tmp = nb;
	neg = 4294967296;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		tmp = neg - tmp;
	}
	while (tmp > 15)
	{
		res++;
		tmp = tmp / 16;
	}
	return (res);
}

int					end_width(const char *str, int index)
{
	while ((str[index] >= '0' && str[index] <= '9')
				|| str[index] == '*')
		index++;
	return (index);
}

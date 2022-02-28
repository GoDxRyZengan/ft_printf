/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_cara.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:00:51 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 17:01:58 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	flag_zero_c(t_list struc, int c)
{
	int	res;

	res = 1;
	while (struc.width > 1)
	{
		ft_putchar('0');
		struc.width--;
		res++;
	}
	ft_putchar(c);
	return (res);
}

int	flag_less_c(t_list struc, int c)
{
	int	res;

	res = 1;
	ft_putchar(c);
	while (struc.width > 1)
	{
		ft_putchar(' ');
		struc.width--;
		res++;
	}
	return (res);
}

int	no_flag_c(t_list struc, int c)
{
	int	res;

	res = 1;
	while (struc.width > 1)
	{
		ft_putchar(' ');
		struc.width--;
		res++;
	}
	ft_putchar(c);
	return (res);
}

int	affichage_cara(t_list struc, va_list ap)
{
	int	c;
	int	res;

	c = va_arg(ap, int);
	if (struc.flag == '0')
		res = flag_zero_c(struc, c);
	else if (struc.flag == '-')
		res = flag_less_c(struc, c);
	else
		res = no_flag_c(struc, c);
	return (res);
}

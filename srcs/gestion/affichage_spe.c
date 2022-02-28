/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:13:01 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/18 18:13:04 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	flag_zero_spe(t_list struc)
{
	int	res;

	res = 1;
	while (struc.width > 1)
	{
		ft_putchar('0');
		struc.width--;
		res++;
	}
	ft_putchar('%');
	return (res);
}

int	flag_less_spe(t_list struc)
{
	int	res;

	res = 1;
	ft_putchar('%');
	while (struc.width > 1)
	{
		ft_putchar(' ');
		struc.width--;
		res++;
	}
	return (res);
}

int	no_flag_spe(t_list struc)
{
	int	res;

	res = 1;
	while (struc.width > 1)
	{
		ft_putchar(' ');
		struc.width--;
		res++;
	}
	ft_putchar('%');
	return (res);
}

int	affichage_spe(t_list struc)
{
	int	res;

	if (struc.flag == '0')
		res = flag_zero_spe(struc);
	else if (struc.flag == '-')
		res = flag_less_spe(struc);
	else
		res = no_flag_spe(struc);
	return (res);
}

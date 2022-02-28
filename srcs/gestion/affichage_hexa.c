/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:37:18 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 17:06:22 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	no_flag_h(t_list struc, int nb, int size)
{
	int		res;

	res = size;
	while (size < struc.prec || size < struc.width)
	{
		while (struc.width > struc.prec && struc.width > size)
		{
			ft_putchar(' ');
			struc.width--;
			res++;
		}
		if (size < struc.prec)
		{
			ft_putchar('0');
			size++;
			res++;
		}
	}
	if (struc.def == 'x')
		ft_putnbr_hexa_min(nb);
	else
		ft_putnbr_hexa_maj(nb);
	return (res);
}

int	flag_zero_h(t_list struc, int nb, int size)
{
	int		res;

	res = size;
	if (struc.prec >= 0)
		res = no_flag_h(struc, nb, size);
	else
	{
		while (size < struc.prec || size < struc.width)
		{
			ft_putchar('0');
			res++;
			size++;
		}
		if (struc.def == 'x')
			ft_putnbr_hexa_min(nb);
		else
			ft_putnbr_hexa_maj(nb);
	}
	return (res);
}

int	flag_less_h(t_list struc, int nb, int size)
{
	int		res;

	res = size;
	while (size < struc.prec)
	{
		ft_putchar('0');
		res++;
		size++;
	}
	if (struc.def == 'x')
		ft_putnbr_hexa_min(nb);
	else
		ft_putnbr_hexa_maj(nb);
	while (size < struc.width)
	{
		ft_putchar(' ');
		res++;
		size++;
	}
	return (res);
}

int	spec_case_h(t_list struc, int nb, int size)
{
	int		res;

	res = 0;
	while (struc.width > 0)
	{
		ft_putchar(' ');
		res++;
		struc.width--;
	}
	return (res);
}

int	affichage_hexa(t_list struc, va_list ap)
{
	int		nb;
	int		size;
	int		res;

	nb = va_arg(ap, int);
	size = nb_cara_hexa(nb);
	if (struc.prec == 0 && nb == 0)
		res = spec_case_h(struc, nb, size);
	else if (struc.flag == '0')
		res = flag_zero_h(struc, nb, size);
	else if (struc.flag == '-')
		res = flag_less_h(struc, nb, size);
	else
		res = no_flag_h(struc, nb, size);
	return (res);
}

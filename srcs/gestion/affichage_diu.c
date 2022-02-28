/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:36:32 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 17:02:45 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	no_flag(t_list struc, long long int nb, int size)
{
	int				res;

	res = size;
	if (nb < 0)
		struc.width--;
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
	ft_putnbr(nb);
	return (res);
}

int	flag_zero(t_list struc, long long int nb, int size)
{
	int				res;

	res = size;
	if (nb < 0)
		struc.width--;
	if (struc.prec >= 0)
		res = no_flag(struc, nb, size);
	else
	{
		while (size < struc.prec || size < struc.width)
		{
			ft_putchar('0');
			res++;
			size++;
		}
		ft_putnbr(nb);
	}
	return (res);
}

int	flag_less(t_list struc, long long int nb, int size)
{
	int				res;

	res = size;
	if (nb < 0)
		struc.width--;
	while (size < struc.prec)
	{
		ft_putchar('0');
		res++;
		size++;
	}
	ft_putnbr(nb);
	while (size < struc.width)
	{
		ft_putchar(' ');
		res++;
		size++;
	}
	return (res);
}

int	spec_case(t_list struc, int nb, int size)
{
	int				res;

	res = 0;
	while (struc.width > 0)
	{
		ft_putchar(' ');
		res++;
		struc.width--;
	}
	return (res);
}

int	affichage_diu(t_list struc, va_list ap)
{
	int				nb;
	int				res;
	long long int	tmp;

	nb = va_arg(ap, int);
	tmp = (long long int)nb;
	if (struc.def == 'u' && nb < 0)
		tmp = 4294967296 + tmp;
	res = nb_cara(tmp);
	if (struc.prec == 0 && tmp == 0)
		res = spec_case(struc, tmp, res);
	else if ((tmp < 0 && struc.prec > res)
		|| (tmp < 0 && res < (struc.width - 1)))
		res = spec_case_2(struc, tmp, res);
	else if (struc.flag == '0')
		res = flag_zero(struc, tmp, res);
	else if (struc.flag == '-')
		res = flag_less(struc, tmp, res);
	else
		res = no_flag(struc, tmp, res);
	if (tmp < 0)
		res++;
	return (res);
}

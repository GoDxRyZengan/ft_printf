/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:53:49 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 17:00:06 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int							f_l_p(t_list struc, unsigned long long nb, int size)
{
	int						res;

	res = size + 2;
	while (size < struc.prec)
	{
		ft_putchar('0');
		res++;
		size++;
	}
	ft_putstr("0x");
	ft_putnbr_hexa_adress(nb);
	while (size < struc.width)
	{
		ft_putchar(' ');
		res++;
		size++;
	}
	return (res);
}

int							n_f_p(t_list struc, unsigned long long nb, int size)
{
	int						res;

	res = size + 2;
	while (struc.width > struc.prec && struc.width > size)
	{
		ft_putchar(' ');
		struc.width--;
		res++;
	}
	ft_putstr("0x");
	while (size < struc.prec)
	{
		ft_putchar('0');
		size++;
		res++;
	}
	ft_putnbr_hexa_adress(nb);
	return (res);
}

int							f_z_p(t_list struc, unsigned long long nb, int size)
{
	int						res;

	if (struc.prec >= 0)
		res = n_f_p(struc, nb, size);
	else
	{
		res = size + 2;
		while (size < struc.prec || size < struc.width)
		{
			ft_putchar('0');
			res++;
			size++;
		}
		ft_putstr("0x");
		ft_putnbr_hexa_adress(nb);
	}
	return (res);
}

int							spec_case_p(t_list struc, int nb, int size)
{
	int						res;

	res = 2;
	while (struc.width > 0)
	{
		ft_putchar(' ');
		res++;
		struc.width--;
	}
	ft_putstr("0x");
	return (res);
}

int							affichage_adress(t_list struc, va_list ap)
{
	int						res;
	int						size;
	unsigned long long int	nb;

	nb = (unsigned long long)va_arg(ap, void*);
	size = nb_cara_adress(nb);
	if (struc.width >= 2)
		struc.width = struc.width - 2;
	if (struc.prec == 0 && nb == 0)
		res = spec_case_p(struc, nb, size);
	else if (struc.flag == '0')
		res = f_z_p(struc, nb, size);
	else if (struc.flag == '-')
		res = f_l_p(struc, nb, size);
	else
		res = n_f_p(struc, nb, size);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 01:03:25 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/17 01:04:18 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			nb_cara(long long int nb)
{
	int		i;

	i = 1;
	if (nb < 0)
		nb = nb * -1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int			spec_case_no_flag(t_list struc, long long int nb, int size)
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
		ft_putchar('-');
		while (size < struc.prec)
		{
			ft_putchar('0');
			size++;
			res++;
		}
	}
	ft_putnbr(nb);
	return (res);
}

int			spec_case_flag_less(t_list struc, long long int nb, int size)
{
	int		res;

	res = size;
	ft_putchar('-');
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

int			spec_case_flag_zero(t_list struc, long long int nb, int size)
{
	int		res;

	res = size;
	ft_putchar('-');
	while (size < struc.width)
	{
		ft_putchar('0');
		res++;
		size++;
	}
	ft_putnbr(nb);
	return (res);
}

int			spec_case_2(t_list struc, long long int nb, int size)
{
	int		res;

	if (nb < 0 && struc.width > 1)
		struc.width--;
	if (nb < 0)
		nb = nb * -1;
	if ((struc.flag == '0' && struc.prec >= 0) || struc.flag == '5')
		res = spec_case_no_flag(struc, nb, size);
	else if (struc.flag == '0')
		res = spec_case_flag_zero(struc, nb, size);
	else if (struc.flag == '-')
		res = spec_case_flag_less(struc, nb, size);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:02:41 by hucoulon          #+#    #+#             */
/*   Updated: 2020/01/12 18:17:15 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void					ft_putchar(char c)
{
	write(1, &c, 1);
}

void					ft_putnbr(long long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void					ft_putnbr_hexa_min(int nb)
{
	long long int		i;
	long long int		neg;

	neg = 4294967296;
	i = nb;
	if (nb < 0)
	{
		i = -i;
		i = neg - i;
	}
	if (i > 15)
		ft_putnbr_hexa_min(i / 16);
	if ((i % 16) < 10)
		ft_putchar(i % 16 + 48);
	if ((i % 16) > 9)
		ft_putchar(i % 16 + 87);
}

void					ft_putnbr_hexa_maj(int nb)
{
	long long int		i;
	long long int		neg;

	neg = 4294967296;
	i = nb;
	if (nb < 0)
	{
		i = -i;
		i = neg - i;
	}
	if (i > 15)
		ft_putnbr_hexa_maj(i / 16);
	if ((i % 16) < 10)
		ft_putchar(i % 16 + 48);
	if ((i % 16) > 9)
		ft_putchar(i % 16 + 55);
}

int						nb_cara_adress(unsigned long long nb)
{
	int					res;
	unsigned long long	neg;

	neg = ULLONG_MAX;
	res = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		nb = neg - nb;
	}
	while (nb > 15)
	{
		res++;
		nb = nb / 16;
	}
	return (res);
}

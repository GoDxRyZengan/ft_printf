/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:50:59 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 16:51:03 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t					ft_strlen(const char *s)
{
	size_t				a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

char					*ft_strdup(const char *s1)
{
	char				*cpy;
	int					a;

	a = 0;
	if (!s1 || s1 == NULL)
		return (NULL);
	while (s1[a])
		a++;
	if (!(cpy = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (s1[a])
	{
		cpy[a] = s1[a];
		a++;
	}
	cpy[a] = '\0';
	return (cpy);
}

void					ft_putstr(char *str)
{
	int					i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char					*ajust_str(t_list struc, char *str)
{
	int					i;

	i = 0;
	if (struc.prec == 0)
		str = NULL;
	else
	{
		while (i < struc.prec)
			i++;
		str[i] = '\0';
	}
	return (str);
}

void					ft_putnbr_hexa_adress(unsigned long long nb)
{
	unsigned long long	i;
	unsigned long long	neg;

	neg = ULLONG_MAX;
	i = nb;
	if (nb < 0)
	{
		i = -i;
		i = neg - i;
	}
	if (i > 15)
		ft_putnbr_hexa_adress(i / 16);
	if ((i % 16) < 10)
		ft_putchar(i % 16 + 48);
	if ((i % 16) > 9)
		ft_putchar(i % 16 + 87);
}

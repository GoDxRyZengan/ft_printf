/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:04:15 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 17:04:23 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;
	size_t	res;

	res = 0;
	a = 0;
	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] == s2[a])
			a++;
		else
		{
			res = (unsigned char)s1[a] - (unsigned char)s2[a];
			return (res);
		}
	}
	return (res);
}

int			flag_zero_s(t_list struc, char *str, int size)
{
	int		res;

	if (struc.prec == 0)
		size = 0;
	res = size;
	while (struc.width > size)
	{
		ft_putchar('0');
		size++;
		res++;
	}
	if (struc.prec != 0)
		ft_putstr(str);
	return (res);
}

int			flag_less_s(t_list struc, char *str, int size)
{
	int		res;

	if (struc.prec == 0)
		size = 0;
	res = size;
	if (struc.prec != 0)
		ft_putstr(str);
	while (size < struc.width)
	{
		ft_putchar(' ');
		size++;
		res++;
	}
	return (res);
}

int			no_flag_s(t_list struc, char *str, int size)
{
	int		res;

	if (struc.prec == 0)
		size = 0;
	res = size;
	while (size < struc.width)
	{
		ft_putchar(' ');
		size++;
		res++;
	}
	if (struc.prec != 0)
		ft_putstr(str);
	return (res);
}

int			affichage_str(t_list struc, va_list ap)
{
	char	*tmp;
	int		res;
	int		size;

	tmp = va_arg(ap, char*);
	if (tmp == NULL || struc.prec == 0)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(tmp);
	size = ft_strlen((const char*)tmp);
	if (size > struc.prec && struc.prec > 0)
	{
		tmp = ajust_str(struc, tmp);
		size = ft_strlen((const char*)tmp);
	}
	if (struc.flag == '0')
		res = flag_zero_s(struc, tmp, size);
	else if (struc.flag == '-')
		res = flag_less_s(struc, tmp, size);
	else
		res = no_flag_s(struc, tmp, size);
	free(tmp);
	return (res);
}

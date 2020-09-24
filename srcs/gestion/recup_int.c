/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:37:23 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/16 17:13:47 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	gestion_flag(const char *params, int index, t_list struc)
{
	if (params[index] == '-')
		struc.flag = '-';
	else if (params[index] == '0')
	{
		struc.flag = '0';
		while (params[index] == '0' && params[index])
		{
			index++;
			if (params[index] == '-')
			{
				struc.flag = '-';
				break ;
			}
		}
	}
	return (struc.flag);
}

int		gestion_width(const char *params, int index, va_list ap, t_list struc)
{
	int	nb;

	nb = 0;
	if (params[index] == '*')
		struc.width = va_arg(ap, int);
	else if (params[index] != '*')
	{
		while (params[index] >= '0' && params[index] <= '9')
		{
			nb = nb * 10 + (params[index] - 48);
			index++;
		}
		struc.width = nb;
	}
	return (struc.width);
}

int		gestion_prec(const char *params, int index, va_list ap, t_list struc)
{
	int	nb;

	nb = 0;
	index++;
	if (params[index] == '*')
		struc.prec = va_arg(ap, int);
	else if (params[index] >= '0' && params[index] <= '9')
	{
		while (params[index] >= '0' && params[index] <= '9')
		{
			nb = nb * 10 + (params[index] - 48);
			index++;
		}
		struc.prec = nb;
	}
	else
		struc.prec = 0;
	return (struc.prec);
}

int		recup_int(const char *params, int index, va_list ap, t_list struc)
{
	int	res;

	if (params[index] == '0' || params[index] == '-')
	{
		struc.flag = gestion_flag(params, index, struc);
		while (params[index] == '0' || params[index] == '-')
			index++;
	}
	if ((params[index] >= '1' && params[index] <= '9') || params[index] == '*')
	{
		struc.width = gestion_width(params, index, ap, struc);
		index = end_width(params, index);
	}
	if (struc.width < 0)
	{
		struc.flag = '-';
		struc.width = struc.width * -1;
	}
	if (params[index] == '.')
		struc.prec = gestion_prec(params, index, ap, struc);
	if (struc.def == 'd' || struc.def == 'i' || struc.def == 'u')
		res = affichage_diu(struc, ap);
	if (struc.def == 'x' || struc.def == 'X')
		res = affichage_hexa(struc, ap);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:08:10 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/18 18:13:46 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	gestion_flag_p(const char *params, int index, t_list struc)
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

int	gestion_width_p(const char *params, int index, va_list ap, t_list struc)
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

int	gestion_prec_p(const char *params, int index, va_list ap, t_list struc)
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

int	recup_adress(const char *params, int index, va_list ap, t_list struc)
{
	int	res;

	res = 0;
	if (params[index] == '0' || params[index] == '-')
	{
		struc.flag = gestion_flag_p(params, index, struc);
		while (params[index] == '0' || params[index] == '-')
			index++;
	}
	if ((params[index] >= '1' && params[index] <= '9') || params[index] == '*')
	{
		struc.width = gestion_width_p(params, index, ap, struc);
		index = end_width(params, index);
	}
	if (struc.width < 0)
	{
		struc.flag = '-';
		struc.width = struc.width * -1;
	}
	if (params[index] == '.')
		struc.prec = gestion_prec_p(params, index, ap, struc);
	res = affichage_adress(struc, ap);
	return (res);
}

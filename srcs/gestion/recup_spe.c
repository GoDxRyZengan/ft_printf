/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:14:02 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/18 18:14:08 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	gestion_flag_spe(const char *params, int index, t_list struc)
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

int		g_w_spe(const char *params, int index, va_list ap, t_list struc)
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

int		recup_spe(const char *params, int index, va_list ap, t_list struc)
{
	int	res;

	res = 0;
	if (params[index] == '0' || params[index] == '-')
	{
		struc.flag = gestion_flag_spe(params, index, struc);
		while (params[index] == '0' || params[index] == '-')
			index++;
	}
	if ((params[index] >= '1' && params[index] <= '9') || params[index] == '*')
	{
		struc.width = g_w_spe(params, index, ap, struc);
		index = end_width(params, index);
	}
	if (struc.width < 0)
	{
		struc.flag = '-';
		struc.width = struc.width * -1;
	}
	res = affichage_spe(struc);
	return (res);
}

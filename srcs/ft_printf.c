/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:10:16 by hucoulon          #+#    #+#             */
/*   Updated: 2020/01/12 18:43:42 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	end_print(const char *params, int index)
{
	while (params[index] != 'c' && params[index] != 's'
		&& params[index] != 'p' && params[index] != 'd'
		&& params[index] != 'i' && params[index] != 'u'
		&& params[index] != 'x' && params[index] != 'X'
		&& params[index] != '%' && params[index])
		index++;
	index++;
	return (index);
}

char	check_def(const char *params, int index)
{
	char	def;

	while (params[index] != 'c' && params[index] != 's'
		&& params[index] != 'p' && params[index] != 'd'
		&& params[index] != 'i' && params[index] != 'u'
		&& params[index] != 'x' && params[index] != 'X'
		&& params[index] != '%' && params[index])
		index++;
	if (params[index] != '\0')
		def = params[index];
	else
		def = '5';
	return (def);
}

int	gestion_print(const char *params, int index, va_list ap)
{
	t_list	struc;
	int		res;
	char	def;

	res = 0;
	struc.flag = '5';
	struc.width = 0;
	struc.prec = -1;
	def = check_def(params, index);
	struc.def = def;
	if (def == 'd' || def == 'i' || def == 'u' || def == 'x' || def == 'X')
		res = recup_int(params, index, ap, struc);
	else if (def == '%')
		res = recup_spe(params, index, ap, struc);
	else if (def == 'c')
		res = recup_cara(params, index, ap, struc);
	else if (def == 's')
		res = recup_str(params, index, ap, struc);
	else if (def == 'p')
		res = recup_adress(params, index, ap, struc);
	return (res);
}

int	ft_printf(const char *params, ...)
{
	va_list	ap;
	int		index;
	int		res;

	res = 0;
	index = 0;
	va_start(ap, params);
	params = ft_strdup(params);
	while (params[index])
	{
		if (params[index] == '%')
		{
			index++;
			res = res + gestion_print(params, index, ap);
			index = end_print(params, index);
		}
		else
		{
			ft_putchar(params[index]);
			res++;
			index++;
		}
	}
	va_end(ap);
	return (res);
}

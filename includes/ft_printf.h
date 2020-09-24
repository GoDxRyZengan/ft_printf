/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:15:33 by hucoulon          #+#    #+#             */
/*   Updated: 2020/02/18 18:43:14 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_list
{
	char		flag;
	int			width;
	int			prec;
	char		def;
}				t_list;

int				end_width(const char *str, int index);
int				nb_cara_hexa(int nb);
int				spec_case_2(t_list struc, long long int nb, int size);
int				nb_cara(long long int nb);
void			ft_putnbr_hexa_adress(unsigned long long nb);
void			affiche_adress(int nb);
size_t			ft_strlen(const char *s);
char			*ajust_str(t_list struc, char *str);
int				affichage_spe(t_list struc);
int				affichage_adress(t_list struc, va_list ap);
int				affichage_str(t_list struc, va_list ap);
int				affichage_hexa(t_list struc, va_list ap);
int				affichage_diu(t_list struc, va_list ap);
int				affichage_cara(t_list struc, va_list ap);
char			*int_to_hexa_str(long long int nb, char *str, int index);
int				nb_cara_adress(unsigned long long nb);
char			*ft_strdup(const char *s1);
void			ft_putnbr(long long int nb);
void			ft_putstr(char *str);
void			ft_putnbr_hexa_min(int nb);
void			ft_putnbr_hexa_maj(int nb);
void			ft_putchar(char c);
int				ft_printf(const char *params, ...);
int				recup_spe(const char *params, int index, va_list ap,
				t_list struc);
int				recup_int(const char *params, int index, va_list ap,
				t_list struc);
int				recup_cara(const char *params, int index, va_list ap,
				t_list struc);
int				recup_str(const char *params, int index, va_list ap,
				t_list struc);
int				recup_adress(const char *params, int index, va_list ap,
				t_list struc);

#endif

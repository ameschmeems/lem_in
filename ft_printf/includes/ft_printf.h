/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:38:42 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/17 11:10:40 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		hex_len(long n);

void	print_char(char c, int *len);
void	print_str(char *s, int *len);
void	print_digit(int n, int *len);
void	print_unsdigit(unsigned long n, int *len);
void	print_lhex(long n, int *len);
void	print_uphex(long n, int *len);
void	print_ptr(void *ptr, int *len);

#endif
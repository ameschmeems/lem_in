/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 07:06:57 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/17 11:10:43 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	checks(char *s, va_list args, size_t i, int *len)
{
	if (s[i] == 'c')
		print_char(va_arg(args, int), len);
	else if (s[i] == 's')
		print_str(va_arg(args, char *), len);
	else if (s[i] == 'p')
		print_ptr(va_arg(args, void *), len);
	else if (s[i] == 'd' || s[i] == 'i')
		print_digit(va_arg(args, int), len);
	else if (s[i] == 'u')
		print_unsdigit(va_arg(args, unsigned long), len);
	else if (s[i] == 'x')
		print_lhex(va_arg(args, long), len);
	else if (s[i] == 'X')
		print_uphex(va_arg(args, long), len);
	else if (s[i] == '%')
		print_char('%', len);
}

static void	utils(char *s, va_list args, int *len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			checks(s, args, i, len);
		}
		else
			print_char(s[i], len);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	*copy;
	int		len;

	len = 0;
	va_start(args, s);
	copy = ft_strdup(s);
	utils(copy, args, &len);
	va_end(args);
	free(copy);
	return (len);
}

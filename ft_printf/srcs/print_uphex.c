/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 02:00:50 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/17 11:10:42 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*dec_to_uphex(long n)
{
	char	*uphex;
	int		remainder;
	int		len;

	len = hex_len(n);
	uphex = malloc(sizeof(char) * (len + 1));
	uphex[len] = 0;
	if (n == 0)
		uphex[0] = '0';
	while (n)
	{
		len--;
		remainder = n % 16;
		if (remainder < 10)
			uphex[len] = remainder + '0';
		else
			uphex[len] = remainder + 'A' - 10;
		n /= 16;
	}
	return (uphex);
}

void	print_uphex(long n, int *len)
{
	char	*uphex;

	uphex = dec_to_uphex(n);
	print_str(uphex, len);
	free(uphex);
}

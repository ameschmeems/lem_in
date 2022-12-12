/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:33:27 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/17 11:10:41 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	hex_len(long n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*dec_to_lhex(long n)
{
	char	*lhex;
	int		remainder;
	int		len;

	len = hex_len(n);
	lhex = malloc(sizeof(char) * (len + 1));
	lhex[len] = 0;
	if (n == 0)
		lhex[0] = '0';
	while (n)
	{
		len--;
		remainder = n % 16;
		if (remainder < 10)
			lhex[len] = remainder + '0';
		else
			lhex[len] = remainder + 87;
		n /= 16;
	}
	return (lhex);
}

void	print_lhex(long n, int *len)
{
	char	*lhex;

	lhex = dec_to_lhex(n);
	print_str(lhex, len);
	free(lhex);
}

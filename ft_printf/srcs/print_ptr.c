/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 02:08:54 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/28 17:43:37 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ptr_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*dec_to_ptr(unsigned long long n)
{
	char	*hex;
	int		remainder;
	int		len;

	len = ptr_hex_len(n);
	hex = malloc(sizeof(char) * (len + 1));
	hex[len] = 0;
	if (n == 0)
		hex[0] = '0';
	while (n)
	{
		len--;
		remainder = n % 16;
		if (remainder < 10)
			hex[len] = remainder + '0';
		else
			hex[len] = remainder + 87;
		n /= 16;
	}
	return (hex);
}

void	print_ptr(void *ptr, int *len)
{
	char	*ptr_hex;

	if (!ptr)
	{
		print_str("0x0", len);
		return ;
	}
	ptr_hex = dec_to_ptr((unsigned long long int)ptr);
	print_str("0x", len);
	print_str(ptr_hex, len);
	free(ptr_hex);
}

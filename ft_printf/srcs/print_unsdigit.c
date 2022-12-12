/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:07:34 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/17 10:58:29 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	uint_len(unsigned long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*uitoa(unsigned long n)
{
	char			*result;
	unsigned int	len;

	len = uint_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (n == 0)
		result[0] = '0';
	while (n && len > 0)
	{
		len--;
		result[len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

void	print_unsdigit(unsigned long n, int *len)
{
	char	*s;

	s = uitoa(n);
	print_str(s, len);
	free(s);
}

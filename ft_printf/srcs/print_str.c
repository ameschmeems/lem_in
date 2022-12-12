/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 00:51:54 by kpucylo           #+#    #+#             */
/*   Updated: 2021/12/17 09:50:04 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_str(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		print_str("(null)", len);
		return ;
	}
	while (s[i])
	{
		print_char(s[i], len);
		i++;
	}
}

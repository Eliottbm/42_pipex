/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:30:03 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/24 14:00:54 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_len(unsigned int nb, int uplow, int *counter)
{
	char	*base;

	if (uplow == 0)
		base = "0123456789abcdef";
	if (uplow == 1)
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_puthex_len((nb / 16), uplow, counter);
		ft_puthex_len((nb % 16), uplow, counter);
	}
	else
		ft_putchar_len(base[nb], counter);
}

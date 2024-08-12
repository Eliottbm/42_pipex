/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:06:14 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/14 13:30:23 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_len(int n, int *counter)
{
	long	nb;
	char	c;

	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_len('-', counter);
	}
	if (nb > 9)
	{
		ft_putnbr_len((int)(nb / 10), counter);
		ft_putnbr_len((int)(nb % 10), counter);
	}
	else
	{
		c = nb + '0';
		ft_putchar_len(c, counter);
	}
}

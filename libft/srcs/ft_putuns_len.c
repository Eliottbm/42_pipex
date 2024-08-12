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

void	ft_putuns_len(unsigned int n, int *counter)
{
	char	c;

	if (n > 9)
	{
		ft_putuns_len((n / 10), counter);
		ft_putuns_len((n % 10), counter);
	}
	else
	{
		c = n + '0';
		ft_putchar_len(c, counter);
	}
}

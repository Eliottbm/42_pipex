/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:54:05 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/24 14:00:54 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len(char *s, int *counter)
{
	int	i;

	if (!s)
	{
		write (1, "(null)", 6);
		*counter += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_len(s[i], counter);
		i++;
	}
}

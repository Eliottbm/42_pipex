/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:34:16 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/29 16:06:34 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsize(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	int		i;
	int		is_neg;

	ln = (long)n;
	is_neg = 0;
	if (ln < 0)
	{
		is_neg = 1;
		ln = -ln;
	}
	i = ft_strsize(ln) + is_neg;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (is_neg == 1)
		str[0] = '-';
	str[i] = '\0';
	while (i > is_neg)
	{
		str[--i] = (ln % 10) + '0';
		ln /= 10;
	}
	return (str);
}

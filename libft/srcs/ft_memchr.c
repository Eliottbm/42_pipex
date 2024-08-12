/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:17:21 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/31 17:20:42 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	unc;
	size_t			i;

	str = (unsigned char *)s;
	unc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == unc)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}

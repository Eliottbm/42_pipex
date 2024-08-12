/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:43:40 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/28 15:48:04 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*strdest;
	char	*strsrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	strdest = (char *)dest;
	strsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		if (dest <= src)
			strdest[i] = strsrc[i];
		else if (dest > src)
			strdest[(n - 1) - i] = strsrc[(n - 1) - i];
		i++;
	}
	return (dest);
}

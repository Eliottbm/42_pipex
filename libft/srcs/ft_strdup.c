/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:20:22 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/22 16:40:20 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*dst;
	int		srclen;

	srclen = ft_strlen(src);
	dst = malloc(sizeof(char) * (srclen + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, (srclen + 1));
	return (dst);
}

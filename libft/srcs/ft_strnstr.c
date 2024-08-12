/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:46:52 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/31 15:44:12 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (str);
	while (big[i] && i + j < len)
	{
		if (big[i] == little[j])
		{
			while ((big[i + j] == little[j])
				&& (big[i + j] && little[j]) && i + j < len)
				j++;
			if (little[j] == '\0')
				return (&(str[i]));
		}
		j = 0;
		i++;
	}
	return (NULL);
}

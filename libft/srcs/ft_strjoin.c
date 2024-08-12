/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:07:34 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/08 14:18:55 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1)
		return (ft_gnldup(s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	ft_gnlcpy(str, s1, lens1);
	ft_gnlcpy(&(str[lens1]), s2, lens2);
	return (str);
}

char	*ft_pipexjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 2));
	if (!str)
		return (NULL);
	ft_gnlcpy(str, s1, lens1);
	ft_gnlcpy(&(str[lens1]), "/", 1);
	ft_gnlcpy(&(str[lens1 + 1]), s2, lens2);
	return (str);
}

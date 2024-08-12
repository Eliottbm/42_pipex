/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:05:06 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/31 17:58:31 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

int	ft_count_word(char const *str, char set)
{
	int	i;
	int	counter;
	int	check;

	i = 0;
	counter = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == 39 && check == 0)
			check = 1;
		else if (str[i] == 39 && check == 1)
			check = 0;
		if (i == 0 && str[i] != set)
			counter++;
		if (str[i] == set && str[i + 1] != '\0'
			&& str[i + 1] != set && check == 0)
			counter++;
		i++;
	}
	return (counter);
}

static void	ft_split_init(int *i, int *j, int *k, int *check)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*check = 0;
}

static int	ft_run_split(char **splitted_str, char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	check;

	ft_split_init(&i, &j, &k, &check);
	while (s[i])
	{
		if (s[i] == 39 && check == 0)
			check = 1;
		else if (s[i] == 39 && check == 1)
			check = 0;
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c) && check == 0)
		{
			splitted_str[k] = malloc(sizeof(char) * (i - j + 2));
			if (!splitted_str[k])
				return (ft_free_all(splitted_str), 1);
			ft_strlcpy(splitted_str[k], &s[j], (i - j + 2));
			k++;
		}
		if (s[i++] == c && s[i] != c && check == 0)
			j = i;
	}
	splitted_str[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_str;
	int		words;

	words = ft_count_word(s, c);
	if (words == 0)
		return (NULL);
	splitted_str = malloc(sizeof(char *) * (words + 1));
	if (!splitted_str)
		return (NULL);
	if (ft_run_split(splitted_str, s, c))
		return (NULL);
	return (splitted_str);
}

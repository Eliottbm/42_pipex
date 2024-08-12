/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:02:04 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/24 15:42:20 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **str, char *buff)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (buff)
		free(buff);
	return (1);
}

static char	*ft_trim_line(char **tab, int fd)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (tab[fd][i] && tab[fd][i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	ft_gnlcpy(tmp, tab[fd], (i + 1));
	if (tab[fd] && tab[fd][i] == '\n' && tab[fd][i + 1])
	{
		tmp2 = ft_gnldup(&(tab[fd][++i]));
		ft_free(&tab[fd], ft_gnldup(""));
		tab[fd] = tmp2;
	}
	else
		ft_free(&tab[fd], ft_gnldup(""));
	return (tmp);
}

static int	ft_read_line(char **tab, int fd)
{
	char	*buff;
	int		rbytes;

	buff = malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
	if (!buff)
		return (1);
	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buff, GNL_BUFFER_SIZE);
		if ((rbytes < 0) || (rbytes == 0 && !tab[fd]))
			return (ft_free(&tab[fd], buff));
		buff[rbytes] = '\0';
		tab[fd] = ft_gnljoin(tab[fd], buff);
		if (!tab[fd])
			return (1);
		if (is_nl(tab[fd]) == 0)
			break ;
	}
	if (buff)
		free(buff);
	return (0);
}

char	*ft_get_next_line(int fd)
{
	static char	*tab[1024];
	char		*str;

	if (fd < 0 || fd > 1024 || GNL_BUFFER_SIZE < 0)
		return (NULL);
	if (ft_read_line(tab, fd))
		return (NULL);
	str = ft_trim_line(tab, fd);
	if (!str)
		return (NULL);
	return (str);
}

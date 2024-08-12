/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:58:57 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/09 14:06:33 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/pipex_bonus.h"

static void	heredoc_gnl(t_pipex *p_data, int *fds)
{
	char	*buff;
	int		cmp_len;

	buff = ft_get_next_line(0);
	while (buff)
	{
		cmp_len = ft_max((ft_strlen(buff) - 1), ft_strlen(p_data->limiter));
		if (ft_strncmp(buff, p_data->limiter, cmp_len) == 0)
		{
			free(buff);
			free_pipex(p_data);
			close(fds[1]);
			exit(0);
		}
		ft_putstr_fd(buff, fds[1]);
		free(buff);
		buff = ft_get_next_line(0);
	}
}

int	run_heredoc(t_pipex *p_data)
{
	pid_t	pid;
	int		fds[2];

	if (pipe(fds) == -1)
		return (perror(NULL), 1);
	pid = fork();
	if (pid == -1)
		return (perror(NULL), 1);
	if (pid == 0)
	{
		close(fds[0]);
		heredoc_gnl(p_data, fds);
		free_pipex(p_data);
		close(fds[1]);
		exit(0);
	}
	if (pid != 0)
	{
		close(fds[1]);
		if (dup2(fds[0], STDIN_FILENO) == -1)
			return (perror(NULL), 1);
		close(fds[0]);
		wait(NULL);
	}
	return (0);
}

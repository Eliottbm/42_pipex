/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:15:11 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/12 14:41:32 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/pipex_bonus.h"

void	free_pipex(t_pipex *p_data)
{
	size_t	i;

	i = 0;
	if (p_data)
	{
		if (p_data->cmds)
		{
			while (p_data->cmds[i])
			{
				free_split(p_data->cmds[i]);
				i++;
			}
			free(p_data->cmds);
		}
		free(p_data);
	}
}

int	noinfile_dup(void)
{
	int	fds[2];

	if (pipe(fds) == -1)
		return (perror(NULL), 1);
	close(fds[1]);
	if (dup2(fds[0], STDIN_FILENO) == -1)
		return (close(fds[0]), perror(NULL), 1);
	close(fds[0]);
	return (0);
}

int	child_islast(t_pipex *p_data)
{
	int	out_fd;

	if (p_data->limiter)
		out_fd = open(p_data->out_fn, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		out_fd = open(p_data->out_fn, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_fd == -1)
		return (perror("outfile"), 1);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		return (close (out_fd), perror(NULL), 1);
	close (out_fd);
	return (0);
}

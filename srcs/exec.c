/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:30:46 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/12 14:20:10 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static int	run_child(t_pipex *p_data, int *fds, int i, int islast)
{
	int	out_fd;

	close(fds[0]);
	if (islast)
	{
		out_fd = open(p_data->out_fn, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (out_fd == -1)
			return (close(fds[1]), perror("outfile"), 1);
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			return (close(fds[1]), close (out_fd), perror(NULL), 1);
		close (out_fd);
	}
	if (islast == 0)
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			return (close(fds[1]), perror(NULL), 1);
	close(fds[1]);
	if (execve(p_data->cmds[i][0], p_data->cmds[i], p_data->env) == -1)
	{
		free_pipex(p_data);
		perror("exec: command not found");
		exit(127);
	}
	return (0);
}

static int	run_parent(pid_t pid, int *fds, int islast, int *exit_status)
{
	pid_t	endpid;
	int		status;

	close(fds[1]);
	if (dup2(fds[0], STDIN_FILENO) == -1)
		return (close(fds[0]), perror(NULL), 1);
	close(fds[0]);
	if (islast)
	{
		while (1 == 1)
		{
			endpid = waitpid(-1, &status, 0);
			if (endpid == pid)
				if (WIFEXITED(status))
					*exit_status = WEXITSTATUS(status);
			if (endpid == -1)
				break ;
		}
	}
	return (0);
}

static int	run_cmd(t_pipex *p_data, int i, int islast, int *exit_status)
{
	pid_t	pid;
	int		fds[2];

	if (pipe(fds) == -1)
		return (perror(NULL), 1);
	pid = fork();
	if (pid == -1)
		return (perror(NULL), 1);
	if (pid == 0)
		if (run_child(p_data, fds, i, islast))
			return (1);
	if (pid != 0)
		if (run_parent(pid, fds, islast, exit_status))
			return (1);
	return (0);
}

int	setup_cmds(t_pipex *p_data, int *exit_status)
{
	int			in_fd;
	int			i;

	i = 0;
	in_fd = open(p_data->in_fn, O_RDONLY);
	if (in_fd == -1)
	{
		perror("infile");
		i = 1;
		if (noinfile_dup())
			return (1);
	}
	else
	{
		if (dup2(in_fd, STDIN_FILENO) == -1)
			return (close (in_fd), perror(NULL), 1);
		close (in_fd);
	}
	while (p_data->cmds[i + 1])
		if (run_cmd(p_data, i++, 0, exit_status))
			return (1);
	if (run_cmd(p_data, i, 1, exit_status))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:59:22 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/12 14:16:56 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/incs/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	*in_fn;
	char	*out_fn;
	char	*limiter;
	char	**env;
	char	***cmds;
}			t_pipex;

/* INITS */
t_pipex	*init_pipex(int ac, char **av, char **env);

/* UTILS */
void	free_pipex(t_pipex *p_data);
int		child_islast(t_pipex *p_data);

/* RUN */
int		setup_cmds(t_pipex *p_data, int *exit_status);
int		noinfile_dup(void);
int		run_heredoc(t_pipex *p_data);

#endif
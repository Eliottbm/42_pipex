/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:58:06 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/09 16:59:19 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*p_data;
	int		exit_status;

	if (ac != 5)
		return (ft_error("wrong args\n"), 1);
	exit_status = 0;
	p_data = init_pipex(ac, av, env);
	if (!p_data)
		return (1);
	if (setup_cmds(p_data, &exit_status))
	{
		if (exit_status == 0)
			exit_status = 1;
		return (free_pipex(p_data), exit_status);
	}
	return (free_pipex(p_data), exit_status);
}

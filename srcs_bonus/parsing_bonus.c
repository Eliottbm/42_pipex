/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:47 by ebengtss          #+#    #+#             */
/*   Updated: 2024/08/13 14:28:11 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/pipex_bonus.h"

static int	flags_trim(char **splitted)
{
	char	*tmpstr;
	int		i;

	i = 0;
	while (splitted[i])
	{
		if (splitted[i][0] == 39
			&& splitted[i][ft_strlen(splitted[i]) - 1] == 39)
		{
			tmpstr = ft_strtrim(splitted[i], "'");
			if (tmpstr[0] == '\0')
				return (free(tmpstr), 1);
			free(splitted[i]);
			splitted[i] = tmpstr;
		}
		i++;
	}
	return (0);
}

static int	cmds_test_paths(char **cmd, char **env_path)
{
	char	*path;
	int		j;

	j = 0;
	while (env_path[j])
	{
		path = ft_pipexjoin(env_path[j], cmd[0]);
		if (!path)
			return (ft_error("error building cmd\n"), 1);
		if (access(path, F_OK) == 0)
		{
			free(cmd[0]);
			cmd[0] = path;
			if (access(path, X_OK) == 0)
				break ;
		}
		free(path);
		j++;
	}
	return (0);
}

static int	cmds_find_paths(t_pipex *p_data, char **cmd)
{
	char	**paths;
	int		j;

	j = 0;
	if (access(cmd[0], F_OK) == 0)
		return (0);
	while (p_data->env && p_data->env[j])
	{
		if (ft_strncmp("PATH=", p_data->env[j], 5) == 0)
		{
			paths = ft_split(&p_data->env[j][5], ':');
			if (!paths)
				return (ft_error("error building cmd\n"), 1);
			if (cmds_test_paths(cmd, paths))
				return (free_split(paths), 1);
			free_split(paths);
		}
		j++;
	}
	return (0);
}

static int	cmds_parse(int ac, char **av, t_pipex *p_data)
{
	int		i;
	int		j;

	i = 0;
	if (p_data->limiter)
		j = 3;
	else
		j = 2;
	p_data->cmds = malloc(sizeof(char *) * ac - j);
	if (!p_data->cmds)
		return (perror(NULL), 1);
	while (i + j < ac - 1)
	{
		p_data->cmds[i] = ft_split(av[i + j], ' ');
		if (!p_data->cmds[i])
			return (ft_error("cmds parsing error\n"), 1);
		if (cmds_find_paths(p_data, p_data->cmds[i]))
			return (ft_error("cmds parsing error\n"), 1);
		if (flags_trim(p_data->cmds[i]))
			return (ft_error("cmds parsing error\n"), 1);
		i++;
	}
	p_data->cmds[i] = NULL;
	return (0);
}

t_pipex	*init_pipex(int ac, char **av, char **env)
{
	t_pipex	*p_data;
	int		cmp_len;

	p_data = malloc(sizeof(t_pipex));
	if (!p_data)
		return (perror(NULL), NULL);
	p_data->cmds = NULL;
	cmp_len = ft_max(8, (ft_strlen(av[1])));
	if (ft_strncmp("here_doc", av[1], cmp_len) == 0)
		p_data->limiter = av[2];
	else
		p_data->limiter = NULL;
	if (p_data->limiter && ac < 6)
		return (free_pipex(p_data), ft_error("wrong args\n"), NULL);
	p_data->in_fn = av[1];
	p_data->out_fn = av[ac - 1];
	if (*env)
		p_data->env = env;
	else
		p_data->env = NULL;
	if (cmds_parse(ac, av, p_data))
		return (free_pipex(p_data), NULL);
	return (p_data);
}

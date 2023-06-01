/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:50:46 by pboonpro          #+#    #+#             */
/*   Updated: 2023/06/01 18:50:01 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_have_path(char **env, int *i)
{
	while (env[*i])
	{
		if (ft_strnstr(env[*i], "PATH=", 5))
			return (1);
		(*i)++;
	}
	return (0);
}

char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	**my_path;
	char	*j_path;
	int		i;

	i = 0;
	if (!check_have_path(env, &i))
		errorh(NULL, 0);
	my_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (my_path[i])
	{
		j_path = ft_strjoin(my_path[i], "/");
		path = ft_strjoin(j_path, cmd);
		free(j_path);
		if (access(path, F_OK | R_OK) == 0)
		{
			my_free(my_path);
			return (path);
		}
		free(path);
		i++;
	}
	my_free(my_path);
	return (0);
}

int	check_is_path(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strnstr(cmd[i], "/", ft_strlen(cmd[i])))
			if (access(cmd[i], F_OK | R_OK) == 0)
				return (1);
		i++;
	}
	return (0);
}

void	exe(char *av, char **env)
{
	char	**cmd;
	char	*path;

	if (ft_strncmp(av, "\0", 1) == 0)
		errorh(NULL, 0);
	cmd = ft_split(av, ' ');
	if (check_is_path(cmd) == 0)
	{
		path = find_path(cmd[0], env);
		if (!path)
			errorh(cmd, 1);
	}
	else
		path = ft_substr(cmd[0], 0, ft_strlen(cmd[0]));
	if (execve(path, cmd, env) != 0)
	{
		free(path);
		errorh(cmd, 1);
	}
}

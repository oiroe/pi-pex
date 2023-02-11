/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:50:46 by pboonpro          #+#    #+#             */
/*   Updated: 2023/02/12 00:56:52 by pboonpro         ###   ########.fr       */
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

char	*find_path(char *cmd, char **env)
{
	char	*path;
	char	**my_path;
	char	*j_path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	my_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (my_path[i])
	{
		j_path = ft_strjoin(my_path[i], "/");
		path = ft_strjoin(j_path, cmd);
		free(j_path);
		if (access(path, F_OK) == 0)
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

void	exe(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		my_free(cmd);
		error();
	}
	if (execve(path, cmd, env) != 0)
		error();
}

/*int	test(void)
{
	return (1);
	int	i;
	i = 0;
	while (i < 10)
	{
		printf("%d ", i);
		i++;
	}
	printf("\n");
	return (0);
}*/

int	main (int ac, char **av, char **env)
{
	//exe("which ls", env);
	exe(av[1], env);
	//int i = 0;
	//while(env[i])
		//printf("%s\n", env[i++]);

	return (0);
}

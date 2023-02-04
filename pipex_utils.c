/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:50:46 by pboonpro          #+#    #+#             */
/*   Updated: 2023/02/04 22:44:16 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe(char *cmd, char **env)
{
	char	*path;
	char	**my_path;
	char	*j_path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	my_path = ft_split(env[i] + 5, ':');
	/*i = 0;
	while (my_path[i])
		printf("%s\n", my_path[i++]);*/
	while (my_path[i])
	{
		j_path = ft_strjoin(my_path[i], "/");
		path = ft_strjoin(j_path, cmd);
		free(j_path);
if (access)
		i++;
	}
}

int	main (int argc, char **argv, char **env)
{
	exe(argv, env);
	int i = 0;
	/*while(env[i])
		printf("%s\n", env[i++]);*/

	return (0);
}

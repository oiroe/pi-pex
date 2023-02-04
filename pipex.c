/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:06:38 by pboonpro          #+#    #+#             */
/*   Updated: 2023/02/04 22:34:44 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(int *pfd, char **env, char **argv)
{
	int		fd;

	fd = open(argv[4], O_RDWR | O_CREAT);
	dup2(pfd[1], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pfd[0]);
	close(fd);
	exe(argv[3], env);
}

void	child(int *pfd, char **env, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDWR | O_CREAT);
	dup2(fd, STDIN_FILENO);
	dup2(pfd[0], STDOUT_FILENO);
	close(pfd[1]);
	close(fd);
	exe(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pfd[2];
	pid_t	pid;
	int		*status;

	if (argc == 5)
	{
		if (pipe(pfd) == -1)
			return (0);
		pid = fork();
		if (pid < 0)
			perror("Error");
		else if (pid == 0)
			child(pfd, env, argv);
		waitpid(pid, &status, 0);
		parent(pfd, env, argv);
	}
	else
		perror("invalid input");
	return (0);
}

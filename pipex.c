/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:06:38 by pboonpro          #+#    #+#             */
/*   Updated: 2023/03/21 01:00:14 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(int *pfd, char **env, char **argv)
{
	int		fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("meaw");
		exit(EXIT_FAILURE);
	}
	dup2(pfd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pfd[1]);
	close(fd);
	exe(argv[3], env);
}

void	child(int *pfd, char **env, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDWR, 0777);
	if (fd == -1)
	{
		perror("meaw");
		exit(EXIT_FAILURE);
	}
	dup2(pfd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pfd[0]);
	close(fd);
	exe(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pfd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pfd) == -1)
			perror("Error");
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
			child(pfd, env, argv);
		waitpid(pid, NULL, 0);
		parent(pfd, env, argv);
	}
	else
		perror("invalid input");
	return (0);
}

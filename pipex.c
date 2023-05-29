/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:06:38 by pboonpro          #+#    #+#             */
/*   Updated: 2023/05/29 21:32:00 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(int *pfd, char **env, char **argv)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("zsh");
		exit(EXIT_FAILURE);
	}
	dup2(pfd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pfd[1]);
	close(pfd[0]);
	close(fd);
	exe(argv[3], env);
}

void	child(int *pfd, char **env, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDWR, 0777);
	if (fd == -1)
	{
		perror("zsh");
		exit(EXIT_FAILURE);
	}
	dup2(pfd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	close(fd);
	exe(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(pfd) == -1)
			perror("Error");
		pid1 = fork();
		if (pid1 == 0)
			child(pfd, env, argv);
		pid2 = fork();
		if (pid2 == 0)
			parent(pfd, env, argv);
		close(pfd[0]);
		close(pfd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		perror("invalid input");
	return (0);
}

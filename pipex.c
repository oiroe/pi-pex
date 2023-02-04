/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:06:38 by pboonpro          #+#    #+#             */
/*   Updated: 2023/02/04 13:50:01 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **env)
{
	pid_t	fd[2];
	pid_t	pid;
	int		*status;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		child();
	else
		perror("Error");
	waitpid(pid, &status, 0);
	parent();
	return (0);
}

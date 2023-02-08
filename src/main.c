/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:43:48 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/08 16:52:43 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

void	parent_closing(t_pipe *main, int *pipes, int argc)
{
	if (main->commands_count == argc - 3)
		close(pipes[0]);
	close(pipes[1]);
}

void	clean_error(int error, char *argument, char *message)
{
	write(STDERR_FILENO, "pipex: ", 7);
	if (error != -1)
		perror(argument);
	else
	{
		write(STDERR_FILENO, argument, ft_strlen(argument));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, message, ft_strlen(message));
	}
	exit(error);
}

void	child_birth(t_pipe *main, char *argv[], int argc, int *pipes)
{	
	pid_t	id;

	id = 1;
	while (main->commands_count < argc - 3 && id != 0)
	{	
		main->read_fd = pipes[0];
		if (pipe(pipes) == -1)
			clean_error(errno, "pipe", NULL);
		id = fork();
		if (id == -1)
			clean_error(errno, "fork", NULL);
		if (id != 0)
			parent_closing(main, pipes, argc);
		main->commands_count++;
	}
	if (id == 0)
	{
		argv++;
		commands(main, argv[main->commands_count]);
		child_execute(main, argv, argc, pipes);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	main;
	int32_t	status;
	int		pipes[2];

	main.commands_count = 0;
	main.envp = envp;
	if (argc < 4)
		clean_error(-1, "arguments", "need at least [4]\n");
	child_birth(&main, argv, argc, pipes);
	while (wait(NULL) != -1)
		;
	exit(WIFEXITED(status));
}

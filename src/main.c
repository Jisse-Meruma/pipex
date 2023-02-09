/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:43:48 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/09 18:10:11 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

void	parent_closing(t_pipe *main, int *pipes)
{
	close(main->read_fd);
	close(pipes[1]);
}

void	clean_error(int error, char *argument, char *message)
{
	errno = error;
	write(STDERR_FILENO, "pipex: ", 7);
	if (error != -1 && error != 127)
		perror(argument);
	else
	{
		write(STDERR_FILENO, argument, ft_strlen(argument));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, message, ft_strlen(message));
	}
	exit(error);
}

void	child_process(t_pipe *main, char *argv[], int argc, int *pipes)
{
	argv++;
	if (main->commands_count == 1 && main->here_doc == 0)
	{
		main->read_fd = open_read_file(argv);
	}
	else if (main->commands_count == 2 && main->here_doc == 1)
	{
		main->read_fd = here_doc(argv);
	}
	commands(main, argv[main->commands_count]);
	child_execute(main, argv, argc, pipes);
}

int	child_birth(t_pipe *main, char *argv[], int argc, int *pipes)
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
			parent_closing(main, pipes);
		main->commands_count++;
	}
	if (id == 0)
	{
		child_process(main, argv, argc, pipes);
	}
	close(pipes[0]);
	return (id);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	main;
	int		id;
	int32_t	status;
	int		pipes[2];

	main.commands_count = 0;
	main.here_doc = 0;
	main.envp = envp;
	if (argc < 5)
		clean_error(-1, "arguments", "need at least [4]\n");
	if (!ft_strncmp(argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
	{
		main.commands_count = 1;
		main.here_doc = 1;
	}
	id = child_birth(&main, argv, argc, pipes);
	waitpid(id, &status, 0);
	while (wait(NULL) != -1)
		;
	if (!WIFEXITED(status))
		exit(EXIT_FAILURE);
	exit(WEXITSTATUS(status));
}

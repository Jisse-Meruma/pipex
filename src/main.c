/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:43:48 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/06 17:22:28 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_error(void)
{
	printf("Error\n");
	exit(-1);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	id;
	t_pipe	main;
	int		pipes[2];
	// 0 = read //
	// 1 = write //
	int		fd;
	int		counter;

	id = 1;
	counter = 0;
	main.commands_count = 0;
	if (argc < 4)
		clean_error();
	while (counter < argc - 3 && id != 0)
	{	
		main.read_fd = pipes[0];
		if (id != 0)
		{
			pipe(pipes);
			printf("pipe =%d | main =[%d]\n", pipes[0], pipes[1]);
			id = fork();
		}
		main.commands_count++;
		counter++;
	}
	if (id != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			clean_error();
		
	}
	if (id == 0)
	{
		argv++;
		main.envp = envp;	
		commands(&main, argv[main.commands_count]);
		execute(&main, argv, argc, pipes);
	}
	// pipe = malloc(1 * sizeof(t_pipe));
	// if (!pipe)
	// 	clean_error();
	// pipe->envp = envp;
	// pipe->commands_count = argc - 3;
	// pipe->commands = malloc(pipe->commands_count * sizeof(char *));
	// if (!pipe->commands)
	// 	clean_error();
	// pipe->commands[pipe->commands_count] = NULL;
}

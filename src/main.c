/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:43:48 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/27 16:39:56 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_error(void)
{
	ft_printf("Error\n");
	exit(-1);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	id;
	int		pipes[2]; 
	// 0 = read //
	// 1 = write //
	int		fd;
	int		counter;
	int 	i;
	
	id = 1;
	counter = 0;
	i = 1;
	
	if (argc < 4)
		clean_error();
	
	while (counter < argc - 3 && id != 0)
	{
		pipe(pipes);
		if (id != 0)
			id = fork();
		i++;
		counter++;
	}
	if (id != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			clean_error();
		
	}
	if (id == 0)
		commands(envp, argv[i]);
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
kaas

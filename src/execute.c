/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:42:36 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/06 17:28:05 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// read = 0;
// write = 1;

void	execute_pipe_command(t_pipe *main, int *pipes)
{
	if (dup2(main->read_fd, STDIN_FILENO) == -1)
		clean_error();
	close(main->read_fd);
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		clean_error();
	close(pipes[1]);
	execve(main->command_path, main->command_arg, main->envp);
}
	
int	execute(t_pipe *main, char *argv[], int argc, int *pipes)
{
	int fd;

	if (main->commands_count == 1)
	{
		close(pipes[0]);
		fd = open_read_file(argv);
		if (dup2(fd, STDIN_FILENO) == -1)
			clean_error();
		close(fd);
		if (dup2(pipes[1], STDOUT_FILENO) == -1)
			clean_error();
		close(pipes[1]);
		execve(main->command_path, main->command_arg, main->envp);
	}
	if (main->commands_count == argc - 3)
	{
		close(pipes[1]);
		fd = open_write_file(argc, argv);
		if (dup2(main->read_fd, STDIN_FILENO) == -1)
			clean_error();
		close(main->read_fd);
		if (dup2(fd, STDOUT_FILENO) == -1)
			clean_error();
		close(fd);
		execve(main->command_path, main->command_arg, main->envp);
	}
	else
		execute_pipe_command(main, pipes);
	return (0);
}	
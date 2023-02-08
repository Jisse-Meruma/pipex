/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:42:36 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/08 17:34:11 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdin(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		clean_error(errno, "dup2", NULL);
	close(fd);
}

void	redirect_stdout(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
		clean_error(errno, "dup2", NULL);
	close(fd);
}

void	execute_pipe_command(t_pipe *main, int *pipes)
{
	close(pipes[0]);
	redirect_stdin(main->read_fd);
	redirect_stdout(pipes[1]);
	execve(main->command_path, main->command_arg, main->envp);
	clean_error(errno, "execve", NULL);
}

void	child_execute(t_pipe *main, char *argv[], int argc, int *pipes)
{
	int	fd;

	if (main->commands_count == 1)
	{
		close(pipes[0]);
		redirect_stdin(main->read_fd);
		redirect_stdout(pipes[1]);
		execve(main->command_path, main->command_arg, main->envp);
		clean_error(errno, "execve", NULL);
	}
	if (main->commands_count == argc - 3)
	{
		close(pipes[1]);
		close(pipes[0]);
		fd = open_write_file(argc, argv);
		redirect_stdin(main->read_fd);
		redirect_stdout(fd);
		execve(main->command_path, main->command_arg, main->envp);
		clean_error(errno, "execve", NULL);
	}
	execute_pipe_command(main, pipes);
}

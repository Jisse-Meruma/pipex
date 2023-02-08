/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:44:35 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/08 17:31:07 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/errno.h>

typedef struct s_pipe
{
	char	**envp;
	char	*command_path;
	char	**command_arg;
	int		commands_count;
	int		read_fd;
	int		write_fd;
}	t_pipe;

void	commands(t_pipe *main, char *argument);
void	clean_error(int error, char *argument, char *message);

// valid_file
int		open_read_file(char *argv[]);
int		open_write_file(int argc, char *argv[]);

// execute
void	child_execute(t_pipe *main, char *argv[], int argc, int *pipes);

#endif

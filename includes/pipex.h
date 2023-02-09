/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:44:35 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/09 13:57:46 by jmeruma          ###   ########.fr       */
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
	int		here_doc;
	int		read_fd;
	int		write_fd;
}	t_pipe;

//	command
void	commands(t_pipe *main, char *argument);

//	main
void	clean_error(int error, char *argument, char *message);

//	valid_file
int		open_read_file(char *argv[]);
int		open_write_file(t_pipe *main, int argc, char *argv[]);
int		open_here_doc(void);

//	execute
void	child_execute(t_pipe *main, char *argv[], int argc, int *pipes);

//	here_doc
int		here_doc(char *argv[]);

#endif

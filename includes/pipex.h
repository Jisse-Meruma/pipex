/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:44:35 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/06 16:34:08 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pipe
{
	char	**envp;
	char	*command_path;
	char	**command_arg;
	int		commands_count;
	int		read_fd;
}	t_pipe;

void	clean_error(void);
void	commands(t_pipe *main, char *argument);

// valid_file
int	open_read_file(char *argv[]);
int	open_write_file(int argc, char *argv[]);

// execute
int execute(t_pipe *main, char *argv[], int argc, int *pipes);

#endif

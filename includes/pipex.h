/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:44:35 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/23 12:57:31 by jmeruma          ###   ########.fr       */
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
	char	**commands;
	int		commands_count;
}	t_pipe;

void	clean_error(void);
void	commands(t_pipe *pipe, char *argv[]);

#endif

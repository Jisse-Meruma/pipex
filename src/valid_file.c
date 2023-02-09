/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:52:57 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/09 13:45:49 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_read_file(char *argv[])
{
	int	fd;

	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
		clean_error(errno, argv[0], NULL);
	return (fd);
}

int	open_write_file(t_pipe *main, int argc, char *argv[])
{
	int	fd;

	if (main->here_doc == 0)
		fd = open(argv[argc - 2], O_WRONLY | O_TRUNC | O_CREAT, 0000644);
	else
		fd = open(argv[argc - 2], O_WRONLY | O_APPEND | O_CREAT, 0000644);
	if (fd == -1)
		clean_error(errno, argv[argc - 2], NULL);
	return (fd);
}

int	open_here_doc(void)
{
	int	fd;

	fd = open("here_doc", O_WRONLY | O_RDONLY | O_CREAT, 0000644);
	if (fd == -1)
		clean_error(errno, "here_doc", NULL);
	return (fd);
}

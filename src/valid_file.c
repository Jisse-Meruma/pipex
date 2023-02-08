/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:52:57 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/08 17:11:56 by jmeruma          ###   ########.fr       */
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

int	open_write_file(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[argc - 2], O_WRONLY | O_TRUNC | O_CREAT, 000644);
	if (fd == -1)
		clean_error(errno, argv[argc - 2], NULL);
	return (fd);
}

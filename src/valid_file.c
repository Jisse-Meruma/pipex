/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:52:57 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/06 13:18:56 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_read_file(char *argv[])
{
	int	fd;

	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
		clean_error();
	return (fd);
}

int	open_write_file(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[argc - 2], O_WRONLY);
	if (fd == -1)
		clean_error();
	return (fd);
}

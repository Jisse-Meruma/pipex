/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:52:57 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 23:00:08 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(int argc, char *argv[])
{
	int	fd_1;
	int	fd_2;

	fd_1 = open(argv[1], O_RDONLY);
	fd_2 = open(argv[argc - 1], O_WRONLY);
	if (fd_1 == -1 || fd_2 == - 1)
		clean_error();
}
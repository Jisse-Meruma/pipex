/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:05:11 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/09 16:23:33 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc_readonly(int fd)
{
	close(fd);
	fd = open("/tmp/here_doc", O_RDONLY);
	if (fd == -1)
		clean_error(errno, "here_doc", NULL);
	if (unlink("/tmp/here_doc") == -1)
		clean_error(errno, "here_doc", NULL);
	return (fd);
}

int	here_doc(char *argv[])
{
	int		fd;
	char	*line;

	fd = open_here_doc();
	write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, argv[1], ft_strlen(argv[1])) && \
			ft_strlen(line) - 1 == ft_strlen(argv[1]))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(STDOUT_FILENO, "> ", 2);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	fd = here_doc_readonly(fd);
	return (fd);
}

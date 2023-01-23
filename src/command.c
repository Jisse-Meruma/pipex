/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:22 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/23 16:02:17 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*argument_split(char *argument)
{
	int i;
	char *ptr;

	i = 0;
	while (argument[i] && argument[i] != ' ')
		i++;
	ptr = malloc(i + 1 * sizeof(char));
	ptr[i] = '\0';
	ft_strlcpy(ptr, argument, i + 1);
	return (ptr);
}

void	valid_command(t_pipe *pipe, char *path, char *argv[])
{
	int		i;
	int		commands;
	char	*bin_command;
	char	**paths;
	char	*command;
	
	commands = 0;
	paths = ft_split(path, ':');
	while (commands < pipe->commands_count)
	{
		i = 0;
		while (1)
		{
			command = ft_strjoin(paths[i], "/");
			bin_command = argument_split(argv[commands + 2]);
			command = ft_strjoin(command, bin_command);
			free(bin_command);
			if (access(command, F_OK | X_OK) == 0)
			{
				ft_printf("%s\n", command);
				ft_printf("%s\n", argv[commands + 2]);
				pipe->commands[commands] = command;
				break;
			}
			free(command);
			i++;
			if (paths[i] == '\0')
				clean_error();
		}
		commands++;
	}
	ft_2dfree(paths);
}

void	commands(t_pipe *pipe, char *argv[])
{
	int i;
	
	i = ft_2d_arrlen(pipe->envp);
	i--;
	while (i > 0)
	{
		if(!ft_strncmp(pipe->envp[i], "PATH=", 5))
			valid_command(pipe, pipe->envp[i] + 5, argv);
		i--;
	}
}

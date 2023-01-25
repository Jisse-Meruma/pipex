/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:22 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/25 14:14:52 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**valid_command(char *path, char *argument, char *command)
{
	int		i;
	int		commands;
	char	**arg_argv;
	char	**paths;

	i = 0;
	commands = 0;
	arg_argv = ft_split(argument, ' ');
	paths = ft_split(path, ':');
	while (1)
	{
		command = ft_strjoin(paths[i], "/");
		command = ft_strjoin(command, arg_argv[0]);
		if (access(command, F_OK | X_OK) == 0)
			return (arg_argv);
		free(command);
		i++;
		if (paths[i] == '\0')
			clean_error();
	}
	ft_2dfree(paths);
}

void	commands(char *envp[], char *argument)
{
	char	**arg_argv;
	char	*command;
	int i;
	
	command = NULL;
	i = ft_2d_arrlen(envp);
	i--;
	while (i > 0)
	{
		if(!ft_strncmp(envp[i], "PATH=", 5))
		{
			arg_argv = valid_command(envp[i] + 5, argument, command);
			break;
		}
		i--;
	}
}

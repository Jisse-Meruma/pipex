/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:22 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/26 12:51:50 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**valid_command(char *path, char *argument, char *command)
{
	int		i;
	char	**arg_argv;
	char	**paths;

	i = 0;
	arg_argv = ft_split(argument, ' ');
	paths = ft_split(path, ':');
	while (1)
	{
		command = ft_strjoin(paths[i], "/");
		command = ft_strjoin_free(command, arg_argv[0]);
		//ft_printf("1=%s\n", command);
		printf("%s\n", command);
		if (access(command, F_OK | X_OK) == 0)
		{
			printf("COMMAND = %s\n", command);
			ft_2dfree(paths);
			free(command);
			return (arg_argv);
		}
		free(command);
		i++;
		if (paths[i] == '\0')
		{
			ft_2dfree(paths);
			ft_2dfree(arg_argv);
			clean_error();
		}
	}
	
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

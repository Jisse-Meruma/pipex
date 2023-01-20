/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:22 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 23:58:55 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	valid_command(char *path, char *argv[])
{
	int		i;
	char	**paths;
	char	*command;
	
	i = 0;
	paths = ft_split(path, ':');
	while (paths[i] != '\0')
	{
		command = ft_strjoin(paths[i], "/");
		command = ft_strjoin(command, argv[2]);
		if (access(command, F_OK | X_OK) == 0)
		{
			printf("%s\n", command);
			break;
		}
		i++;
		if (paths[i] == '\0')
			clean_error();
	}
	while (paths[i] != '\0')
	{
		command = ft_strjoin(paths[i], "/");
		command = ft_strjoin(command, argv[3]);
		if (access(command, F_OK | X_OK) == 0)
		{
			printf("%s\n", command);
			break;
		}
		i++;
		if (paths[i] == '\0')
			clean_error();
	}
	
}

void	commands(char *envp[], char *argv[])
{
	int i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	i--;
	while (i > 0)
	{
		if(!ft_strncmp(envp[i], "PATH=", 5))
			valid_command(envp[i], argv);
		i--;
	}
}
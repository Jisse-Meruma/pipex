/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:22 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/06 17:13:25 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	valid_command(t_pipe *main, char *path, char *argument)
{
	int		i;
	char	*command;
	char	**paths;

	i = 0;
	main->command_arg = ft_split(argument, ' ');
	paths = ft_split(path, ':');
	while (1)
	{
		command = ft_strjoin(paths[i], "/");
		command = ft_strjoin_free(command, main->command_arg[0]);
		if (access(command, F_OK | X_OK) == 0)
		{
			ft_2dfree(paths);
			main->command_path = command;
			return ;
		}
		free(command);
		i++;
		if (paths[i] == '\0')
		{
			ft_2dfree(paths);
			ft_2dfree(main->command_arg);
			clean_error();
		}
	}
	
}

void	commands(t_pipe *main, char *argument)
{
	int i;

	i = ft_2d_arrlen(main->envp);
	i--;
	while (i > 0)
	{
		if(!ft_strncmp(main->envp[i], "PATH=", 5))
		{
			valid_command(main, main->envp[i] + 5, argument);
			break;
		}
		i--;
	}
}

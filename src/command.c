/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:22 by jmeruma           #+#    #+#             */
/*   Updated: 2023/02/09 14:43:07 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_free(t_pipe *main, char **paths, char *argument)
{
	if (main->command_path)
	{
		free(main->command_path);
	}
	if (paths)
	{
		ft_2dfree(paths);
	}
	if (main->command_arg)
	{
		free(main->command_arg);
	}
	clean_error(errno, argument, NULL);
}

void	command_path_creation(t_pipe *main, char **paths, char *argument, int i)
{
	main->command_path = ft_strjoin(paths[i], "/");
	if (!main->command_path)
	{
		error_free(main, paths, argument);
	}
	main->command_path = ft_strjoin_free(main->command_path, \
	main->command_arg[0]);
	if (!main->command_path)
	{
		error_free(main, paths, argument);
	}
}

void	valid_command(t_pipe *main, char *path, char *argument)
{
	int		i;
	char	**paths;

	i = 0;
	main->command_arg = ft_split(argument, ' ');
	if (!main->command_arg)
		clean_error(errno, argument, NULL);
	paths = ft_split(path, ':');
	if (!paths)
		error_free(main, paths, argument);
	while (1)
	{
		command_path_creation(main, paths, argument, i);
		if (access(main->command_path, F_OK | X_OK) == 0)
			return (ft_2dfree(paths));
		free(main->command_path);
		i++;
		if (paths[i] == '\0')
		{
			ft_2dfree(paths);
			ft_2dfree(main->command_arg);
			clean_error(127, argument, "command not found\n");
		}
	}
}

void	commands(t_pipe *main, char *argument)
{
	int	i;

	i = ft_2d_arrlen(main->envp);
	i--;
	while (i > 0)
	{
		if (!ft_strncmp(main->envp[i], "PATH=", 5))
		{
			valid_command(main, main->envp[i] + 5, argument);
			break ;
		}
		i--;
	}
	if (i == 0)
		clean_error(-1, "path", "variable not found in envp\n");
}

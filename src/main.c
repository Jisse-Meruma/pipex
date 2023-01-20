/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:43:48 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/20 23:00:16 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_error(void)
{
	ft_printf("Error\n");
	exit(-1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int i;
	int ptr;
	char **super_ptr;
	
	if (argc < 4)
		clean_error();
	commands(envp, argv);
}
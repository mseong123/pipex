/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:23:47 by melee             #+#    #+#             */
/*   Updated: 2023/06/05 19:21:02 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_splits(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_ptr(t_pipex *ptr)
{
	int	i;

	if (ptr->bin_path)
		free_splits(ptr->bin_path);
	if (ptr->cmd_path)
		free_splits(ptr->cmd_path);
	if (ptr->pipefd)
	{
		i = 0;
		while (i < ptr->cmd_count + 1)
			free(ptr->pipefd[i++]);
		free(ptr->pipefd);
	}
	if (ptr->pid)
		free(ptr->pid);
	free(ptr);
}

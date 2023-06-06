/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:41 by melee             #+#    #+#             */
/*   Updated: 2023/06/06 11:42:32 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_bin_path(t_pipex *ptr, char **envp)
{
	char	*key;

	while (*envp)
	{
		key = ft_strnstr(*envp, "PATH=", ft_strlen(*envp));
		if (key)
			break ;
		envp++;
	}
	key = key + 5;
	ptr->bin_path = ft_split(key, ':');
	return (ptr->bin_path);
}

char	*append_slash(char *path, char *input)
{
	char	*res;
	char	*temp;

	temp = ft_strjoin(path, "/");
	res = ft_strjoin(temp, input);
	free(temp);
	return (res);
}

int	check_cmd_null(t_pipex *ptr, char **argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < ptr->cmd_count)
	{
		if (ptr->cmd_path[i] == NULL)
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putstr_fd(argv[i + ptr->cmd_pos_start], 2);
			ft_putchar_fd('\n', 2);
			error = 1;
		}
		i++;
	}
	if (error == 1)
	{
		i = 0;
		while (i < ptr->cmd_count)
			free(ptr->cmd_path[i++]);
		free(ptr->cmd_path);
	}
	return (error);
}

char	**check_cmd(t_pipex *ptr, char **argv)
{
	char	**cmd_input;
	int		i;
	int		j;

	i = 0;
	while (i < ptr->cmd_count)
	{
		j = 0;
		cmd_input = ft_split(argv[i + (ptr->cmd_pos_start)], ' ');
		while (ptr->bin_path[j++])
		{
			ptr->cmd_path[i] = append_slash(ptr->bin_path[j], cmd_input[0]);
			if (access(ptr->cmd_path[i], F_OK | X_OK) == 0)
				break ;
			free(ptr->cmd_path[i]);
			ptr->cmd_path[i] = NULL;
		}
		free_splits(cmd_input);
		i++;
	}
	if (check_cmd_null(ptr, argv))
		return (NULL);
	ptr->cmd_path[i] = NULL;
	return (ptr->cmd_path);
}

int	**init_pipefd(t_pipex *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->cmd_count + 1)
	{
		ptr->pipefd[i] = malloc(sizeof(int) * 2);
		if (!ptr->pipefd[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < ptr->cmd_count + 1)
	{
		if (pipe(ptr->pipefd[i]) == -1)
		{
			perror("pipex");
			return (NULL);
		}
		i++;
	}
	return (ptr->pipefd);
}

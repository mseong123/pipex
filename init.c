/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:21:11 by melee             #+#    #+#             */
/*   Updated: 2023/06/06 11:41:58 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_to_null(t_pipex *ptr)
{
	ptr->cmd_count = 0;
	ptr->cmd_pos_start = 0;
	ptr->file1_fd = -1;
	ptr->file2_fd = -1;
	ptr->bin_path = NULL;
	ptr->cmd_path = NULL;
	ptr->pipefd = NULL;
	ptr->pid = NULL;
}

static t_pipex	*init_sub(t_pipex *ptr, char **argv, char **envp)
{
	ptr->bin_path = get_bin_path(ptr, envp);
	if (!ptr->bin_path)
		return (NULL);
	ptr->cmd_path = malloc((ptr->cmd_count + 1) * sizeof(char *));
	if (!ptr->cmd_path)
		return (NULL);
	ptr->cmd_path = check_cmd(ptr, argv);
	if (!ptr->cmd_path)
		return (NULL);
	ptr->pipefd = malloc((ptr->cmd_count + 1) * sizeof(int *));
	if (!ptr->pipefd)
		return (NULL);
	ptr->pipefd = init_pipefd(ptr);
	if (!ptr->pipefd)
		return (NULL);
	ptr->pid = malloc((ptr->cmd_count) * sizeof(int));
	if (!ptr->pid)
		return (NULL);
	return (ptr);
}

int	file_init_heredoc(t_pipex *ptr, int argc, char **argv)
{
	ptr->file2_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0666);
	if (ptr->file2_fd == -1)
	{
		perror("pipex");
		return (1);
	}
	return (0);
}

int	file_init(t_pipex *ptr, int argc, char **argv)
{
	int	error;

	error = 0;
	ptr->file1_fd = open(argv[1], O_RDONLY);
	if (ptr->file1_fd == -1)
	{
		perror("pipex");
		error = 1;
	}
	ptr->file2_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (ptr->file2_fd == -1)
	{
		perror("pipex");
		error = 1;
	}
	return (error);
}

t_pipex	*init(t_pipex *ptr, int argc, char **argv, char **envp)
{
	t_pipex	*temp;
	int		error;

	error = 0;
	init_to_null(ptr);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		ptr->cmd_count = argc - 4;
		ptr->cmd_pos_start = 3;
		error = file_init_heredoc(ptr, argc, argv);
	}
	else
	{
		ptr->cmd_count = argc - 3;
		ptr->cmd_pos_start = 2;
		error = file_init(ptr, argc, argv);
	}
	temp = init_sub(ptr, argv, envp);
	if (!temp || error)
	{
		free_ptr(ptr);
		return (NULL);
	}
	return (ptr);
}

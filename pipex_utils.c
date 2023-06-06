/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:26:33 by melee             #+#    #+#             */
/*   Updated: 2023/06/06 10:53:36 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_pipefd(t_pipex *ptr, int parent)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < ptr->cmd_count)
	{
		if (close(ptr->pipefd[i][0]) == -1)
			error = 1;
		if (close(ptr->pipefd[i][1]) == -1)
			error = 1;
		i++;
	}
	if (close(ptr->pipefd[i][1]) == -1)
		error = 1;
	if (!parent)
	{
		if (close(ptr->pipefd[i][0]) == -1)
			error = 1;
	}	
	if (error)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}

void	read_into_first_pipe(t_pipex *ptr)
{
	char	*line;

	line = get_next_line(ptr->file1_fd);
	while (line)
	{
		write(ptr->pipefd[0][1], line, ft_strlen(line));
		free(line);
		line = get_next_line(ptr->file1_fd);
	}
	free(line);
}

void	read_from_last_pipe(t_pipex *ptr)
{
	char	*line;

	line = get_next_line(ptr->pipefd[ptr->cmd_count][0]);
	while (line)
	{
		write(ptr->file2_fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(ptr->pipefd[ptr->cmd_count][0]);
	}
	free(line);
}

void	here_doc_into_pipe(t_pipex *ptr, char **argv)
{
	char	*line;
	char	*delimiter;

	line = get_next_line(STDIN_FILENO);
	delimiter = ft_strjoin(argv[2], "\n");
	while (ft_strcmp(line, delimiter))
	{
		write(ptr->pipefd[0][1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	free(delimiter);
}

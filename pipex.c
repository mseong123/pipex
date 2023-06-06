/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:04:46 by melee             #+#    #+#             */
/*   Updated: 2023/06/06 11:37:19 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *ptr, char **argv, int i, char **envp)
{
	char	**cmd_input;

	dup2(ptr -> pipefd[i][0], STDIN_FILENO);
	dup2(ptr -> pipefd[i + 1][1], STDOUT_FILENO);
	close_all_pipefd(ptr, 0);
	cmd_input = ft_split(argv[i + ptr->cmd_pos_start], ' ');
	if (execve(ptr->cmd_path[i], cmd_input, envp) == -1)
	{
		perror("pipex");
		free(cmd_input);
		free_ptr(ptr);
		exit(EXIT_FAILURE);
	}
}

void	pipex(t_pipex *ptr, char **argv, char **envp)
{	
	int		i;

	i = 0;
	while (i < ptr->cmd_count)
	{
		ptr->pid[i] = fork();
		if (ptr->pid[i] == -1)
		{
			perror("pipex");
			free_ptr(ptr);
			exit(EXIT_FAILURE);
		}
		else if (ptr->pid[i] == 0)
			child_process(ptr, argv, i, envp);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*ptr;

	if (argc >= 5)
	{
		ptr = malloc(sizeof(t_pipex));
		if (!ptr)
			return (EXIT_FAILURE);
		ptr = init(ptr, argc, argv, envp);
		if (!ptr)
			return (EXIT_FAILURE);
		if (!ft_strcmp(argv[1], "here_doc"))
			here_doc_into_pipe(ptr, argv);
		else
			read_into_first_pipe(ptr);
		pipex(ptr, argv, envp);
		close_all_pipefd(ptr, 1);
		if (waitpid(ptr->pid[(ptr->cmd_count) - 1], NULL, 0) == -1)
		{
			perror("pipex");
			return (EXIT_FAILURE);
		}
		read_from_last_pipe(ptr);
		free_ptr(ptr);
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:34 by melee             #+#    #+#             */
/*   Updated: 2023/06/05 16:57:52 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int cmd_count;
	int	file1_fd;
	int	file2_fd;
	char **bin_path;
	char **cmd_path;
	int	**pipefd;
	int	*pid;
}	t_pipex;

t_pipex	*init(t_pipex *ptr, int argc, char **argv, char **envp);
void	free_splits(char **str);
void	free_ptr(t_pipex *ptr);
char	**get_bin_path(t_pipex *ptr, char **envp);
char	**check_cmd(t_pipex *ptr, char **argv);
int		**init_pipefd(t_pipex *ptr);
void	close_all_pipefd(t_pipex *ptr, int parent);
void	read_into_first_pipe(t_pipex *ptr);
void	read_from_last_pipe(t_pipex *ptr);

#endif

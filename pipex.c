/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:04:46 by melee             #+#    #+#             */
/*   Updated: 2023/06/02 14:17:45 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char **environ;
extern int	errno;

/*memory need to be free
 * bin_path
 * */

char **get_bin_path(void)
{
	char *key;

	while (*environ)
	{
		key = ft_strnstr(*environ, "PATH=", ft_strlen(*environ));
		if (key)
			break;
		environ++;
	}
	key = key + 5;
	return (ft_split(key, ':'));
}

void free_splits(char **str)
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

char *append_slash(char *path, char *input)
{
	char *res;
	char *temp;

	temp = ft_strjoin(path, "/");
	res = ft_strjoin(temp, input);
	free(temp);
	return (res);
}

void free_and_null(char **prog_path, int i)
{
	free(prog_path[i - 2]);
	prog_path[i-2] = NULL;
}

char **check_null(char **prog_path, int i)
{
	if (prog_path[i - 2] == NULL)
	{
		perror("pipex");
		return (NULL);
	}
	else
		return (prog_path);
}

char **check_prog(char **prog_path, int argc, char **argv)
{
	char **bin_path;
	char **prog_input;
	int i;
	int j;

	i = 2;
	bin_path = get_bin_path();
	while (i < argc - 1)
	{
		j = 0;
		prog_input = ft_split(argv[i], ' ');
		while (bin_path[j++])
		{
			prog_path[i - 2] = append_slash(bin_path[j], prog_input[0]);
			if (access(prog_path[i - 2], X_OK | F_OK) == 0)
				break;
			free_and_null(prog_path, i);
		}
		if (!check_null(prog_path, i))
			return (NULL);
		free_splits(prog_input);
		i++;
	}
	prog_path[i] = NULL;
	return(prog_path);
}

//check_file checks for first file arg and return fd
//check_prog checks for all cmd arguments and returns a 2d array of valid program paths.

int	check_file(char **argv)
{
	int file1_fd;

	file1_fd = open(argv[1], O_RDONLY);
	if (file1_fd == -1)
	{
		perror("pipex");
		return (-1);
	}
	return (file1_fd);
}


int main(int argc, char **argv)
{
	
	int	file1_fd;
	char **prog_path;
	int i;
	//int pipefd[argc-2][2];

	i = 0;
	if (argc >= 5)
	{
		file1_fd = check_file(argv);
		if (file1_fd == -1)
	   		return (0);
		prog_path = malloc((argc - 2)*sizeof(char *));
		prog_path = check_prog(prog_path, argc, argv);
		if (prog_path == NULL)
			return (0);
		while(*prog_path)
		{
			printf("%s\n",*prog_path);
			prog_path++;	
		}
		

	}	
/*
	if (argc>1)
	{
		while (j < 2)
		{
			pipe(pipefd[j]);
			j++;
		}
		pid[0] = fork();
		if (pid[0] == 0)
		{
			printf("ls process\n");
			dup2(pipefd[0][1], 1);
			close(pipefd[0][1]);
			close(pipefd[0][0]);
			close(pipefd[1][0]);
			close(pipefd[1][1]);
			execve("/bin/ls", ls, NULL); 
		}
		else 
		{
			pid[1] = fork();
			if (pid[1] == 0)
			{
			printf("wc process\n");
			dup2(pipefd[0][0], 0);
			dup2(pipefd[1][1], 1);
			close(pipefd[0][1]);
			close(pipefd[0][0]);
			close(pipefd[1][0]);
			close(pipefd[1][1]);
			execve("/usr/bin/wc", wc, NULL);
			}
			else 
			{
			close(pipefd[0][0]);
			close(pipefd[0][1]);
			close(pipefd[1][1]);
			waitpid(pid[1], NULL, 0);
			read(pipefd[1][0], buffer, 110);
			printf("HERE\n");
		   	printf("%s\n", buffer);	
			}

		}
		
	}
*/
	
	return 0;
}

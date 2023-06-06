/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:02:50 by melee             #+#    #+#             */
/*   Updated: 2023/05/02 15:52:59 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, int size)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (*s && i < size)
	{
		result[i] = *s++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	parse(char **arr, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if ((*s == c && s[-1] != c) && i != 0)
		{
			arr[j++] = ft_strndup(s - i, i);
			i = 0;
		}
		s++;
	}
	if (i != 0)
		arr[j++] = ft_strndup(s - i, i);
	arr[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;
	int		total_size;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	total_size = size(s, c);
	arr = malloc((total_size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	parse(arr, s, c);
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	int		index;
	char	**split;
	char	c = ' ';
	char	*s = "olol          ";
	
	split = ft_split(s, c);
	index = 0;
	while (split[index])
	{
		printf("%s | %p\n", split[index], split[index]);
		index++;
	}	
	return (0);
}
*/

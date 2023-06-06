/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:43:07 by melee             #+#    #+#             */
/*   Updated: 2023/05/02 12:01:06 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	set_check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (s1[i] && set_check(set, s1[i]))
		i++;
	while (s1[len] && set_check(set, s1[len]))
		len--;
	if (i >= ft_strlen(s1) || len <= 0)
		str = malloc(1 * sizeof(char));
	else
		str = malloc((len - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len + 1)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "   xxx   xxx";
	char *set = " x";
	char *result;

	result = ft_strtrim(str, set);
	printf("%s\n", result);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:31:36 by melee             #+#    #+#             */
/*   Updated: 2023/05/05 13:12:44 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*parse(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		matched;

	i = 0;
	while (*haystack && i++ < len)
	{
		if (*haystack == *needle)
		{
			j = 0;
			matched = 1;
			while (needle[j] != '\0')
			{
				if (haystack[j] != needle[j])
					matched = 0;
				j++;
			}
			if (matched == 1 && (i - 1 + j <= len))
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (NULL);
	return (parse(haystack, needle, len));
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	//char	needle[] = "MZIRIBMZE";
	//char haystack[] = "MZIRIBMZIRIBMZE123";
	//size_t	= strlen(needle);

	printf("original function result = %s\n", strnstr(NULL, "fake", 0));
	printf("result = %s", ft_strnstr(NULL, "fake", 0));
	return(0);
}
*/

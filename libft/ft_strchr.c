/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:45:14 by melee             #+#    #+#             */
/*   Updated: 2023/05/05 12:35:30 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	d;
	int		len;

	str = (char *)s;
	d = (char)(c);
	len = ft_strlen(str);
	if (d == '\0' && len > 0)
		return (str + len);
	if (d == '\0' && len == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str == d)
			return (str);
		str++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[] = "hello";
	char c = '\0';
	char *result;

	result = strchr(str, c);
	//result = ft_strchr(str, c);
	printf("%s\n", result);
	return (0);
}
*/

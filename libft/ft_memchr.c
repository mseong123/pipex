/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:04:32 by melee             #+#    #+#             */
/*   Updated: 2023/05/05 11:07:26 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	d;
	size_t			i;

	str = (unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while (i++ < n)
	{
		if (*str == d)
			return (str);
		str++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "/|\x12\xff\x09\x42\2002\42|\\";
	int	c = '\200';
	size_t n = 10;
	
	printf("%s\n", memchr(str, c, n));
	printf("%s\n", ft_memchr(str, c, n));

	return (0);
}
*/

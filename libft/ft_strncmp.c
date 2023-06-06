/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:18:02 by melee             #+#    #+#             */
/*   Updated: 2023/05/01 11:27:50 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	while (c[i] == d[i] && i < n - 1)
	{
		if (c[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (c[i] - d[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "hello";
	char	s2[] = "gello ";
	int		n;

	n = ft_strncmp(s1, s2, 0);
	printf("result = %d", n);
	return (0);	
}
*/

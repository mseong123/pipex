/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:39:56 by melee             #+#    #+#             */
/*   Updated: 2023/05/01 13:30:07 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s3[i] == s4[i])
	{
		i++;
	}
	return (s3[i] - s4[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s1[] = "gello";
	char s2[] = "heglo";
	size_t n = 5;

	printf("%d\n",ft_memcmp(s1,s2,n));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:26:53 by melee             #+#    #+#             */
/*   Updated: 2023/04/28 13:34:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	if (dstsize < 1)
		return (count);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "This is a plane in the sky";
	char	dst[] = "1";
	size_t	dstsize = 30;

	printf("original result %lu\n",strlcpy(dst,src,dstsize));
	printf("original dst %s\n",dst);	
	printf("ft result %lu\n",ft_strlcpy(dst,src,dstsize));
	printf("ft dst %s\n", dst);		
}
*/

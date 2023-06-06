/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:18:20 by melee             #+#    #+#             */
/*   Updated: 2023/04/29 13:00:26 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count_dst;
	size_t	count_src;

	count_dst = count_str(dst);
	count_src = count_str(src);
	i = 0;
	if (dstsize < 1)
		return (count_src + dstsize);
	while (src[i] != '\0' && i + count_dst < dstsize - 1)
	{
		dst[count_dst + i] = src[i];
		i++;
	}
	dst[count_dst + i] = '\0';
	if (dstsize < count_dst)
		return (count_src + dstsize);
	else
		return (count_dst + count_src);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	src[] = "hello";
	char	dst[13] = "goodbye";
	size_t	dstsize = 7;
	char	src1[] = "hello";
	char	dst1[13] = "goodbye";

	printf("original return result is = %lu\n", strlcat(dst, src, dstsize));
	printf("original concat string is = %s\n", dst);
	printf("my return result is = %lu\n", ft_strlcat(dst1, src1, dstsize));
	printf("my concat string is = %s\n", dst1);
	return (0);	
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:25:28 by melee             #+#    #+#             */
/*   Updated: 2023/04/29 15:28:15 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_char;
	char	*src_char;
	size_t	i;

	i = 0;
	dst_char = (char *)dst;
	src_char = (char *)src;
	while ((dst || src) && i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char src[]="abcdefgh";
	//char dst[] = "goodbye";
	//ft_memcpy(&src[5], &src[3], 3);
	memcpy(&src[5], &src[3], 3);
	printf("%s",src);
	return (0);
}
*/

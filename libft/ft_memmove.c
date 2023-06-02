/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:56:41 by melee             #+#    #+#             */
/*   Updated: 2023/05/01 07:43:19 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_char;
	char	*src_char;
	size_t	i;

	i = 0;
	dst_char = (char *)dst;
	src_char = (char *)src;
	if (dst_char > src_char)
		while (len--)
			dst_char[len] = src_char[len];
	else
	{
		while ((dst || src) && i < len)
		{
			dst_char[i] = src_char[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char src[]="abcdef";
	//memmove(&src[2], &src[0], 3);
	ft_memmove(&src[0], &src[3], 3);
	printf("%s",src);
	return (0);
}
*/

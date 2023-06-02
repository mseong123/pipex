/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:59 by melee             #+#    #+#             */
/*   Updated: 2023/04/28 15:20:38 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	d;

	i = 0;
	str = (char *)b;
	d = (unsigned char)c;
	while (i < len)
	{
		str[i] = d;
		i++;
	}
	return (b);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[]="hello";
	//ft_memset(str, 338, sizeof(int));
	memset(str, 'B', sizeof(int));
	printf("%s",str);
	return (0);
}
*/

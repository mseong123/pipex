/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:38:21 by melee             #+#    #+#             */
/*   Updated: 2023/04/28 10:33:59 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *str;

	str = "hello kajsjdkasjkdjaskjdjk";
	printf("original %lu\n",strlen(str));
	printf("ft %lu",ft_strlen(str));
}
*/

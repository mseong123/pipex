/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:46:13 by melee             #+#    #+#             */
/*   Updated: 2023/05/01 10:53:54 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//string assessed for this function is considered only up until the first '\0'
char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	d;

	d = (char)(c);
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == d)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char c = '\0';

	printf("my result = %s\n",ft_strrchr(str,c));
	return (0);
}
*/

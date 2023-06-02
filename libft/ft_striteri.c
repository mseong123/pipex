/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:28:17 by melee             #+#    #+#             */
/*   Updated: 2023/05/03 11:06:40 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	f_striteri(unsigned int n, char *c)
{
	*c = n + '0';
}

int	main(void)
{
	char	s[] = "override this !";

	ft_striteri(s, f_striteri);
	printf("%s\n",s);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:16:37 by melee             #+#    #+#             */
/*   Updated: 2023/05/09 10:06:34 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digit(unsigned long u, int size)
{
	int	digit;

	digit = 0;
	if (u == 0)
		return (1);
	if (u < 0)
		digit++;
	while (u != 0)
	{
		u /= size;
		digit++;
	}
	return (digit);
}

static char	*recursive(char *result, unsigned long u, char *base)
{
	if (u < 0)
	{
		u = -u;
		*result = '-';
		result++;
	}
	if (u >= (unsigned long)ft_strlen(base))
	{
		result = recursive(result, u / ft_strlen(base), base);
		result = recursive(result, u % ft_strlen(base), base);
	}
	else
	{
		*result = base[u % ft_strlen(base)];
		result++;
		*result = '\0';
	}
	return (result);
}

char	*ft_itoa_base(unsigned long u, char *base)
{
	char	*result;

	result = malloc((get_digit(u, ft_strlen(base)) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	recursive(result, u, base);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned long	n = -549831893213;

	printf("%s\n",ft_itoa_base(n,"0123456789abcdef"));
	return (0);
}
*/

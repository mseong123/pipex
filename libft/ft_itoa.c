/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:54:50 by melee             #+#    #+#             */
/*   Updated: 2023/05/03 10:11:51 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
//Have to use return pointer (result) because argument char 
//*result in each (recursive) function is a new pointer pointing 
//at the next address passed by previous function. Hence due to 
//the chaining process of the recursive function, have to return 
//the same pointer in order to use it.

static char	*recursive(char *result, int n)
{
	if (n < 0)
	{
		n = -n;
		*result = '-';
		result++;
	}
	if (n >= 10)
	{
		result = recursive(result, n / 10);
		result = recursive(result, n % 10);
	}
	else
	{
		*result = n + 48;
		result++;
		*result = '\0';
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;

	if (n == -2147483648)
	{
		result = ft_strdup("-2147483648");
		if (!result)
			return (NULL);
		return (result);
	}	
	result = malloc((get_digit(n) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	recursive(result, n);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = -2147483648;

	printf("%s\n",ft_itoa(n));
	return (0);
}
*/

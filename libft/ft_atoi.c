/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:18:54 by melee             #+#    #+#             */
/*   Updated: 2023/05/01 18:57:17 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(const char *str)
{
	if (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r')
		return (1);
	else if (*str == '\t' || *str == '\v')
		return (1);
	else
		return (0);
}

long int	ft_atoi(const char *str)
{
	int	result;
	int	positive;
	int	negative;

	result = 0;
	positive = 0;
	negative = 0;
	while (*str && is_space(str))
		str++;
	while (*str && ((*str == '-' && !negative && !positive)
			|| (*str == '+' && !positive && !negative)))
	{
		if (*str == '-')
			negative = 1;
		if (*str == '+')
			positive = 1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
		result = (result * 10) + *str++ - '0';
	if (negative)
		return (-1 * result);
	else
		return (result);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char str[] = "-+42";

	printf("%d\n",atoi(str));
	printf("%d\n",ft_atoi(str));
	return (0);
}
*/

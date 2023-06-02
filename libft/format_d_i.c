/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 07:41:37 by melee             #+#    #+#             */
/*   Updated: 2023/05/09 07:51:53 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_d_i(va_list ptr)
{
	int			n;
	char		*decimal;
	int			count;				

	n = va_arg(ptr, int);
	decimal = ft_itoa(n);
	count = ft_strlen(decimal);
	ft_putstr_fd(decimal, FD);
	free(decimal);
	return (count);
}

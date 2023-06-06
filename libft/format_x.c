/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:06:52 by melee             #+#    #+#             */
/*   Updated: 2023/05/09 10:13:24 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_x(va_list ptr)
{
	unsigned int	u;
	char			*hexa;
	int				count;

	u = va_arg(ptr, unsigned int);
	hexa = ft_itoa_base(u, "0123456789abcdef");
	count = ft_strlen(hexa);
	ft_putstr_fd(hexa, FD);
	free(hexa);
	return (count);
}

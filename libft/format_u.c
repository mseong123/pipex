/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:04:55 by melee             #+#    #+#             */
/*   Updated: 2023/05/09 10:13:34 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_u(va_list ptr)
{
	unsigned int	u;
	char			*u_decimal;
	int				count;

	u = va_arg(ptr, unsigned int);
	u_decimal = ft_itoa_base(u, "0123456789");
	count = ft_strlen(u_decimal);
	ft_putstr_fd(u_decimal, FD);
	free(u_decimal);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:11:31 by melee             #+#    #+#             */
/*   Updated: 2023/05/08 16:44:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_s(va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", FD);
		return (6);
	}
	ft_putstr_fd(str, FD);
	return (ft_strlen(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:00:40 by melee             #+#    #+#             */
/*   Updated: 2023/05/09 10:22:52 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FD 1

# include "libft.h"
# include "stdarg.h"

int		ft_printf(const char *str, ...);
char	*ft_itoa_base(unsigned long u, char *base);
int		format_c(va_list ptr);
int		format_s(va_list ptr);
int		format_p(va_list ptr);
int		format_d_i(va_list ptr);
int		format_u(va_list ptr);
int		format_x(va_list ptr);
int		format_upper_x(va_list ptr);

#endif

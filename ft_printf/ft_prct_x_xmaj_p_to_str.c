/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_x_xmaj_p_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:28:00 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/10 10:20:39 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_prct_x_xmaj_p_to_str(char *str, int idx, va_list ap)
{
	unsigned int			x;
	unsigned int			x_maj;
	unsigned long long int	p;

	if (str[idx + 1] == 'x')
	{
		x = va_arg(ap, unsigned int);
		return (ft_dec_to_hexa(x));
	}
	else if (str[idx + 1] == 'X')
	{
		x_maj = va_arg(ap, unsigned int);
		return (ft_dec_to_hexa_maj(x_maj));
	}
	else if (str[idx + 1] == 'p')
	{
		p = va_arg(ap, unsigned long long int);
		return (ft_putptr(p));
	}
	return (0);
}

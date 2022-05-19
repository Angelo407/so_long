/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_d_i_u_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:45:58 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/10 10:20:37 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_putnbr_us(unsigned int nb)
{
	if (nb == 4294967295)
	{
		ft_putnbr_us(nb / 10);
		ft_putchar('5');
	}
	else if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb > 9)
	{	
		ft_putnbr_us(nb / 10);
		ft_putnbr_us(nb % 10);
	}
}

int	ft_prct_d_i_u_to_str(char *str, int idx, va_list ap)
{
	int				d_i;
	unsigned int	u;

	if (str[idx + 1] == 'd' || str[idx + 1] == 'i')
	{
		d_i = va_arg(ap, int);
		ft_putnbr(d_i);
		return (ft_nbrlen(d_i));
	}
	else if (str[idx + 1] == 'u')
	{
		u = va_arg(ap, unsigned int);
		if (u <= 0)
		{
			ft_putnbr(u);
			return (ft_nbrlen(u));
		}
		else if (u > 0)
		{
			ft_putnbr_us(u);
			return (ft_nbrlen_plus(u));
		}
	}
	return (0);
}

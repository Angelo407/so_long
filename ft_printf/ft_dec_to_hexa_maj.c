/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hexa_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:12:32 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/10 10:20:25 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	zero_case(unsigned int nb, char *res)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	return (0);
}

char	*lazyness_max(int i)
{
	char	*res;

	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	return (res);
}

int	ft_dec_to_hexa_maj(unsigned int nb)
{	
	int		nb_div;
	int		nb_mod;
	char	*res;
	char	c;
	int		i;

	i = ft_nbrlen_hexa(nb);
	res = lazyness_max(i);
	if (zero_case(nb, res) == 1)
		return (1);
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod >= 0 && nb_mod <= 9)
			c = ft_itoa_char_hexa(nb_mod);
		else if (nb_mod >= 10 && nb_mod <= 15)
			c = 55 + nb_mod;
		nb_div = nb / 16;
		nb = nb_div;
		res[--i] = c;
	}
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}

// Pour mettre ft_dec_to_hexa(unsigned int nb) 
// et ft_dec_to_hexa_maj(unsigned int nb) ds une seule fonction :
/*
int	ft_dec_to_hexa(unsigned int nb, int choice)
{	
	int		nb_div;
	int		nb_mod;
	char	*res;
	char	c;
	int		i;

	i = ft_nbrlen_hexa(nb);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	if (nb == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod >= 0 && nb_mod <= 9)
			c = ft_itoa_char_hexa(nb_mod);
		else if (nb_mod >= 10 && nb_mod <= 15)
		{
			if (choice == 1)
				c = 87 + nb_mod;
			else if (choice == 2)
				c = 55 + nb_mod;
		}
		nb_div = nb / 16;
		nb = nb_div;
		res[--i] = c;
	}
	ft_putstr(res);
	free(res);
	return (ft_strlen(res));
}

// Ensuite ds ft_prct_x_xmaj_p_to_str :
int	ft_prct_x_xmaj_p_to_str(char *str, int idx, va_list ap)
{
	unsigned int			x;
	unsigned int			x_maj;
	unsigned long long int	p;

	if (str[idx + 1] == 'x')
	{
		x = va_arg(ap, unsigned int);
		return (ft_dec_to_hexa(x, 1));
	}
	else if (str[idx + 1] == 'X')
	{
		x_maj = va_arg(ap, unsigned int);
		return (ft_dec_to_hexa(x_maj, 2));
	}
	else if (str[idx + 1] == 'p')
	{
		p = va_arg(ap, unsigned long long int);
		return (ft_putptr(p));
	}
	return (0);
}
*/

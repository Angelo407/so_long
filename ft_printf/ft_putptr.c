/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:38:46 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/10 10:20:49 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putptr(unsigned long long int nb)
{
	int	ret;

	write(1, "0x", 2);
	ft_dec_to_hexa_p(nb);
	ret = ft_nbrlen_hexa_p(nb) + 2;
	return (ret);
}

static int	ntm(unsigned long long int nb, char *res)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	return (0);
}

int	ft_dec_to_hexa_p(unsigned long long int nb)
{	
	unsigned long long int		nb_div;
	unsigned long long int		nb_mod;
	char						*res;
	char						c;
	int							i;

	i = ft_nbrlen_hexa_p(nb);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	if (ntm(nb, res) == 1)
		return (1);
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod <= 9)
			c = ft_itoa_char_hexa(nb_mod);
		else if (nb_mod >= 10 && nb_mod <= 15)
			c = 87 + nb_mod;
		nb_div = nb / 16;
		nb = nb_div;
		res[--i] = c;
	}
	ft_putstr(res);
	free(res);
	return (ft_strlen(res));
}

/*
int	ft_dec_to_hexa_p(unsigned long long int nb)
{	
	unsigned long long int		nb_div;
	unsigned long long int		nb_mod;
	char						*res;
	char						c;
	int							i;
	
	i = ft_nbrlen_hexa_p(nb);
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
			c = 87 + nb_mod;
		nb_div = nb / 16;
		nb = nb_div;
		i--;
		res[i] = c;
	}
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
*/

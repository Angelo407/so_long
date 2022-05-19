/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:08:04 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/10 10:20:42 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	prct(const char *str, va_list ap, size_t idx, int size)
{
	size = 0;
	if (str[idx + 1] == 'c' || str[idx + 1] == '%')
		size = size + ft_prct_c_prct_to_str((char *)str, idx, ap);
	else if (str[idx + 1] == 's')
		size = size + ft_prct_s_to_str((char *)str, idx, ap);
	else if (str[idx + 1] == 'd' || str[idx + 1] == 'i'
		|| str[idx + 1] == 'u')
		size = size + ft_prct_d_i_u_to_str((char *)str, idx, ap);
	else if (str[idx + 1] == 'x' || str[idx + 1] == 'X'
		|| str[idx + 1] == 'p')
		size = size + ft_prct_x_xmaj_p_to_str((char *)str, idx, ap);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	int		size;
	int		i;

	idx = 0;
	i = 0;
	size = 0;
	va_start(ap, str);
	while (str[idx] != '\0')
	{
		if (str[idx] != '%')
		{	
			write(1, &str[idx], 1);
			i++;
		}
		else if (str[idx] == '%')
		{
			size = size + prct(str, ap, idx, size);
			str++;
		}
		idx++;
	}
	va_end(ap);
	return (size + i);
}

/*
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	int		size;
	int		i;

	idx = 0;
	size = 0;
	i = 0;
	va_start(ap, str);
	while (str[idx] != '\0')
	{
		if (str[idx] != '%')
		{	
			write(1, &str[idx], 1);
			i++;
		}
		else if (str[idx] == '%')
		{
			if (str[idx + 1] == 'c' || str[idx + 1] == '%')
				size = size + ft_prct_c_prct_to_str((char *)str, idx, ap);
			else if (str[idx + 1] == 's')
				size = size + ft_prct_s_to_str((char *)str, idx, ap);
			else if (str[idx + 1] == 'd' || str[idx + 1] == 'i' || str[idx + 1] == 'u')
				size = size + ft_prct_d_i_u_to_str((char *)str, idx, ap);
			else if (str[idx + 1] == 'x' || str[idx + 1] == 'X' || str[idx + 1] == 'p')
				size = size + ft_prct_x_xmaj_p_to_str((char *)str, idx, ap);
			str++;
		}
		idx++;
	}
	va_end(ap);
	return (size + i);
}
*/

/*
int	main(void)
{
 	unsigned int prctx_min = 43253;
	unsigned int prctx_maj = 43253;

	ft_printf("pourcentage x_min = %x\n", prctx_min);
	ft_printf("pourcentage x_maj = %x\n", prctx_maj);
	
//	test_1_ft_printf();
//	test_2_ft_printf();
//	test_1_percent_c();
//	test_1_percent_prct();
//	test_1_percent_s();
//	test_2_percent_s();
//	test_1_percent_d();
//	test_1_percent_u();
//	test_1_percent_x();
//	test_1_percent_p();
//	test_1_mix();
	return (0);
}
*/

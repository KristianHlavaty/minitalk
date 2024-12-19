/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:37:59 by khlavaty          #+#    #+#             */
/*   Updated: 2023/03/05 18:43:41 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long long n, char *base, int base_len)
{
	int	i;

	i = 1;
	if (n / base_len > 0)
	{
		i = i + ft_putbase(n / base_len, base, base_len);
	}
	ft_putchar(base[n % base_len]);
	return (i);
}

int	ft_putnbrbase(unsigned long long n, char *base)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	i = ft_putbase(n, base, base_len);
	return (i);
}

int	ft_puthex(unsigned long long n, char formt)
{
	if (formt == 'x')
		return (ft_putnbrbase(n, "0123456789abcdef"));
	else
		return (ft_putnbrbase(n, "0123456789ABCDEF"));
}

int	ft_mem(char *mem_c, uintptr_t mem)
{
	int	i;

	i = 0;
	while (mem > 0)
	{
		mem_c[i] = mem % 16;
		if (mem_c[i] < 10)
			mem_c[i] += '0';
		else
			mem_c[i] += 87;
		mem = mem / 16;
		i++;
	}
	mem_c[i] = 'x';
	mem_c[i + 1] = '0';
	i++;
	return (i);
}

int	ft_putmemory(uintptr_t mem)
{
	char	mem_c[20];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (mem == 0)
	{
		ft_putstring("(nil)");
		return (5);
	}
	i = ft_mem(&mem_c[0], mem);
	while (i >= 0)
	{
		ft_putchar(mem_c[i]);
		j++;
		i--;
	}
	return (j);
}

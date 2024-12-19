/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:12:33 by khlavaty          #+#    #+#             */
/*   Updated: 2023/03/04 20:56:41 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, char c)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstring("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10, c);
		i += ft_putnbr(n % 10, c);
	}
	if (n < 10 && n != -2147483648)
	{
		c = n + '0';
		i += ft_putchar(c);
	}
	return (i);
}

int	ft_putnbrunsig(unsigned int n)
{
	char	c;
	int		i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbrunsig(n / 10);
		i += ft_putnbrunsig(n % 10);
	}
	if (n < 10)
	{
		c = n + '0';
		i += ft_putchar(c);
	}
	return (i);
}

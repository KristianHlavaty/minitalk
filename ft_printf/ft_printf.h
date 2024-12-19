/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:11:09 by khlavaty          #+#    #+#             */
/*   Updated: 2023/03/04 20:55:23 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		fts_check_formt(va_list args, char formt);
int		ft_putstring(char *str);
int		ft_putnbr(int n, char c);
int		ft_putnbrunsig(unsigned int n);
int		ft_puthex(unsigned long long n, char formt);
size_t	ft_strlen(const char *str);
int		ft_putbase(unsigned long long n, char *base, int base_len);
int		ft_putnbrbase(unsigned long long n, char *base);
int		ft_mem(char *mem_c, uintptr_t mem);
int		ft_putmemory(uintptr_t mem);

#endif
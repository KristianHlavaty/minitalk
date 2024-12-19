/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:06:04 by khlavaty          #+#    #+#             */
/*   Updated: 2023/07/15 19:53:58 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// _POSIX_C_SOURCE with the value 199309L is used to specify the POSIX version
// to be used. It is set to 199309L, which corresponds to POSIX.
// 1b with the threads extension. This macro ensures that the appropriate POSIX
// definitions and declarations are available.

// _XOPEN_SOURCE with the value 700 is used to specify the X/Open version to be
// used. It is set to 700, which corresponds to X/Open UNIX 2008.
// This macro ensures that the appropriate X/Open definitions and declarations
// are available.

// _DEFAULT_SOURCE with the value 1 is used to enable a default set of
// definitions and declarations. It activates various features and
// behaviors that are considered part of the "default" environment.

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_C_SOURCE 199309L
# define _XOPEN_SOURCE 700
# define _DEFAULT_SOURCE 1

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_data_len(volatile char *str);

extern volatile char	*g_data;
#endif
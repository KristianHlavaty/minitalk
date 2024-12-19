/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:05:36 by khlavaty          #+#    #+#             */
/*   Updated: 2023/07/15 20:58:56 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SIGUSR1 and SIGUSR2 are user-defined signals in UNIX systems that 
// can be used for various purposes in a program.

// Functionally, they can be used interchangeably in the sense that their
// behavior is not predefined by the system.

// There are variations in the behavior of signal()
// across UNIX implementations, which mean that it should
// never be used for establishing signal handlers in portable programs.
// Because of these portability issues, sigaction() is the (strongly)
// preferred API for establishing a signal handler

volatile char	*g_data;

void	ft_process_data(void)
{
	ft_printf("%s", g_data);
	free ((void *) g_data);
	g_data = malloc(1);
	g_data[0] = 0;
}

void	ft_realloc(volatile char **str, int newlen, int oldlen)
{
	int				i;
	volatile char	*newstr;

	i = 0;
	newstr = malloc(sizeof(char) * newlen);
	while (i < oldlen)
	{
		newstr[i] = (*str)[i];
		i++;
	}
	free ((void *) *str);
	*str = newstr;
}

char	read_data(int signl, unsigned char *c)
{
	static int				i;
	static int				data_len;

	*c |= (signl == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (*c == 0)
			return (2);
		data_len = ft_data_len(g_data);
		ft_realloc(&g_data, data_len + 2, data_len + 1);
		g_data[data_len] = (char)*c;
		g_data[data_len + 1] = '\0';
		*c = 0;
		return (1);
	}
	else
		*c <<= 1;
	return (0);
}

void	handle_signal(int signl, siginfo_t *info, void *context)
{
	static int				server_id;
	static unsigned char	c;

	(void)context;
	if (!server_id)
		server_id = info->si_pid;
	if (read_data(signl, &c) == 2)
	{
		ft_process_data();
		kill(server_id, SIGUSR2);
		server_id = 0;
		c = 0;
		return ;
	}
	kill(server_id, SIGUSR1);
}

int	main(void)
{
	struct sigaction	server;

	ft_printf("PID: %d\n", getpid());
	g_data = malloc(1);
	g_data[0] = 0;
	server.sa_flags = SA_SIGINFO;
	server.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

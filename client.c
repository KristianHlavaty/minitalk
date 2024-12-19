/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:05:43 by khlavaty          #+#    #+#             */
/*   Updated: 2023/07/15 20:56:40 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// todo move ft_atoi to utils

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	handle_response(int signl)
{
	struct sigaction	loop;

	if (signl == SIGUSR1)
	{
		loop.sa_handler = handle_response;
		sigaction(SIGUSR1, &loop, NULL);
	}
	else if (signl == SIGUSR2)
	{
		ft_printf("Message received!\n");
		exit(0);
	}
}

static void	send_message(char *str, int server_id)
{
	unsigned char	c;
	int				i;

	while (*str)
	{
		i = 0;
		c = *str++;
		while (i < 8)
		{
			if ((c >> (7 - i)) & 1)
				kill(server_id, SIGUSR1);
			else
				kill(server_id, SIGUSR2);
			usleep(250);
			i++;
		}
	}
	i = 0;
	while (i < 8)
	{
		kill(server_id, SIGUSR2);
		usleep(250);
		i++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	response;
	int					server_id;

	if (ac != 3)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	server_id = ft_atoi(av[1]);
	if (kill(server_id, 0) == -1)
	{
		ft_printf ("Error: Incorrect server PID\n");
		exit(EXIT_FAILURE);
	}
	response.sa_flags = SA_SIGINFO;
	response.sa_handler = handle_response;
	sigemptyset(&response.sa_mask);
	sigaction(SIGUSR1, &response, NULL);
	sigaction(SIGUSR2, &response, NULL);
	send_message(av[2], ft_atoi(av[1]));
	return (1);
}

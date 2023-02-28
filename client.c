/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:36:01 by hyecheon          #+#    #+#             */
/*   Updated: 2023/02/25 19:19:14 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	error_exit(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	send_sig(pid_t pid, char c)
{
	int	bit_i;

	bit_i = 0;
	while (bit_i < 8)
	{
		if (((c >> bit_i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_i++;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		send_sig(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error_exit("Usage : ./client [server pid] [string]\n");
	pid = ft_atoi(argv[1]);
	if (100 > pid || pid > 99998)
		error_exit("Pid Error\n");
	send_str(pid, argv[2]);
	return (0);
}

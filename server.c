/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:36:18 by hyecheon          #+#    #+#             */
/*   Updated: 2023/02/25 16:36:20 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	signal_handler(int sig)
{
	static char	recieve_data;
	static int	bit_cnt;

	if (sig == SIGUSR1)
		recieve_data |= (1 << bit_cnt);
	else if (sig == SIGUSR2)
		recieve_data |= (0 << bit_cnt);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		bit_cnt = 0;
		write(1, &recieve_data, 1);
		recieve_data = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}

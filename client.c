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

int	send_str(pid_t pid, char *str)
{
	int	str_i;
	int	bit_i;

	str_i = 0;
	while (i < ft_strlen(str))
	{
		bit_i = 0;
		while (bit_i < 8)
		{
			if (((str[i] >> bit_i) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit_i--;
		}
		str_i++;
	}
}

int	main(int argc, char **argv)
{
	pit_t	pid;

	if (argc != 3)
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}

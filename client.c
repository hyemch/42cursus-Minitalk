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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

int	send_str(pid_t pid, char *str)
{
	int	str_i;
	int	bit_i;

	str_i = 0;
	while (i < ft_strlen(str))
	{
		bit_i = 7;
		while (bit_i >= 0)
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

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result < 0)
			return ((sign + 1) / -2);
		str++;
	}
	return (result * sign);
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

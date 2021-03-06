/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:29:29 by san               #+#    #+#             */
/*   Updated: 2022/02/25 10:32:25 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	msgchar_to_bit(int pid, int msgchar_int)
{
	int	*bit;
	int	i;

	i = 8;
	bit = (int *)malloc(8 * sizeof(int));
	if (!bit)
	{
		write(1, "MALLOC ERROR\n", 13);
		exit(1);
	}
	ft_bzero(bit, 8);
	while (--i >= 0)
	{
		bit[i] = msgchar_int % 2;
		msgchar_int = msgchar_int / 2;
	}
	while (++i < 8)
		send_signal(pid, bit[i]);
	free(bit);
}

void	send_message(int pid, char *message)
{
	int	i;
	int	msgchar_int;

	i = 0;
	msgchar_int = 0;
	while (message[i])
	{
		msgchar_int = (int)message[i];
		msgchar_to_bit(pid, msgchar_int);
		i++;
	}
	msgchar_to_bit(pid, 10);
}

int	main(int ac, char **argv)
{
	int	pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}

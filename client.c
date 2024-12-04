/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:14:15 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/12/03 20:02:57 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	temp;

	i = 0;
	neg = 1;
	temp = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		temp = (nptr[i] - '0') + (temp * 10);
		i++;
	}
	return (temp * neg);
}

static void	ft_error(void)
{
	write(2, "Incorrect usage! [corret: ./client <PID> phrase ]\n", 50);
}

static void	confirmation(int signum)
{
	if (signum == SIGUSR1)
		write(1, "message sent!\n", 14);
}

static void	send_message(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (0b00000001 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		signal(SIGUSR1, &confirmation);
		while (av[2][i])
		{
			send_message(pid, av[2][i]);
			i++;
		}
		send_message(pid, '\0');
	}
	else
	{
		ft_error();
		return (1);
	}
	return (0);
}

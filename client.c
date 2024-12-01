/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:14:15 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/11/28 18:18:47 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

// ------------------------- utils ----------------------------

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

// ------------------------------------------------------------

static void	send_message(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (00000001 >> i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	pid;
		int	i;

		pid = ft_atoi(av[1]);
		i = 0;
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

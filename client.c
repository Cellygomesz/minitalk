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
#include <stdio.h>

int	ft_atoi(const char *nptr)
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

// --------------------------------------------------------

void	print_bits(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (num & (128 >> i) == 1)
			kill(pid, SIGUSR1);
		else
				kill(pid, SIGUSR2);
		i++;
	}
}

//----------------------------------------------------------



//                 65
void	sendchar(int c, int pid)
{
	while (c >= 10)
	{
		c -= 10;
		kill(pid, SIGUSR2);
		usleep(700);
	}
	while (c > 0)
	{
		c--;
		kill(pid, SIGUSR1);
		usleep(700);
	}
	kill(pid, SIGINT);
	usleep(700);
}

// ./a.out 93993 a
int main(int ac, char **av)
{
	int	pid;
	pid = ft_atoi(av[1]);
	int	i;
	i = 0;
	while (av[2][i])
	{
		 sendchar(av[2][i], pid);
		 i++;
	}

	return (0);
}

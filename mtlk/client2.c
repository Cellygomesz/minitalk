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

// ------------------ utils.c ------------------------------------

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

void    ft_error(void)
{
    write(2, "incorrect usage. The program will be terminated.Try again.\n", 59);
}

// -----------------------------------------------------------------

static void	send_message(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (128 >> i) == 1)
			kill(pid, SIGUSR1);
		else if (c & (128 >> i) == 0)
				kill(pid, SIGUSR2);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int	pidsize;
		int	pid;
		int	i;
		
		pidsize = 0;
		while (av[1][pidsize])
			pidsize++;
		if (pidsize != 5)
		{
			ft_error();
			return (0);
		}
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_message(pid, av[2][i]);
		 	i++;
		}
	}
	else
		ft_error();
	return (0);
}
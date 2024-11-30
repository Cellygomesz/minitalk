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


void	sendbits(int pid, int c)
{
	int	i;
	int	bit;

	i = 0;
	bit =0;

	while (i < 8)
	{
		if (num & (128 >> i) == 1)
			kill(pid, SIGUSR1);
		else
				kill(pid, SIGUSR2);
		i++;
	}

	if (c == 1)
		kill(pid, );
	else if (c == 0)
		kill(pid, );
}


int main(int ac, char **av)
{
	if (ac == 3)
	{
		int	pidsize;
		int	pid;
		int	i;
		
		pidsize = 0;
		while (av[1][i])
			pidsize++;
		if (pidsize != 6)
		{
			ft_error();
			return (0);
		}
		i = 0;
		pid = ft_atoi(av[1])
		while (av[2][i])
		{
		 	sendbits(pid, av[2][i]);
		 	i++;
		}
		return (0);
	}
}
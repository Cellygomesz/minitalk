/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:49:49 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/12/03 21:05:50 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	put_message(int sig, siginfo_t	*siginfo, void *context)
{
	static int	sizebit;
	static int	caracter;

	(void)context;
	if (sig == SIGUSR1)
		caracter |= (0b00000001 << sizebit);
	sizebit++;
	if (sizebit == 8)
	{
		write(1, &caracter, 1);
		if (caracter == '\0')
			kill(siginfo->si_pid, SIGUSR1);
		sizebit = 0;
		caracter = 0;
	}
}

int	main(void)
{
	struct sigaction	query_action;

	sigemptyset(&query_action.sa_mask);
	query_action.sa_sigaction = &put_message;
	query_action.sa_flags = SA_SIGINFO;
	write(1, "[PID: ", 6);
	ft_putnbr(getpid());
	write(1, "]\n", 2);
	sigaction(SIGUSR1, &query_action, NULL);
	sigaction(SIGUSR2, &query_action, NULL);
	while (1)
		pause();
	return (0);
}

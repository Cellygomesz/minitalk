/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:17:59 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/11/28 15:33:29 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	name(int sig)
{
	static int	letter;

	if (sig == SIGUSR1)
		letter += 1;
	else if (sig == SIGUSR2)
		letter += 10;
	else if (sig == SIGINT)
	{
		write(1, &letter, 1);
		letter = 0;
	}
}

int	main(void)
{
	printf("PID: [ %d ]\n", getpid());
	signal(SIGINT, name);
	signal(SIGUSR1, name);
	signal(SIGUSR2, name);

	while (42)
		;
	return (0);
}

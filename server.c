/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:17:59 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/12/01 13:43:40 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	put_message(int sig)
{
	static int	sizebit;
	static int	caracter;

	if (sig == SIGUSR1)
		caracter |= (00000001 << sizebit);
	sizebit++;
	if (sizebit == 8)
	{
		printf("%c", caracter);
		sizebit = 0;
		caracter = 0;
	}
}

int	main(void)
{
	printf("[PID: %d ]\n", getpid());
	signal(SIGUSR1, put_message);
	signal(SIGUSR2, put_message);
	while (1)
		;
	return (0);
}

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

// put_message:
// recebe um sinal
// se aquele sinal for sg1 (1) ou sig (2)
// coloca seus respectivos numeros como string em uma variavel static
// usa atoi pra transformar ela em numero ascii
// printa aquele caracter formado

// PROBLEMAS
// tenho que fazer isso até 8 bits, e depois zerar minha variável static;


void	put_message(int sig)
{
	static char	*c = 0;

	if ()
}

int	main(void)
{
	printf("[PID: %d ]\n", getpid());
	signal(SIGUSR1, put_message());
	signal(SIGUSR2, put_message());
	while (42)
		;
	return (0);
}
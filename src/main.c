/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:44:12 by inazaria          #+#    #+#             */
/*   Updated: 2025/07/24 18:04:51 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static int
parse_arg(char *argv[])
{
	if (!argv || !*argv)
		return (FUNC_FAILURE);

	return (FUNC_SUCCESS);
}

static int	
ft_ping(void)
{
	printf("ft_ping !\n");

	return (FUNC_SUCCESS);
}

int 
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf(BAD_ARG);
		exit(EXIT_FAILURE);
	}

	if (!parse_arg(argv)) {
		printf(INVALID_ARG);
		exit(EXIT_FAILURE);
	}

	int	result;

	result = ft_ping();
	return (result == FUNC_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}

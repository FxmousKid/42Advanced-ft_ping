/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:44:12 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/02 18:26:23 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static void
ft_ping(struct s_ping *data)
{
	printf("ft_ping !\n");
	(void)data;

}

// For proper error handling
extern const char *__progname;

int 
main(int argc, char *argv[])
{
	struct s_ping	data = {.progname = __progname};
	
	
	if (argc < 2) {
		ARG_MISSING(__progname);
		MORE_INFO_MSG(argv[0]);
		exit(EXIT_BAD_ARGS);
	}

	if (!parse_cli(argc, argv, &data))
		exit(EXIT_BAD_ARGS);

	ft_ping(&data);
	return data.exit_code;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:07:09 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/04 18:19:12 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

_Noreturn 
void	fatal(const char *msg)
{
	fprintf(stderr, "%s[FATAL] %s%s\n", RED, msg, WHT);
	exit(EXIT_OTHER);
}

void	fatal_strerror(const char *msg)
{
	fprintf(stderr, "%s[FATAL] %s: %s%s\n", RED, msg, strerror(errno), WHT);
	exit(EXIT_OTHER);
}


FILE	*get_logfile(void)
{
	static FILE *logfile = NULL;

	if (!logfile)
		logfile = fopen(LOGFILE_NAME, "w");

	if (!logfile)
		fatal_strerror("Log file creation");

	return logfile;
}

void	close_logfile(void) 
{
	fclose(get_logfile());
}

void	log_error(const char *msg, FILE *log)
{
	fprintf(stderr, "%s[FATAL] %s%s\n", RED, msg, WHT);
	fprintf(log, "%s[FATAL] %s%s\n", RED, msg, WHT);
}

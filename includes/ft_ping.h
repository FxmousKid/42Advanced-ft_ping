#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h> // IWYU pragma: keep
# include <stdbool.h>
# include <bits/posix1_lim.h>
# include <netinet/in.h>
// # include <sys/socket.h>

# include "ANSI-colors.h"
# include "defines.h" // IWYU pragma: keep

struct s_stats {
	int			sent; // packets sent
	int			received; // packets received
	int			lost; // packets lost
	double			avg_time; // average time in ms
	double			min_time; // min time in ms
	double			max_time; // max time in ms
	double			stddev_time; // standard deviation in ms
};

struct s_hosts {
	char			host[_POSIX_HOST_NAME_MAX + 1]; // + 1 for '\0'
	struct s_stats		stats;
	struct in_addr		ip;
	struct s_hosts		*next;
	size_t			host_idx;
};

struct s_ping {
	int			socket; // socket fd
	int			count_max; // CLI option -c [count_max]
	bool			is_verbose; // CLI option -v presence or not
	short			exit_code;
	const char		*progname; // for error msgs
	struct s_hosts		*hosts;
};

struct s_icmp_packet {
	int8_t		type;
	int8_t		code;
	int16_t		checksum;
	int16_t		identifier;
	int16_t		seq_number;
};

// Parsing
void		parse_cli(int argc, char *argv[], struct s_ping *data);
bool		parse_hosts(struct s_ping *data, char *argv[]);
struct s_hosts	*get_hosts(void);
void		hosts_free();


// Utils
bool	has_host(struct s_ping *data);

void	print_help(const char *progname);
void	print_info(struct s_ping *data);
void	print_hosts_info(struct s_hosts *hosts);

void	fatal(const char *msg);
void	fatal_strerror(const char *msg);

FILE	*get_logfile(void);
void	log_error_strerror(const char *msg, FILE *log);
void	log_fatal(const char *msg, FILE *log);
void	log_close(void);
void	log_error(const char *msg, FILE *log);


#endif

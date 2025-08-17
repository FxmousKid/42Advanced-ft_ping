/**
 * @file ft_ping.h
 * @brief main header file
 * @ingroup 
 *
 * @author Iyan Nazarian
 * @date 2025-08-11
 * @version v0.1.0-1-g927c91f
 *
 * @details
 *  contains most structures, and all functions declarations for now
 */

#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h> // IWYU pragma: keep
# include <stdbool.h>
# include <bits/posix1_lim.h>
# include <netinet/in.h>
// # include <sys/socket.h>

# include "ANSI-colors.h"
# include "defines.h" // IWYU pragma: keep

/**
 * @struct s_stats
 * @brief stores the statistics related to packet operations 
 * of a specific host
 *
 * @details
 *  number of packets sent, received, and lost, are of type int
 *  because setting some of their values to -1 could be use as a
 *  sort of sentinel value
 *
 */
struct s_stats {
	/** @brief number of sent packets. */
	int			sent;
	/** @brief number of received packets. */
	int			received;
	/** @brief number of lost packets. */
	int			lost;
	/** @brief average time for packet operations */
	double			avg_time;
	/** @brief minimum time for packet operations */
	double			min_time;
	/** @brief maximum time for packet operations */
	double			max_time;
	/** @brief standard deviation for packet operations */
	double			stddev_time;
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
	uint8_t		type;
	uint8_t		code;
	uint16_t	checksum;
	uint16_t	identifier;
	uint16_t	seq_number;
};

// Parsing

/** @brief fills the passed contexte structure by parsing argv
 * options and arguments
 * @details handles all options desribed when calling ft_ping -h.\n
 * Can handle multi-hosts parsing -- IP addresses (IPv4) or hosts (FQDN).\n
 * Arguments and Options don't have a specific order, but POSIX specifies
 * that all options be passed before arguments */
void		parse_cli(int argc, char *argv[], struct s_ping *data);
/** @brief allocates s_hosts for every hosts passed via argv. 
 * @details allocates a linked list cell for each hosts passed via argv
 * and logs errors (failed calloc(3) call) and retruns false,
 * else returns true*/
bool		parse_hosts(struct s_ping *data, char *argv[]);
/** @brief returns the head of the allocated struct s_hosts linked list. 
 * @details assumes hosts_free() has not been called, else segfaults can happen\n
 * do NOT handle freeing the returned s_hosts when done with it, freeing it
 * is handled by atexit(3) upon calling exit(2)*/
struct s_hosts	*get_hosts(void);
/** @brief frees the allocated struct s_hosts by get_hosts().
 * @details this function should never manually be called, instead let
 * atexit(3) handle it, when calling exit(2)*/
void		hosts_free();


// Utils

/** @brief return true if hosts have been added. */
bool	has_host(struct s_ping *data);
/** @brief function to print debugging related informations. */
void	print_debug(struct s_ping *data);
/** @brief print usage guide for ft_ping. */
void	print_help(const char *progname);
/** @brief prints info regarding the main context structure. */
void	print_info(struct s_ping *data);
/** @brief prints info about parsed hosts and their packet stats. */
void	print_hosts_info(struct s_hosts *hosts);
/** @brief exits with the appropriate exit value : EXIT_OTHER. */
_Noreturn void	fatal(void);
/** @brief prints error msg to stderr then calls fatal() . */
_Noreturn void	fatal_error(const char *msg);
/** @brief same as fatal_error() but also prints errno-associated message. */
_Noreturn void	fatal_strerror(const char *msg);

// logfile

/** @brief returns the FILE ptr for the logfile. 
 *  @details assumes log_close() has not been called*/
FILE	*get_logfile(void);
/** @brief logs the given error message in the given file. */
void	log_error(const char *msg, FILE *log);
/** @brief same as log_error() buts adds strerror(3) output. */
void	log_strerror(const char *msg, FILE *log);
/** @brief logs the given successful event message in the given file. */
void	log_success(const char *msg, FILE *log);
/** @brief logs the given event message in the given file. */
void	log_event(const char *msg, FILE *log);
/** @brief calls log_error() then calls fatal(). */
void	log_fatal(const char *msg, FILE *log);
/** @brief calls fclose(3) on the logfile.
 * @details should never be called manually, should be called by exit(2)
 * by registering it with atexit(3)*/
void	log_close(void);

// inet stuff

/** @brief returns the socket fd for sending the ICMP packets. 
 * @details creates the socket with socket(2) and returns the given fd
 * else exits with non-zero exit code on failure with exit(2)*/
int	get_socket_icmp(void);
/** @brief closes the socket created with get_socket_icmp().
 * @details should only be called by atexit(3) when exit(2)*/
void	close_socket_icmp(void);
/** @brief creates and allocates the internet stuff
 * @details creates and allocates the ICMP socket.  */
bool	inet_setup(struct s_ping *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:57:00 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 18:57:02 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logging.h"

void	log_close_queue(t_philo *philo)
{
	(void) philo;
}

// returns true if no philo has died yet
bool	log_queue(void (*print_smth)(t_philo *p), t_philo *p)
{
	static pthread_mutex_t	io_mut = PTHREAD_MUTEX_INITIALIZER;
	static bool				io_open;
	bool					result;

	if (pthread_mutex_lock(&io_mut))
		return (false);
	if (print_smth == NULL)
		return (io_open = true, !pthread_mutex_unlock(&io_mut));
	if (io_open)
	{
		print_smth(p);
		io_open = (log_died != print_smth && log_close_queue != print_smth);
	}
	result = io_open;
	return (!pthread_mutex_unlock(&io_mut) && result);
}

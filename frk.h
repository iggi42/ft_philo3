/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:57:59 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/24 01:03:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRK_H
# define FRK_H
# include "philo_types.h"
# include <pthread.h>
# include <stdbool.h>

// set default values really
bool	frk_init(t_frk *frk, unsigned char id);
bool	frk_destroy(t_frk *frk);

// executes do_somthing with the philo after locking both fork mutexes for "taken"
int	frk_sync_do(int (*do_smth)(t_philo *me), t_philo *me);

// this needs to seperate error case and return val
// error case is also the "we need to stop early because another philo died" case
// returns -1 on error, 0 has not eaten, 1 on has eaten
int		frk_sync_takeup(t_philo *me);
int		frk_sync_putdown(t_philo *me);

// does what the names suggest
// returns true => no error
bool	frk_pickup(t_frk *frk);
bool	frk_putdown(t_frk *frk);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:49:36 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 20:49:38 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THINKERS_H
# define THINKERS_H
# include "philo_types.h"

void		init_thinker(t_philo *fresh, size_t i, t_philo_conf *c,
				t_frk *cutlery);
void		cleanup_thinkers(t_philo *philos, size_t n);
t_philo		*create_thinkers(t_philo_conf *c, t_frk *cutlery);
pthread_t	*start_thinkers(t_philo_conf *c, t_philo *philo);
void		wait4thinkers(pthread_t *ids, size_t n);
#endif

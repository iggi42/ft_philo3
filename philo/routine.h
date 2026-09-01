/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:24:22 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 20:24:30 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H
# include "philo_types.h"

// the routines that run inside a philo thread
void	*philo_routine_endless(void *s);
void	*philo_routine_maxmeals(void *s);

bool	philo_routine_eating(t_philo *me);
#endif

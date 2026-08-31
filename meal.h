/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:57:42 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 18:58:02 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils to interact with last_meal and its mutex in a philo struct

#ifndef MEAL_H
# define MEAL_H
# include "philo_types.h"

bool		is_last_meal2on(t_philo *p);
bool		set_last_meal2now(t_philo *p);
bool		set_last_meal2off(t_philo *p);

// gets the time since the last meal, triggers death if detected
t_timespan	read_philo_state(t_philo *p);

#endif

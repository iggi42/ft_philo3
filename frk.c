/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 04:02:18 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/13 05:52:20 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "frk.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

// taken is true if the fork is in use
bool	frk_init(t_frk *frk, unsigned char id)
{
	if (!frk)
		return (false);
	frk->id = id + 5;
	frk->taken = false;
	if (pthread_mutex_init(&frk->taken_mtx, NULL) == 0)
		return true;
	pthread_mutex_destroy(&frk->taken_mtx);
	return false;
}

bool	frk_destroy(t_frk *frk)
{
	if (!frk)
		return (false);
	return (pthread_mutex_destroy(&frk->taken_mtx) != 0);
}

// returns -1 on error, 0 has not eaten, 1 on has eaten
bool	frk_pickup(t_frk *frk)
{
	if (pthread_mutex_lock(&frk->taken_mtx))
		return (false);
	frk->taken = true;
	return (true);
}

bool	frk_putdown(t_frk *frk)
{
	frk->taken = false;
	return (pthread_mutex_unlock(&frk->taken_mtx) != 0);
}

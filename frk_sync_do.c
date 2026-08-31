/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sync.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:47:57 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/30 16:48:02 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_types.h"

static int	mtx_safely_do(pthread_mutex_t *mtx0, pthread_mutex_t *mtx1,
		int (*do_smth)(t_philo *arg), t_philo *arg)
{
	int	result;

	if (do_smth == NULL || mtx0 == mtx1)
		return (-1);
	if (pthread_mutex_lock(mtx0) != 0)
		return (-1);
	if (pthread_mutex_lock(mtx1) != 0)
		return (pthread_mutex_unlock(mtx0), -1);
	result = do_smth(arg);
	if (pthread_mutex_unlock(mtx1) != 0)
		result = -1;
	if (pthread_mutex_unlock(mtx0) != 0)
		result = -1;
	return (result);
}

static int	mtx_extra_safely_do(pthread_mutex_t *mtx0, pthread_mutex_t *mtx1,
		int (*do_smth)(t_philo *arg), t_philo *arg)
{
	int						result;
	static pthread_mutex_t	ser_mut = PTHREAD_MUTEX_INITIALIZER;

	if (pthread_mutex_lock(&ser_mut) != 0)
		return (-1);
	result = mtx_safely_do(mtx0, mtx1, do_smth, arg);
	if (pthread_mutex_unlock(&ser_mut) != 0)
		result = -1;
	return (result);
}

// run do_smth after taking the mutexes for taken of me philo
int	frk_sync_do(int (*do_smth)(t_philo *me), t_philo *me)
{
	int	(*strat)(pthread_mutex_t * mtx0, pthread_mutex_t * mtx1,
			int (*do_smth)(t_philo * arg), t_philo *arg);

	if (me == NULL || me->left == NULL || me->right == NULL)
		return (-1);
	// if(me->c->n_phil > 50)
	// 	strat = mtx_safely_do;
	// else
	strat = mtx_extra_safely_do;
	if (me->left->id > me->right->id)
		return (strat(&me->left->taken_mtx, &me->right->taken_mtx,
				do_smth, me));
	return (strat(&me->right->taken_mtx, &me->left->taken_mtx, do_smth,
			me));
}

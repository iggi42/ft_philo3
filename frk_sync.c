#include "frk.h"
#include "logging.h"
#include "philo_types.h"
#include <stdbool.h>
#include <stdio.h>

static int	protected_takeup(t_philo *me)
{
	if (!(!(me->left->taken) && !(me->right->taken)))
		return (0);
	if (!log_queue(log_forklift, me) || !log_queue(log_forklift, me))
		return (-1);
	me->right->taken = true;
	me->left->taken = true;
	return (1);
}

static int	protected_takedown(t_philo *me)
{
	if (!me->right->taken || !me->left->taken)
		return (-1);
	me->right->taken = false;
	me->left->taken = false;
	return (1);
}

// returns -1 on error, 0 has not eaten, 1 on has eaten
int	frk_sync_takeup(t_philo *me)
{
	return (frk_sync_do(protected_takeup, me));
}

int	frk_sync_putdown(t_philo *me)
{
	return (frk_sync_do(protected_takedown, me));
}

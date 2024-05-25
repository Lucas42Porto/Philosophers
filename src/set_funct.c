/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:37:15 by lumarque          #+#    #+#             */
/*   Updated: 2024/05/25 21:20:07 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_keep_iterating(t_data *data, bool set_to)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = set_to;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:37:15 by lumarque          #+#    #+#             */
/*   Updated: 2024/05/07 20:48:21 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	This function loop thorough all the philosophers infinitely
	unless fifth parameter has given. In this case it will loop
	thorough untill philosophers complete their total must_eat times.
	Whenever a philosopher's last_eat time become bigger than die_time,
	it means our philosopher died out of starving. In this case,
	we lock our funeral mutex for other philosophers not to race to die.
	We lock the funeral mutex in printf function.
*/
void	ft_die(t_phi_data *data)
{
	t_phi_data				*tmp;
	int						j;

	tmp = data;
	while (*data->done < data->total_philo)
	{
		j = ft_time(data->time);
		if (j >= data->die_time)
		{
			*data->did_die = 1;
			printf("%ldms - The philo number %i, died!💀\n", ft_time(data->time), data->index);
			return ;

		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}

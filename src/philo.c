/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:32:44 by lumarque          #+#    #+#             */
/*   Updated: 2024/05/07 20:50:20 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wrong_input(void)
{
	printf("\033[0;31mWrong input has given!\033[0m \n");
	printf("\033[0;32mCorrect use: \033[0m \n");
	printf("$ ./philo <number_of_philosophers>  <time_to_did_die>");
	printf("<time_to_eat>  <time_to_sleep>");
	printf("<number_of_times_each_philosopher_must_eat>");
	printf("(optional) \n\n");
}

int	main(int argc, char **argv)
{
	t_phi_data	*data;
	int			did_die;
	int			done;

	if (argc == 5 || argc == 6)
	{
		did_die = 0;
		done = 0;
		data = ft_start(argc, argv, &did_die);
		if (data == NULL)
			return (1);
		ft_thread_create(data, &done);
		printf("Freee......");
		ft_free(data);
	}
	else
		wrong_input();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:52:31 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 16:36:57 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (!get_input(ac, av[1], &data))
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1200,
				1200, "Potato");
	hooks(data);
	mlx_loop(data.mlx);
	return (0);
}

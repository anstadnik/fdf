/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:52:31 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 16:11:57 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_map(t_data data)
{
	int i;
	int j;

	i = -1;
	while (++i < data.height)
	{
		j = -1;
		while (++j < data.width)
			ft_printf("%3d", data.field[i][j][2]);
		ft_printf("\n");
	}
}

/* static void	print_map(t_data data) */
/* { */
/* 	int i; */
/* 	int j; */

/* 	i = -1; */
/* 	while (++i < data.height) */
/* 	{ */
/* 		j = -1; */
/* 		ft_printf("y = %d\n", i); */
/* 		while (++j < data.width) */
/* 			ft_printf("x = %d, z = %d\n", data.field[i][j][0], data.field[i][j][2]); */
/* 		ft_printf("\n"); */
/* 	} */
/* } */

int		main(int ac, char **av)
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (!get_input(ac, av[1], &data))
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1200,
				1200, "Potato");
	ft_printf("%d %d\n", data.width, data.height);
	print_map(data);
	hooks(data);
	mlx_loop(data.mlx);
	return (0);
}

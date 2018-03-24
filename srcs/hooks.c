/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:25:04 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/24 19:01:02 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_c(void)
{
	exit(1);
}

static int	draw(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			mlx_pixel_put(data->mlx, data->win,
					data->field[i][j][0] + data->offs[0], // data->field[i][j][2],
					data->field[i][j][1] + data->offs[1], // data->field[i][j][2],
					0x00ffffff);
	}
	ft_printf("hehey\n");
	return (42);
}

void	hooks(t_data data)
{
	mlx_loop_hook(data.mlx, &draw, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_c, NULL);
	/* mlx_loop_hook(g_mlx_ptr, &f, NULL); */
}

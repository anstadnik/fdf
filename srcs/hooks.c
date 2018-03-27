/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:25:04 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 17:44:40 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				exit_c(void)
{
	exit(1);
}

static int		triggers(int key, void *param)
{
	t_data	*data;

	data = param;
	param = NULL;
	if (key == 53)
		exit(1);
	else if (key == 126)
		data->offs[0] += data->offs[0] < -100 ? 0 : -10;
	else if (key == 125)
		data->offs[0] += data->offs[0] > data->width * data->scale ? 0 : 10;
	else if (key == 123)
		data->offs[1] += data->offs[1] < -100 ? 0 : -10;
	else if (key == 124)
		data->offs[1] += data->offs[1] > data->height * data->scale ? 0 : 10;
	else if (key == 24)
		data->altitude += data->altitude > 500 ? 0 : 1;
	else if (key == 27)
		data->altitude += data->altitude < -500 ? 0 : -1;
	else if (key == 47)
		data->scale += data->scale > 200 ? 0 : 1;
	else if (key == 43)
		data->scale += data->scale < 5 ? 0 : -1;
	else if (key == 15)
	{
		data->scale = data->width > data->height ?
			1300 / (data->width + 2) : 1300 / (data->height + 2);
		data->offs[0] = data->scale;
		data->offs[1] = data->scale;
	}
	return (1);
}

void			hooks(t_data data)
{
	mlx_loop_hook(data.mlx, &draw, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_c, NULL);
	mlx_hook(data.win, 2, 5, triggers, &data);
}

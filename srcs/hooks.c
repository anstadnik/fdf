/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:25:04 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 17:33:43 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				exit_c(void)
{
	exit(1);
}

static t_point	convert(intmax_t *p1, t_data *data)
{
	t_point	rez;

	rez.z = p1[2] * data->altitude;
	rez.x = p1[0] * data->scale - rez.z / 2 + data->offs[1];
	rez.y = p1[1] * data->scale - 2 * rez.z / 3 + data->offs[0];
	return (rez);
}

int				draw(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(data->mlx, data->win);
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (i + 1 < data->height)
				draw_line(*data, convert(data->field[i][j], data),
						convert(data->field[i + 1][j], data));
			if (j + 1 < data->width)
				draw_line(*data, convert(data->field[i][j], data),
						convert(data->field[i][j + 1], data));
		}
	}
	return (42);
}

static int		triggers(int key, void *param)
{
	t_data	*data;

	data = param;
	param = NULL;
	if (key == 53)
		exit(1);
	else if (key == 126)
		data->offs[0] -= data->offs[0] < -100 ? 0 : 1;
	else if (key == 125)
		data->offs[0] += data->offs[0] > data->width * data->scale ? 0 : 1;
	else if (key == 123)
		data->offs[1] = data->offs[1] < -100 ? 0 : -1;
	else if (key == 124)
		data->offs[1] += data->offs[1] > data->height * data->scale ? 0 : 1;
	else if (key == 24)
		data->altitude += data->altitude > 500 ? 0 : 1;
	else if (key == 27)
		data->altitude += data->altitude < -500 ? 0 : -1;
	else if (key == 47)
		data->scale += data->scale > 200 ? 0 : 1;
	else if (key == 43)
		data->scale += data->scale < 5 ? 0 : -1;
	return (1);
}

void			hooks(t_data data)
{
	mlx_loop_hook(data.mlx, &draw, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_c, NULL);
	mlx_hook(data.win, 2, 5, triggers, &data);
}

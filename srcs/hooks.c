/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:25:04 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/26 19:40:16 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_c(void)
{
	exit(1);
}

static void	draw_line(t_data data, t_point p1, t_point p2)
{
	int dx;
	int	dy;
	int	error;
	int	diry;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	error = 0;
	diry = p2.y - p1.y;
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	while (p1.x < p2.x)
	{
		mlx_pixel_put(data.mlx, data.win, p1.x, p1.y, 0x00ffffff);
		error = error + dy;
		if (2 * error >= dx)
		{
			p1.y = p1.y + diry;
			error = error - dx;
		}
		p1.x++;
	}
}

/* static t_point	convert(int *p1, t_data *data) */
/* { */
/* 	t_point	rez; */

/* 	ft_printf("{blue}p1[0] = %d, p1[1] = %d p1[2] = %d\noffs[0] = %d, offs[1] = %d, scale = %d{eoc}\n", p1[0], p1[1], p1[2], data->offs[0], data->offs[1], data->scale); */
/* 	rez.x = (p1[0] + data->offs[0]) * data->scale; */
/* 	rez.y = (p1[1] + data->offs[1]) * data->scale; */
/* 	rez.z = p1[2] * data->scale; */
/* 	return (rez); */
/* } */

static int	draw(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	draw_line(*data, (t_point){100, 100, 1}, (t_point){150, 500, 1});
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

static int	triggers(int key, void *param)
{
	param = NULL;
	if (key == 53)
		exit(1);
	return (1);
}

void	hooks(t_data data)
{
	mlx_loop_hook(data.mlx, &draw, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_c, NULL);
	mlx_hook(data.win, 2, 5, triggers, NULL);
}

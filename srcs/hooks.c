/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:25:04 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 11:35:31 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_c(void)
{
	exit(1);
}

static t_point	convert(int *p1, t_data *data)
{
	t_point	rez;

	/* ft_printf("p1[0] = %d, p1[1] = %d p1[2] = %d\noffs[0] = %d, offs[1] = %d, scale = %d\n", p1[0], p1[1], p1[2], data->offs[0], data->offs[1], data->scale); */
	rez.z = p1[2] * data->altitude;
	rez.x = p1[0] * data->scale - rez.z / 2 + data->offs[1];
	rez.y = p1[1] * data->scale - rez.z + data->offs[0];
	ft_printf("x = %d, y = %d, z = %d\n", rez.x, rez.y, rez.z);
	return (rez);
}

/* static int	draw(t_data *data) */
int	draw(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (i + 1 < data->height)
			{
				/* ft_printf("\np1.x = %d, p1.y = %d, p1.z = %d, p2.x = %d, p2.y = %d, p2.z = %d, i = %d, j = %d\n", data->field[i][j][0], data->field[i][j][1], data->field[i][j][2], data->field[i + 1][j][0], data->field[i + 1][j][1], data->field[i + 1][j][2], i, j); */
				draw_line(*data, convert(data->field[i][j], data), convert(data->field[i + 1][j], data));
			}
			if (j + 1 < data->width)
				draw_line(*data, convert(data->field[i][j], data), convert(data->field[i][j + 1], data));
		}
		/* mlx_pixel_put(data->mlx, data->win, */
		/* 		data->field[i][j][0] + data->offs[0], // data->field[i][j][2], */
		/* 		data->field[i][j][1] + data->offs[1], // data->field[i][j][2], */
		/* 		0x00ffffff); */
	}
	mlx_clear_window(data->mlx, data->win);
	ft_printf("hehey\n");
	return (42);
}

static int	triggers(int key, void *param)
{
	t_data	*data;

	data = param;
	param = NULL;
	if (key == 53)
		exit(1);
	else if (key == 126)
		data->offs[0] -= 10;
	else if (key == 125)
		data->offs[0] += 10;
	else if (key == 123)
		data->offs[1] -= 10;
	else if (key == 124)
		data->offs[1] += 10;
	else if (key == 24)
		data->altitude += 10;
	else if (key == 27)
		data->altitude -= 10;
	return (1);
}

void	hooks(t_data data)
{
	mlx_loop_hook(data.mlx, &draw, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_c, NULL);
	mlx_hook(data.win, 2, 5, triggers, &data);
}

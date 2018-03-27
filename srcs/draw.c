/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:43:58 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 17:44:13 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

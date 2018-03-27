/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 10:11:43 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 17:34:05 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap(t_point *p1, t_point *p2)
{
	t_point	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static void	draw_dy(t_data data, t_point p1, t_point p2)
{
	int dx;
	int	dy;
	int	error;
	int	dirx;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	error = 0;
	dirx = p2.x - p1.x;
	if (dirx != 0)
		dirx = dirx > 0 ? 1 : -1;
	while (p1.y < p2.y)
	{
		mlx_pixel_put(data.mlx, data.win, p1.x, p1.y,
				p1.z == p2.z ? 0x00ffffff : 0x0000ff00);
		error = error + dx;
		if (2 * error >= dy)
		{
			p1.x = p1.x + dirx;
			error = error - dy;
		}
		p1.y++;
	}
}

static void	draw_dx(t_data data, t_point p1, t_point p2)
{
	int dx;
	int	dy;
	int	error;
	int	diry;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	error = 0;
	diry = p2.y - p1.y;
	if (diry != 0)
		diry = diry > 0 ? 1 : -1;
	while (p1.x < p2.x)
	{
		mlx_pixel_put(data.mlx, data.win, p1.x, p1.y,
				p1.z == p2.z ? 0x00ffffff : 0x0000ff00);
		error = error + dy;
		if (2 * error >= dx)
		{
			p1.y = p1.y + diry;
			error = error - dx;
		}
		p1.x++;
	}
}

void		draw_line(t_data data, t_point p1, t_point p2)
{
	int dx;
	int	dy;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	if (dx > dy)
	{
		if (p1.x > p2.x)
			swap(&p1, &p2);
		draw_dx(data, p1, p2);
	}
	else
	{
		if (p1.y > p2.y)
			swap(&p1, &p2);
		draw_dy(data, p1, p2);
	}
}

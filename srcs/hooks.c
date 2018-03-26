/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:25:04 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/26 16:27:10 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_c(void)
{
	exit(1);
}

static void	wu_swap(double *n1, double *n2)
{
	double	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

static int	wu_color(double per)
{
	int	tmp;

	tmp = 0xff * per;
	return ((tmp << 16) + (tmp << 8) + tmp);
}

static double	wu_prep(double *x1, double *x2, double *y1, double *y2)
{
	double	dx;
	double	dy;

	dx = *x2 - *x1;
	dy = *y2 - *y1;
	if (fabs(dx) < fabs(dy))
	{
		ft_printf("{red}dx{eoc}\n");
		wu_swap(x1, y1);
		wu_swap(x2, y2);
		wu_swap(&dx, &dy);
	}
	if (*x2 < *x1)
	{
		ft_printf("{red}x{eoc}\n");
		wu_swap(x1, x2);
		wu_swap(y1, y2);
	}
	return (dy / dx);
}

static double	wu_first(t_data data, double *x1, double y1, double gradient)
{
	double	xend;
	double	yend;
	double	xgap;
	double	ypxl1;

	xend = round(*x1);
	yend = y1 + gradient * (xend - *x1);
	xgap = 1 - ((*x1 + 0.5) - (int)(*x1 + 0.5));
	printf("%f\n", yend);
	*x1 = xend;
	ypxl1 = (int)yend;
	mlx_pixel_put(data.mlx, data.win, *x1, ypxl1, wu_color((1 - yend) * xgap));
	mlx_pixel_put(data.mlx, data.win, *x1, ypxl1 + 1, wu_color((yend - (int)yend) * xgap));
	return (yend + gradient);
}

static double	wu_last(t_data data, double *x2, double y2, double gradient)
{
	double	xend;
	double	yend;
	double	xgap;
	double	ypxl2;

	xend = round(*x2);
	yend = y2 + gradient * (xend - *x2);
	xgap = 1 - ((*x2 + 0.5) - (int)(*x2 + 0.5));
	*x2 = xend;
	ypxl2 = (int)yend;
	mlx_pixel_put(data.mlx, data.win, *x2, ypxl2, wu_color((1 - yend) * xgap));
	mlx_pixel_put(data.mlx, data.win, *x2, ypxl2 + 1, wu_color((yend - (int)yend) * xgap));
	return (yend + gradient);

}

static void	draw_line(t_data data, t_point p1, t_point p2)
{
	double	gradient;
	double	intery;
	double	x;

	ft_printf("{red}HEHEY{eoc}\n");
	printf("p1.x = %f, p1.y = %f, p2.y = %f, p2.y = %f\n", p1.x, p1.y, p2.x, p2.y);
	gradient = wu_prep(&p1.x, &p2.x, &p1.y, &p2.y);
	printf("gradient = %f\n", gradient);
	/* printf("%f %f %f %f\n", p1.x, p1.y, p2.x, p2.y); */
	intery = wu_first(data, &p2.x, p2.y, gradient);
	wu_last(data, &p2.x, p2.y, gradient);
	/* printf("%f %f %f %f\n", p1.x, p1.y, p2.x, p2.y); */
	x = p1.x;
	while (x++ < p2.x - 1)
	{
		mlx_pixel_put(data.mlx, data.win, x, (int)intery, wu_color((1 - (intery - (int)intery))));
		mlx_pixel_put(data.mlx, data.win, x, (int)intery + 1, wu_color((intery - (int)intery)));
		/* printf("%f\n", gradient); */
		intery = intery + gradient;
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
	mlx_clear_window(data->mlx, data->win);
	draw_line(*data, (t_point){100, 100, 1}, (t_point){900, 200, 1});
	while (++i < data->height)
	{
		j = -1;
		// add z-axis
		/* while (++j < data->width) */
		/* { */
		/* 	if (i + 1 < data->height) */
		/* 		draw_line(*data, convert(data->field[i][j], data), convert(data->field[i + 1][j], data)); */
		/* 	if (j + 1 < data->width) */
		/* 		draw_line(*data, convert(data->field[i][j], data), convert(data->field[i][j + 1], data)); */
		/* } */
		mlx_pixel_put(data->mlx, data->win,
				data->scale * (data->field[i][j][0] + data->offs[0]), // data->field[i][j][2],
				data->scale * (data->field[i][j][1] + data->offs[1]), // data->field[i][j][2],
				0x00ff0000);
	}
	return (42);
}

void	hooks(t_data data)
{
	mlx_loop_hook(data.mlx, &draw, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_c, NULL);
}

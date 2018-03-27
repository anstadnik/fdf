/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:53:36 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 10:38:12 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_data	t_data;
typedef struct s_point	t_point;

/*
* Offs is here to move the origin point
*/

// Add max height and make gradient based on it
struct		s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		altitude;
	int		***field;
	int		scale;
	int		offs[2];
};

struct		s_point
{
	int	x;
	int	y;
	int	z;
};

int	draw(t_data *data);
void	draw_line(t_data data, t_point p1, t_point p2);
int		get_input(int ac, char *av, t_data *data);
int		get_sizes_and_check(char *av, t_data *data, t_list **head);
void	hooks(t_data data);

#endif

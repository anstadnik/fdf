/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:53:36 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/26 16:03:46 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_data	t_data;
typedef struct s_point	t_point;

/*
* Offs - here to move the origin point
*/

struct		s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		***field;
	int		scale;
	int		offs[2];
	int		move[4];
};

struct				s_point
{
	double	x;
	double	y;
	double	z;
};

int		get_input(int ac, char *av, t_data *data);
int		get_sizes_and_check(char *av, t_data *data, t_list **head);
void	hooks(t_data data);

#endif

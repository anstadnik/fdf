/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:53:36 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/24 17:57:58 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_data	t_data;
typedef int			t_point;

struct		s_data
{
	int		width;
	int		height;
	int		***field;
	int		offs[2];
	int		move[4];
	int		rotate[4];
};

int		get_input(int ac, char *av, t_data *data);
int		get_sizes_and_check(char *av, t_data *data, t_list **head);

#endif

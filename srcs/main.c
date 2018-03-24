/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:52:31 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/24 18:15:53 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data data;
	int	i;
	int	j;

	if (!get_input(ac, av[1], &data))
		return (1);
	i = -1;
	while (++i < data.height)
	{
		j = -1;
		while (++j < data.width)
			ft_printf("%d %d %d %d\n", data.field[i][j][0], data.field[i][j][1], data.field[i][j][2], data.field[i][j][3]);
	}
	ft_printf("%d %d\n", data.width, data.height);
	ft_printf("hehehehey\n");
	return (0);
}

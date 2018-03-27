/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:46:46 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/27 17:33:25 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	err(t_list **head)
{
	if (*head)
		ft_lstdel(head, &free);
	ft_printf("You've got an error, dude\n");
	return (0);
}

static void	get_num(char **str, t_data *data, int i, int j)
{
	while (**str == ' ')
		(*str)++;
	if (**str == '-')
		(*str)++;
	data->field[i][j][0] = j;
	data->field[i][j][1] = i;
	data->field[i][j][2] = ft_atoi(*str);
	if (data->maltitude < data->field[i][j][2])
		data->maltitude = data->field[i][j][2];
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == ',')
		(*str) += 8;
}

static void	fill_field(t_list *head, t_data *data)
{
	int		i;
	int		j;
	char	*cur;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		cur = head->content;
		while (++j < data->width)
			get_num(&cur, data, i, j);
		head = head->next;
	}
}

int			get_input(int ac, char *av, t_data *data)
{
	t_list	*head;
	int		i;
	int		j;

	head = NULL;
	if (ac != 2 || !get_sizes_and_check(av, data, &head))
		return (err(&head));
	data->field = malloc(sizeof(intmax_t **) * data->height);
	i = -1;
	while (++i < data->height)
	{
		(data->field)[i] = malloc(sizeof(intmax_t *) * data->width);
		j = -1;
		while (++j < data->width)
			data->field[i][j] = malloc(sizeof(intmax_t) * 3);
	}
	data->scale = data->width > data->height ?
		1300 / (data->width + 2) : 1300 / (data->height + 2);
	data->offs[0] = data->scale;
	data->offs[1] = data->scale;
	data->altitude = data->scale / 5 ? data->scale / 10 : 1;
	fill_field(head, data);
	ft_lstdel(&head, &free);
	return (1);
}

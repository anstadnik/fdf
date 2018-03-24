/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:37:24 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/24 17:39:58 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_num(char **str)
{
	int	c;

	c = 6;
	if (**str == '-')
		(*str)++;
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == ',')
	{
		if (*(*str)++ != '0' || *(*str)++ != 'x')
			return (0);
		while (c--)
		{
			if (ft_strsrch("0123456789ABCDEF", (*str)[c]) == -1)
				return (0);
		}
	}
	if (**str == ' ' && (*str)++)
		return (1);
	else if (**str == '\0')
		return (1);
	else
		return (0);
}

static int		check_line(char *str, t_data *data)
{
	int	width;

	width = 0;
	while (*str != '\0')
	{
		if (check_num(&str))
			width++;
		else
			return (0);
	}
	if (!width)
		return (0);
	if (data->width == 0)
		data->width = width;
	else if (data->width != width)
		return (0);
	return (1);
}

int		get_sizes_and_check(char *av, t_data *data, t_list **head)
{
	int		fd;
	char	*buf;

	data->height = 0;
	data->width = 0;
	fd = open(av, O_RDONLY);
	if (read(fd, NULL, 0) == -1)
		return (0);
	while (get_next_line(fd, &buf))
	{
		if (check_line(buf, data))
			data->height++;
		else
		{
			free(buf);
			return (0);
		}
		ft_lstpushb(head, buf, ft_strlen(buf) + 1);
	}
	close(fd);
	return (data->height != 0);
}

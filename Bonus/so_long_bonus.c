/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:32:14 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 16:29:11 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	parse2(char *a, t_inf *i_f)
{
	char	**cpy_map;
	char	**or_map;
	int		s;

	s = count_word(a, '\n');
	or_map = ft_split(a, '\n');
	cpy_map = ft_split(a, '\n');
	if (!or_map)
		return (free_ary(cpy_map), free(a), 1);
	if (check_element(or_map) || check_rules(or_map, s))
		return (free_ary(or_map), free_ary(cpy_map), free(a), 1);
	if (!cpy_map)
		return (free_ary(or_map), free(a), 1);
	*i_f = creat_data(or_map, s);
	if (i_f->x > 90 || i_f->y > 49)
		return (free_ary(or_map), free_ary(cpy_map), free(a), 1);
	coordition(i_f);
	flood_fil(cpy_map, i_f->info._x, i_f->info._y);
	if (check_map(cpy_map))
		return (free_ary(or_map), free_ary(cpy_map), free(a), 1);
	(free_ary(cpy_map), free(a));
	return (0);
}

static int	parse1(char **av1, t_inf *info)
{
	char	*buff;
	char	*join;
	int		fd;

	fd = open(av1[1], O_RDONLY);
	if (fd < 0)
		return (1);
	join = NULL;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (!ft_strcmp(buff, "\n"))
			return (free(join), free(buff), close(fd), 1);
		join = ft_strjoin(join, buff);
		if (!join)
			return (free(buff), free(join), 1);
		free(buff);
	}
	if (!join)
		return (1);
	if (close(fd) < 0)
		return (free(join), 1);
	return (parse2(join, info));
}

int	main(int ac, char **av)
{
	t_inf	_inf;

	if (ac == 2)
	{
		if (comparison(av[1], ".ber"))
			return (1);
		if (parse1(av, &_inf))
			return (write(2, "Error\ninvalide argment", 23), 1);
		_inf.info.nb_move = 0;
		coordition_1(_inf.p_, &_inf.info);
		open_win(&_inf);
	}
	else
		write(2, "Error\ninvalide argement 2\n", 24);
}

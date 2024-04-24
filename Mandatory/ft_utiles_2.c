/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:01:40 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/24 21:00:25 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_inf	creat_data(char **map_gm, int axe_y)
{
	t_inf	data;

	data.p_ = map_gm;
	data.x = ft_strlen(map_gm[0]);
	data.y = axe_y;
	data.px = 32;
	data.coll_found = 0;
	data.key = -1;
	return (data);
}

int	ft_strcmp(char	const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[i] == s2[j] && !s2[j])
		return (0);
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	if (i == ft_strlen(s2) && !s2[j] && i != 0)
		return (0);
	return (-1);
}

void	ft_putchar(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	free(str);
}

void	coordition_1(char **arg_v, t_cor *pos)
{
	int		i;
	int		j;

	i = 0;
	pos->nb_cool = 0;
	while (arg_v[i])
	{
		j = -1;
		while (arg_v[i][++j])
		{
			if (arg_v[i][j] == 'C')
				pos->nb_cool++;
			if (arg_v[i][j] == 80)
			{
				pos->_y = i;
				pos->_x = j;
			}
			if (arg_v[i][j] == 69)
			{
				pos->e_y = i;
				pos->e_x = j;
			}
		}
		i++;
	}
}

void	add_move(t_cor *cor)
{
	cor->nb_move++;
	write(1, "MOVES ", 7);
	(ft_putchar(ft_itoa(cor->nb_move)), write(1, "\n", 1));
}

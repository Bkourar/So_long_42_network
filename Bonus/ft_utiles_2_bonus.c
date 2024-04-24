/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:01:40 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/24 21:03:54 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_inf	creat_data(char **map_gm, int axe_y)
{
	t_inf	data;

	data.p_ = map_gm;
	data.x = ft_strlen(map_gm[0]);
	data.y = axe_y;
	data.px = 32;
	data.coll_found = 0;
	data.key = -1;
	data.info.nb_ghost = 0;
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

void	coordition_ghost(t_inf *d)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	d->g_x = malloc(sizeof(int) * count_nb_ghost(d));
	if (!d->g_x)
		exit(1);
	d->g_y = malloc(sizeof(int) * count_nb_ghost(d));
	if (!d->g_y)
		exit(1);
	while (d->p_[++i])
	{
		j = -1;
		while (d->p_[i][++j])
		{
			if (d->p_[i][j] == 'G')
			{
				d->g_x[x] = j;
				d->g_y[x] = i;
				x++;
			}
		}
	}
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

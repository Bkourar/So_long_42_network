/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:37:23 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 15:58:37 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;

	j = 0;
	if (!s1 && !s2)
		return (string = NULL, NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	string = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (!string)
		return (free((char *)s2), NULL);
	i = 0;
	while (s1[i])
		string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		string[j++] = s2[i++];
	string[j] = '\0';
	return (free((char *)s1), string);
}

void	free_ary(char **argement)
{
	int	i;

	if (!argement)
		return ;
	i = 0;
	while (argement[i])
	{
		free(argement[i]);
		i++;
	}
	free(argement);
}

void	coordition(t_inf *d)
{
	int		i;
	int		j;

	i = 0;
	d->info.nb_cool = 0;
	d->info.nb_ghost = 0;
	while (d->p_[i])
	{
		j = 0;
		while (d->p_[i][j])
		{
			if (d->p_[i][j] == 'C')
				d->info.nb_cool++;
			if (d->p_[i][j] == 'G')
				d->info.nb_ghost++;
			if (d->p_[i][j] == 80)
			{
				d->info._y = i;
				d->info._x = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fil(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'R';
		return ;
	}
	map[y][x] = 86;
	flood_fil(map, x, y + 1);
	flood_fil(map, x, y - 1);
	flood_fil(map, x + 1, y);
	flood_fil(map, x - 1, y);
}

int	check_map(char **a_v)
{
	int		i;
	int		j;

	i = -1;
	while (a_v[++i])
	{
		j = 0;
		while (a_v[i][j])
		{
			if (!(a_v[i][j] == 49 || a_v[i][j] == 86
				|| a_v[i][j] == 71 || a_v[i][j] == 48))
				return (1);
			j++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:37:23 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/24 20:07:17 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	coordition(t_inf *d, t_cor *pos)
{
	int		i;
	int		j;

	i = -1;
	pos->nb_cool = 0;
	while (d->p_[++i])
	{
		j = -1;
		while (d->p_[i][++j])
		{
			if (d->p_[i][j] == 'C')
				pos->nb_cool++;
			if (d->p_[i][j] == 80)
			{
				pos->_y = i;
				pos->_x = j;
			}
			if (d->p_[i][j] == 69)
			{
				pos->e_y = i;
				pos->e_x = j;
			}
		}
	}
}

void	flood_fil(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
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
				|| a_v[i][j] == 48))
				return (1);
			j++;
		}
	}
	return (0);
}

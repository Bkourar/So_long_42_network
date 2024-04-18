/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:18:25 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 14:34:26 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	comparison(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = strlen(s1) - 4;
	j = 0;
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	check_element(char **_ar)
{
	int	i;
	int	j;

	i = -1;
	while (_ar[++i])
	{
		j = 0;
		while (_ar[i][j] && (_ar[i][j] == 48 || _ar[i][j] == 49 ||
		_ar[i][j] == 71 || _ar[i][j] == 67 || _ar[i][j] == 69
		|| _ar[i][j] == 80))
			j++;
		if (!(_ar[i][j] == 48 || _ar[i][j] == 49 || _ar[i][j] == 67 ||
		_ar[i][j] == 71 || _ar[i][j] == 69 || _ar[i][j] == 80)
		&& _ar[i][j] != '\0')
			return (1);
	}
	return (0);
}

int	check_rules(char **ar, int size)
{
	int		i;
	size_t	j;
	int		dou_ble;
	int		collectible;

	i = -1;
	dou_ble = 0;
	collectible = 0;
	while (ar[++i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (ar[i][0] != 49 || (ar[i][j] != 49 && ar[i][j + 1] == '\0'))
				return (1);
			if (ar[i][j] == 69 || ar[i][j] == 80)
				dou_ble++;
			if (ar[i][j] == 67)
				collectible++;
			j++;
		}
		if (ar[i + 1] != NULL && j != strlen(ar[i + 1]))
			return (1);
	}
	return (check_rules1(dou_ble, collectible, ar, size));
}

int	check_rules1(int db, int coll, char **ar, int size)
{
	int	j;

	if (db > 2 || coll == 0)
		return (1);
	j = 0;
	while (ar[0][j] && ar[0][j] == 49)
		j++;
	if (ar[0][j] != '\0' && ar[0][j] != 49)
		return (1);
	j = 0;
	while (ar[size - 1][j] && ar[size - 1][j] == 49)
		j++;
	if (ar[size - 1][j] != '\0' && ar[size - 1][j] != 49)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *theString)
{
	size_t	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}

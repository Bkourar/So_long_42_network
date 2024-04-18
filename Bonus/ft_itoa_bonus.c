/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:29:42 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 08:25:15 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check(long number)
{
	long	i;
	int		j;

	i = 1;
	j = 0;
	if (number <= 0)
	{
		if (number < 0)
			number *= -1;
		j++;
	}
	while (number / i > 0)
	{
		i *= 10;
		j++;
	}
	return (j);
}

static char	*dynamic(long number, int j)
{
	char	*str;

	str = (char *) malloc ((sizeof(char) * j) + 1);
	if (!str)
		return (NULL);
	str[j--] = '\0';
	if (number <= 0)
	{
		if (number < 0)
		{
			str[0] = '-';
			number = -number;
		}
		else
			str[j--] = '0';
	}
	while (number)
	{
		str[j--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;

	nbr = (long)n;
	i = check(nbr);
	return (dynamic(nbr, i));
}

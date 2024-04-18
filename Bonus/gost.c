/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:29 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 17:26:00 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	g_move_right(t_inf *data, int i)
{
	coordition_ghost(data);
	if (data->p_[data->g_y[i]][data->g_x[i] + 1] == data->p_[data->info._y][data->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (data->p_[data->g_y[i]][data->g_x[i] + 1] == '0')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = '0';
		data->p_[data->g_y[i]][data->g_x[i] + 1] = 'G';
		draw_it(data, 4);
		draw_floor(data, data->g_x[i], data->g_y[i]);
	}
	else if (data->p_[data->g_y[i]][data->g_x[i] + 1] == 'C')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = 'C';
		data->p_[data->g_y[i]][data->g_x[i] + 1] = 'G';
		draw_it(data, 4);
		draw_floor(data, data->g_x[i], data->g_y[i]);
		draw_coll(data, data->g_x[i], data->g_y[i]);
	}
	free(data->g_x);
	free(data->g_y);
}

static void	g_move_left(t_inf *data, int i)
{
	coordition_ghost(data);
	if (data->p_[data->g_y[i]][data->g_x[i] - 1] == data->p_[data->info._y][data->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (data->p_[data->g_y[i]][data->g_x[i] - 1] == '0')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = '0';
		data->p_[data->g_y[i]][data->g_x[i] - 1] = 'G';
		draw_it(data, 3);
		draw_floor(data, data->g_x[i], data->g_y[i]);
	}
	else if (data->p_[data->g_y[i]][data->g_x[i] - 1] == 'C')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = 'C';
		data->p_[data->g_y[i]][data->g_x[i] - 1] = 'G';
		draw_it(data, 3);
		draw_floor(data, data->g_x[i], data->g_y[i]);
		draw_coll(data, data->g_x[i], data->g_y[i]);
	}
	free(data->g_x);
	free(data->g_y);
}

static void	g_move_up(t_inf *data, int i)
{
	coordition_ghost(data);
	if (data->p_[data->g_y[i] - 1][data->g_x[i]] == data->p_[data->info._y][data->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (data->p_[data->g_y[i] - 1][data->g_x[i]] == '0')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = '0';
		data->p_[data->g_y[i] - 1][data->g_x[i]] = 'G';
		draw_it(data, 1);
		draw_floor(data, data->g_x[i], data->g_y[i]);
	}
	else if (data->p_[data->g_y[i] - 1][data->g_x[i]] == 'C')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = 'C';
		data->p_[data->g_y[i] - 1][data->g_x[i]] = 'G';
		draw_it(data, 1);
		draw_floor(data, data->g_x[i], data->g_y[i]);
		draw_coll(data, data->g_x[i], data->g_y[i]);
	}
	free(data->g_x);
	free(data->g_y);
}

static void	g_move_down(t_inf *data, int i)
{
	coordition_ghost(data);
	if (data->p_[data->g_y[i] + 1][data->g_x[i]] == data->p_[data->info._y][data->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (data->p_[data->g_y[i] + 1][data->g_x[i]] == '0')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = '0';
		data->p_[data->g_y[i] + 1][data->g_x[i]] = 'G';
		draw_it(data, 2);
		draw_floor(data, data->g_x[i], data->g_y[i]);
	}
	else if (data->p_[data->g_y[i] + 1][data->g_x[i]] == 'C')
	{
		data->p_[data->g_y[i]][data->g_x[i]] = 'C';
		data->p_[data->g_y[i] + 1][data->g_x[i]] = 'G';
		(draw_it(data, 2), draw_floor(data, data->g_x[i], data->g_y[i]));
		draw_coll(data, data->g_x[i], data->g_y[i]);
	}
	(free(data->g_x), free(data->g_y));
}

int	ghost_ai(t_inf *data, int *x, int *y, int l)
{
	int	i;

	i = 0;
	coordition(data);
	while (i < l)
	{
		if (data->info._y < y[i])
			g_move_up(data, i);
		if (data->info._x < x[i])
			g_move_left(data, i);
		i++;
	}
	while (i > 0)
	{
		i--;
		if (data->info._y > y[i])
			g_move_down(data, i);
		if (data->info._x > x[i])
			g_move_right(data, i);
	}
	return (0);
}

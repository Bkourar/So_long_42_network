/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gost_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:29 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/25 14:17:40 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	g_move_right(t_inf *d, int i)
{
	coordition_ghost(d);
	if (d->p_[d->g_y[i]][d->g_x[i] + 1] == d->p_[d->info._y][d->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (d->p_[d->g_y[i]][d->g_x[i] + 1] == '0')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = '0';
		d->p_[d->g_y[i]][d->g_x[i] + 1] = 'G';
		draw_it(d, 4);
		draw_floor(d, d->g_x[i], d->g_y[i]);
	}
	else if (d->p_[d->g_y[i]][d->g_x[i] + 1] == 'C')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = 'C';
		d->p_[d->g_y[i]][d->g_x[i] + 1] = 'G';
		draw_it(d, 4);
		draw_floor(d, d->g_x[i], d->g_y[i]);
		draw_coll(d, d->g_x[i], d->g_y[i]);
	}
	free(d->g_x);
	free(d->g_y);
}

static void	g_move_left(t_inf *d, int i)
{
	coordition_ghost(d);
	if (d->p_[d->g_y[i]][d->g_x[i] - 1] == d->p_[d->info._y][d->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (d->p_[d->g_y[i]][d->g_x[i] - 1] == '0')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = '0';
		d->p_[d->g_y[i]][d->g_x[i] - 1] = 'G';
		draw_it(d, 3);
		draw_floor(d, d->g_x[i], d->g_y[i]);
	}
	else if (d->p_[d->g_y[i]][d->g_x[i] - 1] == 'C')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = 'C';
		d->p_[d->g_y[i]][d->g_x[i] - 1] = 'G';
		draw_it(d, 3);
		draw_floor(d, d->g_x[i], d->g_y[i]);
		draw_coll(d, d->g_x[i], d->g_y[i]);
	}
	free(d->g_x);
	free(d->g_y);
}

static void	g_move_up(t_inf *d, int i)
{
	coordition_ghost(d);
	if (d->p_[d->g_y[i] - 1][d->g_x[i]] == d->p_[d->info._y][d->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (d->p_[d->g_y[i] - 1][d->g_x[i]] == '0')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = '0';
		d->p_[d->g_y[i] - 1][d->g_x[i]] = 'G';
		draw_it(d, 1);
		draw_floor(d, d->g_x[i], d->g_y[i]);
	}
	else if (d->p_[d->g_y[i] - 1][d->g_x[i]] == 'C')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = 'C';
		d->p_[d->g_y[i] - 1][d->g_x[i]] = 'G';
		draw_it(d, 1);
		draw_floor(d, d->g_x[i], d->g_y[i]);
		draw_coll(d, d->g_x[i], d->g_y[i]);
	}
	free(d->g_x);
	free(d->g_y);
}

static void	g_move_down(t_inf *d, int i)
{
	coordition_ghost(d);
	if (d->p_[d->g_y[i] + 1][d->g_x[i]] == d->p_[d->info._y][d->info._x])
		(write(1, "GAME OVER\n", 11), exit(0));
	if (d->p_[d->g_y[i] + 1][d->g_x[i]] == '0')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = '0';
		d->p_[d->g_y[i] + 1][d->g_x[i]] = 'G';
		draw_it(d, 2);
		draw_floor(d, d->g_x[i], d->g_y[i]);
	}
	else if (d->p_[d->g_y[i] + 1][d->g_x[i]] == 'C')
	{
		d->p_[d->g_y[i]][d->g_x[i]] = 'C';
		d->p_[d->g_y[i] + 1][d->g_x[i]] = 'G';
		(draw_it(d, 2), draw_floor(d, d->g_x[i], d->g_y[i]));
		draw_coll(d, d->g_x[i], d->g_y[i]);
	}
	(free(d->g_x), free(d->g_y));
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

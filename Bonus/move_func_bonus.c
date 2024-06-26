/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:49:50 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/25 14:44:50 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_all(t_inf *f, int y, int x)
{
	f->p_[f->info._y][f->info._x] = 48;
	f->p_[y][x] = 'P';
	draw_player(f, x, y);
	draw_floor(f, f->info._x, f->info._y);
	put_scorce(f);
}

void	move_up(t_cor *_p, t_inf *f)
{
	if (f->p_[_p->_y - 1][_p->_x] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y - 1][_p->_x] == 69 && f->info.nb_cool == 0)
		(put_scorce(f), write(1, "you win\n", 9), exit (0));
	else if (f->p_[_p->_y - 1][_p->_x] == 69)
		draw_all(f, _p->_y - 1, _p->_x);
	else if (f->p_[_p->_y - 1][_p->_x] != 49)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y - 1][_p->_x] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		if (f->p_[_p->_y][_p->_x] == f->p_[_p->e_y][_p->e_x])
		{
			f->p_[_p->_y][_p->_x] = 69;
			f->p_[_p->_y - 1][_p->_x] = 80;
			draw_player(f, _p->_x, _p->_y - 1);
			(draw_exit(f, _p->_x, _p->_y), put_scorce(f));
		}
		else
			draw_all(f, _p->_y - 1, _p->_x);
	}
}

void	down_up(t_cor *_p, t_inf *f)
{
	if (f->p_[_p->_y + 1][_p->_x] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y + 1][_p->_x] == 69 && f->info.nb_cool == 0)
		(put_scorce(f), write(1, "you win\n", 9), exit(0));
	else if (f->p_[_p->_y + 1][_p->_x] == 69)
		draw_all(f, _p->_y + 1, _p->_x);
	else if (f->p_[_p->_y + 1][_p->_x] != 49)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y + 1][_p->_x] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		if (f->p_[_p->_y][_p->_x] == f->p_[_p->e_y][_p->e_x])
		{
			f->p_[_p->_y][_p->_x] = 69;
			f->p_[_p->_y + 1][_p->_x] = 80;
			draw_player(f, _p->_x, _p->_y + 1);
			(draw_exit(f, _p->_x, _p->_y), put_scorce(f));
		}
		else
			draw_all(f, _p->_y + 1, _p->_x);
	}
}

void	right_up(t_cor *_p, t_inf *f)
{
	if (f->p_[_p->_y][_p->_x + 1] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y][_p->_x + 1] == 69 && f->info.nb_cool == 0)
		(put_scorce(f), write(1, "you win\n", 9), exit (0));
	else if (f->p_[_p->_y][_p->_x + 1] == 69)
		draw_all(f, _p->_y, _p->_x + 1);
	else if (f->p_[_p->_y][_p->_x + 1] != 49)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y][_p->_x + 1] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		if (f->p_[_p->_y][_p->_x] == f->p_[_p->e_y][_p->e_x])
		{
			f->p_[_p->_y][_p->_x] = 69;
			f->p_[_p->_y][_p->_x + 1] = 80;
			draw_player(f, _p->_x + 1, _p->_y);
			(draw_exit(f, _p->_x, _p->_y), put_scorce(f));
		}
		else
			draw_all(f, _p->_y, _p->_x + 1);
	}
}

void	left_up(t_cor *_p, t_inf *f)
{
	if (f->p_[_p->_y][_p->_x - 1] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y][_p->_x - 1] == 69 && f->info.nb_cool == 0)
		(put_scorce(f), write(1, "you win", 9), exit(0));
	else if (f->p_[_p->_y][_p->_x - 1] == 69)
		draw_all(f, _p->_y, _p->_x - 1);
	else if (f->p_[_p->_y][_p->_x - 1] != 49)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y][_p->_x - 1] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		if (f->p_[_p->_y][_p->_x] == f->p_[_p->e_y][_p->e_x])
		{
			f->p_[_p->_y][_p->_x] = 69;
			f->p_[_p->_y][_p->_x - 1] = 80;
			draw_player(f, _p->_x - 1, _p->_y);
			(draw_exit(f, _p->_x, _p->_y), put_scorce(f));
		}
		else
			draw_all(f, _p->_y, _p->_x - 1);
	}
}

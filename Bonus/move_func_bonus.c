/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:49:50 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 17:29:17 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_cor *_p, t_inf *f)
{
	
	if (f->p_[_p->_y - 1][_p->_x] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y - 1][_p->_x] == 69 && f->info.nb_cool == 0)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		(write(1, "you wine\n", 10), exit (0));
	}
	else if (f->p_[_p->_y - 1][_p->_x] != 49 && f->p_[_p->_y - 1][_p->_x] != 69)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y - 1][_p->_x] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		f->p_[_p->_y][_p->_x] = 48;
		f->p_[_p->_y - 1][_p->_x] = 'P';
		draw_player(f, _p->_x, _p->_y - 1);
		draw_floor(f, _p->_x, _p->_y);
		_p->nb_move++;
		put_scorce(f);
	}
}

void	down_up(t_cor *_p, t_inf *f)
{
	
	if (f->p_[_p->_y - 1][_p->_x] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y + 1][_p->_x] == 69 && f->info.nb_cool == 0)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		(write(1, "you wine\n", 10), exit(0));
	}
	else if (f->p_[_p->_y + 1][_p->_x] != 49 && f->p_[_p->_y + 1][_p->_x] != 69)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y + 1][_p->_x] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		f->p_[_p->_y][_p->_x] = 48;
		f->p_[_p->_y + 1][_p->_x] = 'P';
		draw_player(f, _p->_x, _p->_y + 1);
		draw_floor(f, _p->_x, _p->_y);
		_p->nb_move++;
		put_scorce(f);
	}
}

void	right_up(t_cor *_p, t_inf *f)
{
	
	if (f->p_[_p->_y - 1][_p->_x] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y][_p->_x + 1] == 69 && f->info.nb_cool == 0)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		(write(1, "you wine\n", 10), exit (0));
	}
	else if (f->p_[_p->_y][_p->_x + 1] != 49 && f->p_[_p->_y][_p->_x + 1] != 69)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y][_p->_x + 1] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		f->p_[_p->_y][_p->_x] = 48;
		f->p_[_p->_y][_p->_x + 1] = 'P';
		draw_player(f, _p->_x + 1, _p->_y);
		draw_floor(f, _p->_x, _p->_y);
		_p->nb_move++;
		put_scorce(f);
	}
}

void	left_up(t_cor *_p, t_inf *f)
{
	if (f->p_[_p->_y - 1][_p->_x] == 71)
		(write(1, "GAME OVER\n", 11), exit(0));
	if (f->p_[_p->_y][_p->_x - 1] == 69 && f->info.nb_cool == 0)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		(write(1, "you wine\n", 10), exit(0));
	}
	else if (f->p_[_p->_y][_p->_x - 1] != 49 && f->p_[_p->_y][_p->_x - 1] != 69)
	{
		if (f->coll_found == 1)
			f->coll_found = 0;
		if (f->p_[_p->_y][_p->_x - 1] == 67 && _p->nb_cool >= 0)
		{
			_p->nb_cool--;
			f->coll_found = 1;
		}
		f->p_[_p->_y][_p->_x] = 48;
		f->p_[_p->_y][_p->_x - 1] = 'P';
		_p->nb_move++;
		draw_player(f, _p->_x - 1, _p->_y);
		draw_floor(f, _p->_x, _p->_y);
		_p->nb_move++;
		put_scorce(f);
	}
}
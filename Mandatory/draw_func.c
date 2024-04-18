/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:49:47 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 06:01:39 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_inf *dr)
{
	int	i;
	int	j;

	i = -1;
	while (dr->p_[++i])
	{
		j = 0;
		while (dr->p_[i][j])
		{
			if (dr->p_[i][j] == '0')
				draw_floor(dr, j, i);
			if (dr->p_[i][j] == '1')
				draw_wall(dr, j, i);
			if (dr->p_[i][j] == 'C')
				draw_coll(dr, j, i);
			if (dr->p_[i][j] == 'E')
				draw_exit(dr, j, i);
			if (dr->p_[i][j] == 'P')
				draw_player(dr, j, i);
			j++;
		}
	}
}

int	fun(int key, t_inf *data)
{
	data->key = key;
	coordition(data, &data->info);
	if (key == 1 || key == 125)
		down_up(&data->info, data);
	else if (key == 0 || key == 123)
		left_up(&data->info, data);
	else if (key == 13 || key == 126)
		move_up(&data->info, data);
	else if (key == 2 || key == 124)
		right_up(&data->info, data);
	else if (key == 53)
		(write(1, "Exit so_long\n", 14), exit (0));
	return (0);
}

int	mouse_hook(t_inf *map)
{
	(void)map;
	(write(1, "Exit so_long By mouse\n", 23), exit (0));
}

void	open_win(t_inf *fo)
{
	fo->m = mlx_init();
	if (!fo->m)
		return ;
	fo->wi = mlx_new_window(fo->m, fo->x * fo->px, fo->y * fo->px, "so_long");
	draw_map(fo);
	mlx_hook(fo->wi, 2, 1L << 0, fun, fo);
	mlx_hook(fo->wi, 17, 0, &mouse_hook, fo);
	mlx_loop(fo->m);
	mlx_destroy_window(fo->m, fo->wi);
}

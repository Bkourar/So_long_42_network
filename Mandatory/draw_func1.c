/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:08:25 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/15 11:54:21 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_inf *d, int x, int y)
{
	d->wall = mlx_xpm_file_to_image(d->m, WALL, &d->px, &d->px);
	if (!d->wall)
		(write(2, "mlx is fail", 12), exit (1));
	mlx_put_image_to_window(d->m, d->wi, d->wall, x * d->px, y * d->px);
}

void	draw_floor(t_inf *d, int x, int y)
{
	d->floor = mlx_xpm_file_to_image(d->m, FLOOR, &d->px, &d->px);
	if (!d->floor)
		(write(2, "mlx is fail", 12), exit (1));
	mlx_put_image_to_window(d->m, d->wi, d->floor, x * d->px, y * d->px);
}

void	draw_coll(t_inf *d, int x, int y)
{
	d->coll = mlx_xpm_file_to_image(d->m, COLL, &d->px, &d->px);
	if (!d->coll)
		(write(2, "mlx is fail", 12), exit (1));
	mlx_put_image_to_window(d->m, d->wi, d->coll, x * d->px, y * d->px);
}

void	draw_player(t_inf *d, int x, int y)
{
	if (d->key == -1)
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN, &d->px, &d->px);
	else if ((d->key == 1 || d->key == 125) && d->coll_found)
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_OD, &d->px, &d->px);
	else if ((d->key == 0 || d->key == 123) && d->coll_found)
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_OL, &d->px, &d->px);
	else if ((d->key == 13 || d->key == 126) && d->coll_found)
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_OU, &d->px, &d->px);
	else if ((d->key == 2 || d->key == 124) && d->coll_found)
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_OR, &d->px, &d->px);
	else if ((d->key == 1 || d->key == 125))
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_SD, &d->px, &d->px);
	else if ((d->key == 0 || d->key == 123))
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_SL, &d->px, &d->px);
	else if ((d->key == 13 || d->key == 126))
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_SU, &d->px, &d->px);
	else if ((d->key == 2 || d->key == 124))
		d->pac_man = mlx_xpm_file_to_image(d->m, PACMAN_SR, &d->px, &d->px);
	if (!d->pac_man)
		(write(2, "mlx is fail", 12), exit (1));
	mlx_put_image_to_window(d->m, d->wi, d->pac_man, x * d->px, y * d->px);
	d->key = -1;
}

void	draw_exit(t_inf *d, int x, int y)
{
	d->door = mlx_xpm_file_to_image(d->m, DOOR_CL, &d->px, &d->px);
	if (!d->door)
		(write(2, "mlx is fail", 12), exit (1));
	mlx_put_image_to_window(d->m, d->wi, d->door, x * d->px, y * d->px);
}

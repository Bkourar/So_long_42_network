/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:30 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 17:05:47 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_inf *d, int x, int y)
{
	mlx_put_image_to_window(d->m, d->wi, d->ghost, x * d->px, y * d->px);
}

static void	draw_image(t_inf *d)
{
	int			y;
	int			x;

	y = -1;
	while (d->p_[++y] != NULL)
	{
		x = -1;
		while (d->p_[y][++x] != '\0')
		{
			if (d->p_[y][x] == 'G')
				put_image(d, x, y);
		}
	}
}

void	draw_it(t_inf *d, int sens)
{
	static int	mov;

	if (sens == 1 && mov % 2 != 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_U1, &d->px, &d->px);
	else if (sens == 1 && mov % 2 == 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_U2, &d->px, &d->px);
	if (sens == 2 && mov % 2 != 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_D1, &d->px, &d->px);
	else if (sens == 2 && mov % 2 == 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_D2, &d->px, &d->px);
	if (sens == 3 && mov % 2 != 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_L1, &d->px, &d->px);
	else if (sens == 3 && mov % 2 == 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_L2, &d->px, &d->px);
	if (sens == 4 && mov % 2 != 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_R1, &d->px, &d->px);
	else if (sens == 4 && mov % 2 == 0)
		d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_R2, &d->px, &d->px);
	if (d->ghost == NULL)
		exit(1);
	mov++;
	draw_image(d);
}

int	ghost_a(t_inf *data)
{
	int			*x;
	int			*y;
	int			l;
	static int	j;

	l = count_nb_ghost(data);
	if (j == 5000)
	{
		coordition_ghost(data);
		x = data->g_x;
		y = data->g_y;
		ghost_ai(data, x, y, l);
		free(x);
		free(y);
		j = 0;
	}
	j++;
	return (0);
}

void	draw_ghost(t_inf *d, int x, int y)
{
	d->ghost = mlx_xpm_file_to_image(d->m, GHOST_G_D1, &d->px, &d->px);
	if (!d->ghost)
		(write(2, "mlx is fail", 12), exit (1));
	mlx_put_image_to_window(d->m, d->wi, d->ghost, x * d->px, y * d->px);
}

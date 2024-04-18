/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:43:15 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/18 16:19:29 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define WALL "./Fond/Walls/wall.xpm"
# define FLOOR "./Fond/Walls/floor_black.xpm"
# define DOOR_CL "./Fond/Walls/Door.xpm"
# define COLL "./Fond/Collectible/pacdot_food.xpm"
# define PACMAN "./Fond/Pacman/pac_closed.xpm"
# define PACMAN_SL "./Fond/Pacman/pac_semi_left.xpm"
# define PACMAN_OL "./Fond/Pacman/pac_open_left.xpm"
# define PACMAN_SR "./Fond/Pacman/pac_semi_right.xpm"
# define PACMAN_OR "./Fond/Pacman/pac_open_right.xpm"
# define PACMAN_SU "./Fond/Pacman/pac_semi_up.xpm"
# define PACMAN_OU "./Fond/Pacman/pac_open_up.xpm"
# define PACMAN_SD "./Fond/Pacman/pac_semi_down.xpm"
# define PACMAN_OD "./Fond/Pacman/pac_open_down.xpm"
# define GHOST_G_D1 "./Fond/Ghost/G/ghost_down_1.xpm"
# define GHOST_G_D2 "./Fond/Ghost/G/ghost_down_2.xpm"
# define GHOST_G_L1 "./Fond/Ghost/G/ghost_left_1.xpm"
# define GHOST_G_L2 "./Fond/Ghost/G/ghost_left_2.xpm"
# define GHOST_G_R1 "./Fond/Ghost/G/ghost_right_1.xpm"
# define GHOST_G_R2 "./Fond/Ghost/G/ghost_right_2.xpm"
# define GHOST_G_U1 "./Fond/Ghost/G/ghost_up_1.xpm"
# define GHOST_G_U2 "./Fond/Ghost/G/ghost_up_2.xpm"
# define GHOST_Y_D1 "./Fond/Ghost/Y/ghost_down_1.xpm"
# define GHOST_Y_D2 "./Fond/Ghost/Y/ghost_down_2.xpm"
# define GHOST_Y_L1 "./Fond/Ghost/Y/ghost_left_1.xpm"
# define GHOST_Y_L2 "./Fond/Ghost/Y/ghost_left_2.xpm"
# define GHOST_Y_R1 "./Fond/Ghost/Y/ghost_right_1.xpm"
# define GHOST_Y_R2 "./Fond/Ghost/Y/ghost_right_2.xpm"
# define GHOST_Y_U1 "./Fond/Ghost/Y/ghost_up_1.xpm"
# define GHOST_Y_U2 "./Fond/Ghost/Y/ghost_up_2.xpm"
# define GHOST_B_D1 "./Fond/Ghost/B/ghost_down_1.xpm"
# define GHOST_B_D2 "./Fond/Ghost/B/ghost_down_2.xpm"
# define GHOST_B_L1 "./Fond/Ghost/B/ghost_left_1.xpm"
# define GHOST_B_L2 "./Fond/Ghost/B/ghost_left_2.xpm"
# define GHOST_B_R1 "./Fond/Ghost/B/ghost_right_1.xpm"
# define GHOST_B_R2 "./Fond/Ghost/B/ghost_right_2.xpm"
# define GHOST_B_U1 "./Fond/Ghost/B/ghost_up_1.xpm"
# define GHOST_B_U2 "./Fond/Ghost/B/ghost_up_2.xpm"
# define GHOST_R_D1 "./Fond/Ghost/R/ghost_down_1.xpm"
# define GHOST_R_D2 "./Fond/Ghost/R/ghost_down_2.xpm"
# define GHOST_R_L1 "./Fond/Ghost/R/ghost_left_1.xpm"
# define GHOST_R_L2 "./Fond/Ghost/R/ghost_left_2.xpm"
# define GHOST_R_R1 "./Fond/Ghost/R/ghost_right_1.xpm"
# define GHOST_R_R2 "./Fond/Ghost/R/ghost_right_2.xpm"
# define GHOST_R_U1 "./Fond/Ghost/R/ghost_up_1.xpm"
# define GHOST_R_U2 "./Fond/Ghost/R/ghost_up_2.xpm"
# define LOGO "./Fond/logo/logo.xpm"
typedef struct coordition
{
	int	nb_cool;
	int	nb_move;
	int	nb_ghost;
	int	_x;
	int	_y;
}	t_cor;
typedef struct information
{
	int		px;
	int		x;
	int		y;
	int		coll_found;
	int		key;
	int		*g_x;
	int		*g_y;
	char	**p_;
	void	*m;
	void	*wi;
	void	*wall;
	void	*floor;
	void	*pac_man;
	void	*coll;
	void	*door;
	void	*ghost;
	void	*logo;
	t_cor	info;
}			t_inf;
t_inf	creat_data(char **map_gm, int axe_y);
size_t	ft_strlen(const char *theString);
char	*f_strjoin(char *str1, char *str2, int line_b);
char	*free_line(char *back_buf);
char	*start(char *arr, int fd);
char	*get_next_line(int fd);
char	*by_line(char *str);
char	*f_insial(void);
char	*ft_strdup(char const *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_rules1(int db, int coll, char **ar, int size);
int		comparison(char const *s1, char const *s2);
int		count_word(char const *string, char c);
int		check_rules(char **ar, int size);
int		check_nl(char const *str);
int		check_element(char **_ar);
int		check_map(char **a_v);
int		fun(int key, t_inf *data);
void	draw_wall(t_inf *d, int x, int y);
void	draw_floor(t_inf *d, int x, int y);
void	draw_coll(t_inf *d, int x, int y);
void	draw_player(t_inf *d, int x, int y);
void	draw_exit(t_inf *d, int x, int y);
void	move_up(t_cor *pos, t_inf *f);
void	down_up(t_cor *pos, t_inf *f);
void	right_up(t_cor *pos, t_inf *f);
void	left_up(t_cor *pos, t_inf *f);
void	coordition(t_inf *d);
void	flood_fil(char **map, int x, int y);
void	free_ary(char **argement);
void	open_win(t_inf *fo);
void	draw_map(t_inf *dr);
void	coordition_ghost(t_inf *d);
void	coordition_1(char **arg_v, t_cor *pos);
int		count_nb_ghost(t_inf *info);
int		ft_strcmp(char	const *s1, char const *s2);
void	ft_putchar(char *str);
char	*ft_itoa(int n);
void	draw_it(t_inf *d, int sens);
void	draw_ghost(t_inf *data, int x, int y);
int		ghost_a(t_inf *data);
int		ghost_ai(t_inf *data, int *x, int *y, int l);
void	put_scorce(t_inf *f);
char	*ft_putstr(char *str);
#endif
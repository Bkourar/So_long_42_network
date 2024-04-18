/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:43:15 by bikourar          #+#    #+#             */
/*   Updated: 2024/04/17 22:21:32 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct coordition
{
	int	nb_cool;
	int	nb_move;
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
	char	**p_;
	void	*m;
	void	*wi;
	void	*wall;
	void	*floor;
	void	*pac_man;
	void	*coll;
	void	*door;
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
void	coordition(t_inf *d, t_cor *pos);
void	flood_fil(char **map, int x, int y);
void	free_ary(char **argement);
void	open_win(t_inf *fo);
void	draw_map(t_inf *dr);
int		ft_strcmp(char	const *s1, char const *s2);
void	ft_putchar(char *str);
char	*ft_itoa(int n);
void	coordition_1(char **arg_v, t_cor *pos);
#endif
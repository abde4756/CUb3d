#ifndef CUB3_H
# define CUB3_H

# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_render
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		ceiling_color;
	int		floor_color;
	int		tex_x;
	double	step;
	double	tex_pos;
}			t_render;

typedef struct s_color
{
	int		floor[3];
	int		ceiling[3];
}			t_color;

typedef struct s_textr
{
	void	*imag;
	char	*adrs;
	int		width_txtr;
	int		height_txtr;
	int		bit_pxl;
	int		octe_ligne;
	int		andian;
}			t_textr;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_game;

typedef struct s_file
{
	t_color	color;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		count_map_lines;
	char	*gard_first_line_map;
	char	**map;
}			t_file;

typedef struct s_map
{
	t_game	*game;
	int		height;
	int		length;

	int		screen_width;
	int		screen_height;

	// l'information player
	double	y_player;
	double	x_player;
	double	dir_angle;
	char	direction;
	int		fov;
	t_file	*file;
	t_textr	textur[4];
}			t_map;

typedef struct s_dda
{
	double	ray_angle;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_dda;

int			validate_name_file(char *filename);
char		**ft_split(const char *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *s);
void		free_array(char **array);
/* Parsing functions */
int         verify_last_line(t_file *file);
int			add_color_info(t_file *file);
int			elemnt_check(t_file *file, t_map *map_info);
int			check_line_elements(char *line, int i, t_map *map_info,
				int *player_count);
int			validate_name_file(char *filename);
int			chech_space(char *str);
int			check_newlign(char *str);
int			add_line_to_file(char *line, t_file *file);
/* window creation - declared after t_file/t_map typedefs */
int			creat_window(t_file *file, t_map *map);
void		add_line_to_map(t_file *file);
void		free_array(char **array);

// raycasting
void		init_dda(t_map *map, t_dda *dda);
int			chech_space(char *str);
int			test_line(char **lines);
int			verify_map(t_file *file, t_map *map_info);
int			raycasting_loop(t_map *map, t_file *file);
void		put_pixel(t_map *map, int x, int y, int color);
// void		render_column(int x, int line_height, t_map *map, t_dda *dda);
// graphic
void		render_column_textured(int x, t_map *map, t_dda *dda, t_textr *tex);
void		move_forward_backward(t_map *map, t_file *file, double speed);
void		strafe(t_map *map, t_file *file, double speed);
void		rotate_player(t_map *map, double angle);
void		update_player_direction(t_map *map, double angle);
void		move_player(t_map *map, t_file *file, double speed);
int			handle_key(int key, t_map *map);
int			close_wind(t_map *map);
void		clear_image(t_map *map);
void		cleanup(t_map *map);
void		cleanup_and_exit(t_map *map);
// patie graphic textures
void		load_texture(t_map *map, int idx, char *path);
int			calcul_position_texture(t_dda *dda, t_map *map, t_textr *tex);
int			select_texture(t_dda *dda);
void		render_column_textured(int x, t_map *map, t_dda *dda, t_textr *tex);

#endif
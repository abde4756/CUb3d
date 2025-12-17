#include "cub3.h"

void	load_texture(t_map *map, int idx, char *path)
{
	map->textur[idx].imag = mlx_xpm_file_to_image(map->game->mlx, path,
			&map->textur[idx].width_txtr, &map->textur[idx].height_txtr);
	if (!map->textur[idx].imag)
	{
		printf("Erreur: cannot load texture %s\n", path);
		exit(1);
	}
	map->textur[idx].adrs = mlx_get_data_addr(map->textur[idx].imag,
			&map->textur[idx].bit_pxl, &map->textur[idx].octe_ligne,
			&map->textur[idx].andian);
	if (!map->textur[idx].adrs)
	{
		printf("Erreur: cannot get data addr %s\n", path);
		exit(1);
	}
}

int	select_texture(t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->ray_dir_x > 0)
			return (3);
		else if (dda->ray_dir_x < 0)
			return (2);
	}
	else
	{
		if (dda->ray_dir_y > 0)
			return (1);
		else if (dda->ray_dir_y < 0)
			return (0);
	}
	return (-1);
}

int	calcul_position_texture(t_dda *dda, t_map *map, t_textr *tex)
{
	double	wall_x;
	int		tex_x;

	if (dda->side == 0)
		wall_x = map->y_player + dda->perp_wall_dist * dda->ray_dir_y;
	else
		wall_x = map->x_player + dda->perp_wall_dist * dda->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width_txtr);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		tex_x = tex->width_txtr - tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		tex_x = tex->width_txtr - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width_txtr)
		tex_x = tex->width_txtr - 1;
	return (tex_x);
}

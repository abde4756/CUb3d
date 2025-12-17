#include "cub3.h"

int	check_space_in_line(t_file *file, int i)
{
	int	j;

	j = 0;
	while (file->map[i][j] && file->map[i][j] != '\n')
	{
		if (file->map[i][j] == ' ')
		{
			if (j == 0)
			{
				if ((file->map[i + 1][j] != '1' && file->map[i + 1][j] != ' '
						&& file->map[i + 1][j] != '\n' && file->map[i + 1][j])
					|| (file->map[i - 1][j] != '1' && file->map[i - 1][j] != ' '
						&& file->map[i - 1][j] != '\n' && file->map[i - 1][j]))
					return (-1);
			}
			else if ((file->map[i + 1][j - 1] != '1' && file->map[i + 1][j
				- 1] != ' ') || (file->map[i - 1][j - 1] != '1'
				&& file->map[i - 1][j - 1] != ' '))
				return (-1);
		}
		j++;
	}
	return (0);
}

int	verify_side_walls(t_file *file)
{
	int		i;
	char	**test;

	i = 0;
	while (file->map[++i] && i < file->count_map_lines - 1)
	{
		if (chech_space(file->map[i]))
		{
			test = ft_split(file->map[i], ' ');
			if (test_line(test) == -1)
				return (free_array(test), -1);
			free_array(test);
			if (check_space_in_line(file, i) == -1)
				return (-1);
		}
		else
		{
			test = ft_split(file->map[i], ' ');
			if (test_line(test) == -1)
				return (free_array(test), -1);
			free_array(test);
		}
	}
	return (0);
}

static int	check_space_valid(t_file *file, int j)
{
	if (file->map[0][j + 1] == '1' && file->map[1][j + 1] != '1')
		return (-1);
	if (j == 0)
	{
		if (file->map[1][j]
			&& file->map[1][j] != '1'
			&& file->map[1][j] != ' ')
			return (-1);
	}
	else
	{
		if (file->map[1][j]
			&& file->map[1][j] != '1'
			&& file->map[1][j] != ' ')
			return (-1);
		if (file->map[1][j - 1]
			&& file->map[1][j - 1] != '1'
			&& file->map[1][j - 1] != ' ')
			return (-1);
	}
	return (0);
}

/* ========== FONCTION PRINCIPALE ========== */

int	verify_first_line(t_file *file)
{
	int	j;

	j = 0;
	while (file->map[0][j] && file->map[0][j] != '\n')
	{
		if (file->map[0][j] != '1' && file->map[0][j] != ' ')
			return (-1);
		if (file->map[0][j] == ' ')
		{
			if (check_space_valid(file, j) == -1)
				return (-1);
		}
		j++;
	}
	return (0);
}

int	verify_map(t_file *file, t_map *map_info)
{
	if (!file->map || !file->map[0])
		return (-1);
	map_info->height = file->count_map_lines;
	if (file->count_map_lines <= 1)
		return (-1);
	if (verify_first_line(file) == -1)
		return (-1);
	if (verify_side_walls(file) == -1)
		return (-1);
	if (verify_last_line(file) == -1)
		return (-1);
	return (0);
}

#include "cub3.h"

int	elemnt_check(t_file *file, t_map *map_info)
{
	int	i;
	int	player_count;

	i = 1;
	player_count = 0;
	if (!file->map)
		return (-1);
	while (file->map[i] && i < file->count_map_lines - 1)
	{
		if (check_line_elements(file->map[i], i, map_info, &player_count) == -1)
			return (-1);
		i++;
	}
	if (player_count != 1)
		return (-1);
	return (0);
}

int	check_line_elements(char *line, int i, t_map *map_info, int *player_count)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '0' && line[j] != '1' && line[j] != 'N'
			&& line[j] != '\n' && line[j] != 'S' && line[j] != 'E'
			&& line[j] != 'W' && line[j] != ' ')
			return (-1);
		if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E'
			|| line[j] == 'W')
		{
			map_info->x_player = j + 0.5;
			map_info->y_player = i + 0.5;
			map_info->direction = line[j];
			(*player_count)++;
		}
		j++;
	}
	return (0);
}

int	validate_name_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		perror("Invalid file name");
		return (-1);
	}
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u' || filename[len
			- 3] != 'c' || filename[len - 4] != '.')
	{
		perror("Invalid file extension");
		return (-1);
	}
	return (0);
}

int	check_newlign(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == '\n')
			return (2);
	}
	return (1);
}

int	test_line(char **lines)
{
	int	i;
	int	len;
	int	flag;

	if (!lines)
		return (-1);
	i = 0;
	while (lines[i])
	{
		len = ft_strlen(lines[i]);
		flag = check_newlign(lines[i]);
		if (lines[i][0] != '1' || lines[i][len - flag] != '1')
			return (-1);
		i++;
	}
	return (0);
}

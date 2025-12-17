#include "cub3.h"

static int	process_line(t_file *file, char *line, int *i, int *flag)
{
	if (line[0] == '\n' || line[0] == '\0')
	{
		free(line);
		return (1);
	}
	if (ft_strcmp(line, file->gard_first_line_map) == 0)
	{
		file->map[(*i)++] = ft_strdup(line);
		*flag = 1;
		free(line);
		return (1);
	}
	if (*flag == 1 && *i < file->count_map_lines)
		file->map[(*i)++] = ft_strdup(line);
	free(line);
	return (0);
}

void	add_line_to_map(t_file *file)
{
	char	*line;
	int		i;
	int		fd;
	int		flag;

	flag = 0;
	i = 0;
	fd = open("map.cub", O_RDONLY);
	file->map = malloc(sizeof(char *) * (file->count_map_lines + 1));
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(file, line, &i, &flag);
		line = get_next_line(fd);
	}
	file->map[i] = NULL;
	close(fd);
}


static int	parse_color(char *color_str, int *color_array)
{
	char	**rgb;
	int		i;

	rgb = ft_split(color_str, ',');
	if (!rgb)
		return (-1);
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (free_array(rgb), -1);
	color_array[0] = ft_atoi(rgb[0]);
	if (color_array[0] < 0 || color_array[0] > 255)
		return (free_array(rgb), -1);
	color_array[1] = ft_atoi(rgb[1]);
	if (color_array[1] < 0 || color_array[1] > 255)
		return (free_array(rgb), -1);
	color_array[2] = ft_atoi(rgb[2]);
	if (color_array[2] < 0 || color_array[2] > 255)
		return (free_array(rgb), -1);
	free_array(rgb);
	return (0);
}

int	add_color_info(t_file *file)
{
	if (parse_color(file->f, file->color.floor) == -1)
		return (-1);
	if (parse_color(file->c, file->color.ceiling) == -1)
		return (-1);
	return (0);
}
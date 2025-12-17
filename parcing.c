#include "cub3.h"

void	parse_other(char **arg, char *line, t_file *file)
{
	if (ft_strcmp(arg[0], "F") == 0)
		file->f = ft_strdup(arg[1]);
	else if (ft_strcmp(arg[0], "C") == 0)
		file->c = ft_strdup(arg[1]);
	else
	{
		if (file->count_map_lines == 0)
			file->gard_first_line_map = ft_strdup(line);
		file->count_map_lines++;
	}
}

int	check_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

int	parse_texture(char **arg, t_file *file)
{
	if (ft_strcmp(arg[0], "NO") == 0)
		file->no = ft_strdup(arg[1]);
	else if (ft_strcmp(arg[0], "SO") == 0)
		file->so = ft_strdup(arg[1]);
	else if (ft_strcmp(arg[0], "WE") == 0)
		file->we = ft_strdup(arg[1]);
	else if (ft_strcmp(arg[0], "EA") == 0)
		file->ea = ft_strdup(arg[1]);
	else
		return (0);
	return (check_texture_file(arg[1]));
}

int	add_line_to_file(char *line, t_file *file)
{
	int		i;
	char	**arg;

	arg = ft_split(line, ' ');
	i = 0;
	while (arg[i])
		i++;
	if (i > 2)
		return (free_array(arg), -1);
	if (parse_texture(arg, file) == -1)
		return (free_array(arg), -1);
	parse_other(arg, line, file);
	free_array(arg);
	return (0);
}

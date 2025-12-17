#include "cub3.h"

int	chech_space(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == ' ')
			return (1);
	}
	return (0);
}


static int	finalize_parsing(t_file *file, t_map *map, int fd)
{
	if (file->count_map_lines > 0)
		add_line_to_map(file);
	if (verify_map(file, map) == -1)
		return (-1);
	if (elemnt_check(file, map) == -1)
		return (-1);
	add_color_info(file);
	close(fd);
	return (0);
}

int	parcing_map(char *name_file, t_file *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n' && line[0] != '\0')
			add_line_to_file(line, file);
		free(line);
		line = get_next_line(fd);
	}
	return (finalize_parsing(file, map, fd));
}

int	main(int ac, char **av)
{
	t_file	file;
	t_map	map;

	(void)ac;
	file = (t_file){0};
	file.count_map_lines = 0;
	map = (t_map){0};
	if (validate_name_file(av[1]) == -1)
		return (1);
	if (parcing_map(av[1], &file, &map) == -1)
	{
		perror("Error parsing map");
		return (1);
	}
	creat_window(&file, &map);
	return (0);
}

#include "cub3.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	if (!s1 || !s2)
		return (s1 == s2) ? 0 : (s1 ? 1 : -1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	return (int)(c1 - c2);
}

/* ft_strdup and ft_strlen are provided by get_next_line's utils; avoid
   defining them here to prevent multiple definition at link time. */

int	ft_atoi(const char *s)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (int)(result * sign);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* ft_strlen is provided by get_next_line utils; do not redefine here. */

char	*ft_strdup(char *s)
{
	size_t len;
	char *dup;
	size_t i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
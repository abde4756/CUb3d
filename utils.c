#include "cub3.h"

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen((char *)s))
	{
		sub = malloc(1);
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		j;
	int		wlen;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i] && j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		wlen = word_len(s + i, c);
		res[j] = ft_substr(s, i, (size_t)wlen);
		if (!res[j])
		{
			while (j-- > 0)
				free(res[j]);
			free(res);
			return (NULL);
		}
		i += wlen;
		j++;
	}
	res[words] = NULL;
	return (res);
}

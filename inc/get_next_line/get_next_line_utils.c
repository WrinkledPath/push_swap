#include "get_next_line.h"

char	*get_strchr(char *str, int chr)
{
	while (*str && *str != chr)
		str++;
	if (!*str)
		return (NULL);
	return (str);
}

char	*get_substr(const char *buf, size_t left, size_t right)
{
	size_t		i;
	size_t		buf_size;
	char		*tmp_buf;

	buf_size = right - left;
	if (buf_size <= 0)
		return (NULL);
	tmp_buf = (char *)malloc((buf_size + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	i = 0;
	while (i < buf_size && buf[left + i])
	{
		tmp_buf[i] = buf[left + i];
		i++;
	}
	tmp_buf[i] = '\0';
	return (tmp_buf);
}

char	*get_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (get_strdup(s2));
	if (!s2)
		return (get_strdup(s1));
	joined = (char *)malloc(((get_strlen(s1) + get_strlen(s2)) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*get_strdup(const char *s)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	dup = (char *)malloc((get_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	get_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

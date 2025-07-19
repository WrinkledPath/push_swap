/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:32:59 by ywagner           #+#    #+#             */
/*   Updated: 2025/07/19 18:08:03 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void		join_bufs(char *tmp_buf, char **buffer);
static char		*read_file(int fd, char **buffer);
static char		*extract_buf(char **buffer);
static int		has_newline(char *str);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_file(fd, &buffer);
	if (!buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_buf(&buffer);
	return (line);
}

static char	*read_file(int fd, char **buffer)
{
	int		bytes_read;
	char	*tmp_buf;

	tmp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		tmp_buf[bytes_read] = '\0';
		join_bufs(tmp_buf, buffer);
		if (has_newline(*buffer))
			break ;
		bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
	}
	free(tmp_buf);
	if (bytes_read < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (*buffer);
}

static int	has_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*extract_buf(char **buffer)
{
	char	*line;
	char	*leftover;
	int		len;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	len = 0;
	while ((*buffer)[len] && (*buffer)[len] != '\n')
		len++;
	if ((*buffer)[len] == '\n')
		len++;
	line = get_substr(*buffer, 0, len);
	if (!line)
		return (NULL);
	leftover = get_strdup(*buffer + len);
	free(*buffer);
	if (!leftover)
	{
		free(line);
		return (NULL);
	}
	*buffer = leftover;
	return (line);
}

static void	join_bufs(char *tmp_buf, char **buffer)
{
	char	*tmp;

	if (!*buffer)
		*buffer = get_strdup("");
	tmp = get_strjoin(*buffer, tmp_buf);
	free(*buffer);
	*buffer = tmp;
}

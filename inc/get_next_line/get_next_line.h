#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Utils
char	*get_strjoin(char *s1, char *s2);
char	*get_substr(const char *buf, size_t left, size_t right);
char	*get_strdup(const char *s);
size_t	get_strlen(const char *s);
char	*get_strchr(char *str, int chr);
// Get_Next_Line
char	*get_next_line(int fd);

#endif

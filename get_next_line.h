#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define RED "\033[7m\033[31m"
# define DEFFAULT "\033[1m"
# define GREEN "\033[7m\033[32m"
# define YOLLOW "\033[7m\033[33m"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//Simopoza12345@@

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, const char *s2);

#endif

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h> // read, write

char    *get_next_line(int fd);
int has_nl(const char *s);
size_t ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);

#endif
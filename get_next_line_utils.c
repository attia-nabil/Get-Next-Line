#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0); 
    while (s[i])
    {
        i++;
    }
    return (i);
}

int has_nl(const char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while(s[i])
    {
        if (s[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;
    int k;
    char *ptr;

    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }

    i = 0;
    j = 0;
    k = ft_strlen(s2) + ft_strlen(s1);

    ptr = malloc(k + 1);
    if(!ptr)
        return (NULL);
    while(s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        ptr[i + j] = s2[j];
        j++;
    }
    ptr[k] = '\0';
    free(s1);
    return (ptr);
}
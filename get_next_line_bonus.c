/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:51:15 by nattia            #+#    #+#             */
/*   Updated: 2021/12/03 15:07:23 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *ln_dump(char *r)
{
    char    *d;
    int     i;

    if (!r[0])
        return (NULL);
    i = 0;
    while (r[i] && r[i] != '\n')
        i++;
    d = malloc(i + 2);
    if (!d)
        return (NULL);
    i = -1;
    while (r[++i] && r[i] != '\n')
        d[i] = r[i];
    if (r[i] == '\n')
        d[i++] = '\n';
    d[i] = '\0';
    return (d);
}

char    *update_rec(char *r)
{
    char    *u;
    int     i;
    int     j;

    i = 0;
    while (r[i] && r[i] != '\n')
        i++;
    if (!r[i])
    {
        free(r);
        return (NULL);
    }
    u = malloc(ft_strlen(r) - i + 1);
    if (!u)
        return (NULL);
    i++;
    j = 0;
    while (r[i])
        u[j++] = r[i++];
    u[j] = '\0';
    free(r);
    return (u);
}

char    *get_next_line_bonus(int fd)
{
    char        *buf;
    char        *rtn;
    static char *rec;
    int         rdr;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    rdr = 1;
    while (!has_nl(rec) && rdr)
    {
        rdr = read(fd, buf, BUFFER_SIZE);
        if (rdr == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[rdr] = '\0';
        rec = ft_strjoin(rec, buf);
    }
    free(buf);
    rtn = ln_dump(rec);
    rec = update_rec(rec);
    return (rtn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:08:24 by nattia            #+#    #+#             */
/*   Updated: 2021/12/03 15:08:28 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*l_dump(char *s)
{
	char	*d;
	int		i;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	d = (char *)malloc(i + 2);
	i = -1;
	while (s[++i] && s[i] != '\n')
		d[i] = s[i];
	if (s[i] == '\n')
		d[i++] = '\n';
	d[i] = '\0';
	return (d);
}

char	*g_save(char *s)
{
	char	*sv;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!*(s + i))
	{
		free(s);
		return (NULL);
	}
	sv = (char *)malloc(ft_strlen(s) - i + 1);
	if (!sv)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		sv[j++] = s[i++];
	sv[j] = '\0';
	free(s);
	return (sv);
}

int	buf_alloc(char **buf)
{
	*buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*rtn;
	static char	*sv;
	int			rdr;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buf_alloc(&buf))
		return (NULL);
	rdr = 1;
	while (!nl_found(sv) && rdr)
	{
		rdr = read(fd, buf, BUFFER_SIZE);
		if (rdr == -1)
		{
			free(buf);
			return (0);
		}
		buf[rdr] = '\0';
		sv = ft_strjoin(sv, buf);
	}
	free(buf);
	rtn = l_dump(sv);
	sv = g_save(sv);
	return (rtn);
}

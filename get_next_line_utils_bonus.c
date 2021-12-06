/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:59:35 by nattia            #+#    #+#             */
/*   Updated: 2021/12/03 15:02:19 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	nl_found(const char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rtn;
	int		l;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		*s1 = '\0';
	}
	l = ft_strlen(s1) + ft_strlen(s2);
	rtn = (char *)malloc(l + 1);
	if (!rtn)
		return (NULL);
	i = -1;
	while (s1[++i])
		rtn[i] = s1[i];
	j = -1;
	while (i < l)
		rtn[i++] = s2[++j];
	rtn[l] = '\0';
	free(s1);
	return (rtn);
}

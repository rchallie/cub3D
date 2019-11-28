/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:39:20 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 15:40:21 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/cub3d.h"

static char		*join_str(char const *s1, char c)
{
	size_t	s1_len;
	size_t	stot_len;
	char	*rtn;

	if (c == '\n')
	{
		if (s1)
			return (ft_strdup(s1));
		else
		{
			if (!(rtn = malloc(sizeof(char) * 1)))
				return (0);
			rtn[0] = '\0';
			return (rtn);
		}
	}
	s1_len = ft_strlen((char *)s1);
	stot_len = s1_len + 2;
	if (!(rtn = malloc(sizeof(char) * stot_len)))
		return (0);
	ft_memmove(rtn, s1, s1_len);
	rtn[s1_len] = c;
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}

int				get_line(int fd, char **line)
{
	char	buffer;
	int		reader;

	reader = 1;
	buffer = '\0';
	while (buffer != '\n' && reader != 0)
	{
		if ((reader = read(fd, &buffer, 1)) == -1)
			return (-1);
		if (reader != 0)
			*line = join_str(*line, buffer);
	}
	if (reader == 0)
		return (0);
	return (1);
}

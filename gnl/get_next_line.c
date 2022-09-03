/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:35:42 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/11 18:34:51 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!tmp)
		return (NULL);
	j = i + 1;
	while (str[++i])
		tmp[i - j] = str[i];
	tmp[i - j] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	len = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (len && ft_gnl_strchr(stash, '\n') <= 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			break ;
		buffer[len] = '\0';
		stash = ft_gnl_strjoin(stash, buffer, -1, -1);
	}
	line = ft_fill_line(stash);
	stash = ft_get_next(stash);
	return (line);
}

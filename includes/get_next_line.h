/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:36:25 by maparigi          #+#    #+#             */
/*   Updated: 2022/06/12 13:04:27 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

int		ft_gnl_strchr(const char *str, int c);

char	*ft_gnl_strjoin(char *s1, char *s2, int i, int j);
char	*ft_get_next(char *str);
char	*get_next_line(int fd);
char	*ft_fill_line(char *s);

#endif
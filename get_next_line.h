/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:24 by vnascime          #+#    #+#             */
/*   Updated: 2020/03/12 14:39:08 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
char			*ft_substr(char *str, size_t start, size_t len);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strdup(char *str);
void			ft_strdel(char **todel);

#endif

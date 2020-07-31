/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:43:55 by vnascime          #+#    #+#             */
/*   Updated: 2020/03/14 17:23:51 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//This function is responsible for copying our wanted memory
//We search for the \n or EOF in *s and attribute this memory to **line.
//We then give the excess memory to tmp whose address we will assign to *s.

static int		append_line(char **s, char **line)
{
	size_t		len;
	char		*tmp;

	len = 0;
	while ((*s)[len] != 0 && (*s)[len] != '\n')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == 0)
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

//This function helps output our return value. 0 when we finish reading
//-1 for errors and 1 if we perform append_line fully.

static int		output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
	{
		*line = (char *)malloc(1 * sizeof(char));
		*line[0] = 0;
		return (0);
	}
	else
		return (append_line(&s[fd], line));
}

//We dynamically allocate our static array using OPEN_MAX
// and statically allocate our BufferSize dealing with high buffers
//While we are reading we will initialize s[fd] and join it with buff until
//we find \n

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char	*s[OPEN_MAX];
	char		*buff;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (buff)
		free(buff);
	return (output(s, line, ret, fd));
}

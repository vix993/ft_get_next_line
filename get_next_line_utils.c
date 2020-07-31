/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:26:38 by vnascime          #+#    #+#             */
/*   Updated: 2020/03/11 16:50:12 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	size_t		len1;
	size_t		len2;
	char		*new;

	i = 0;
	j = 0;
	len1 = 0;
	len2 = 0;
	while (str1[len1] != 0)
		len1++;
	while (str2[len2] != 0)
		len2++;
	if (NULL == (new = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	while (str1[i] != 0)
	{
		new[i] = str1[i];
		i++;
	}
	while (str2[j] != 0)
		new[i++] = str2[j++];
	new[i] = 0;
	return (new);
}

void	ft_strdel(char **todel)
{
	if (todel)
	{
		free(*todel);
		*todel = NULL;
	}
	return ;
}

char	*ft_strdup(char *str)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[len] != 0)
		len++;
	if (NULL == (new = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (str[i] != 0)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = start;
	if (!str || len <= 0 || start >= len)
		return (ft_strdup(""));
	if (NULL == (new = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (len == 0)
		return (new);
	while (i < len && str[i] != 0)
	{
		new[i] = str[j];
		j++;
		i++;
	}
	new[i] = 0;
	return (new);
}

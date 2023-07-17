/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:32:21 by chugot            #+#    #+#             */
/*   Updated: 2023/05/02 13:32:22 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	if (!str)
		return (NULL);
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
		return ((char *)&str[i]);
	else
		return (NULL);
}

char	*ft_strchr_x(const char *str, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	if (!str)
		return (NULL);
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
		return (i);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	length;
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	length = ft_strlen(s1) + ft_strlen(s2);
	new = (char *) malloc(sizeof(char) * length + 1);
	if (!new)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free (s1);
	return (new);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

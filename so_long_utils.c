/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:32:21 by chugot            #+#    #+#             */
/*   Updated: 2023/07/08 20:03:20 by clara            ###   ########.fr       */
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

int	ft_strchr_x(const char *str, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	if (!str)
		exit (0);
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
		return (i);
	else
		exit (0);
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

size_t	ft_strcmp(char *s1, char * s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_itoa2(int n, char *str, int len)
{
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		temp;
	char	*str;

	temp = n;
	len = 1;
	str = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (temp < 0)
	{
		temp = temp * -1;
		len++;
	}
	while (temp > 9)
	{
		temp = temp / 10;
		len++;
	}
	return (ft_itoa2(n, str, len));
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		lenght;

	lenght = ft_strlen((char *)s);
	if (s == 0)
		return (NULL);
	copy = (char *) malloc(sizeof(char) * (lenght + 1));
	if (copy != NULL)
		ft_memcpy(copy, s, lenght + 1);
	return (copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destbis;
	char	*srcbis;

	srcbis = (char *)src;
	destbis = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		destbis[i] = srcbis[i];
		i++;
	}
	return (dest);
}
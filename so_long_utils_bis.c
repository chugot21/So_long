/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:59:40 by chugot            #+#    #+#             */
/*   Updated: 2023/07/21 15:59:41 by chugot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (int *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, (nmemb * size));
	return (ptr);
}

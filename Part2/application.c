/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorriga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:59:54 by mmorriga          #+#    #+#             */
/*   Updated: 2022/02/24 15:19:53 by mmorriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

/* function below checks if c is a decimal alphabet character or not */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

/* The function below does stuff */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		i2;
	int		i3;

	if (s1 || s2)
	{
		res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		i = 0;
		i2 = 0;
		i3 = 0;
		while (s1[i2])
			res[i++] = s1[i2++];
		while (s2[i3])
			res[i++] = s2[i3++];
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

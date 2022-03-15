/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorriga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:16:07 by mmorriga          #+#    #+#             */
/*   Updated: 2022/03/15 12:29:08 by mmorriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <strings.h>
#include "libft.h"

int	main(void)
{
	char	*name;
	char	*str;
	FILE	*file;
	int		i;

	name = malloc(sizeof(*name) * sizeof(char));
	printf("Input your username: ");
	scanf("%s", name);
	str = ft_strjoin("Welcome to FDS - ", name);
	file = fopen("consolelog.txt", "a");
	fprintf(file, "User Input: %s\nUser Output: %s\n", name, name);
	i = 0;
	while (ft_isalpha(*name++) == 0)
		i++;
	if (i > 1)
	{
		fprintf(file, "[Error 1]\n");
		printf("Input is not valid, please only use alphabetical characters\n");
		fprintf(file, "Error: str was NULL\n");
		fprintf(file, "incorrect input (non-alphabetical) or not enough mem\n");
		return (1);
	}
	else
		printf("%s", str);
	return (0);
}

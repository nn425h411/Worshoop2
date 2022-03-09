/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorriga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:16:07 by mmorriga          #+#    #+#             */
/*   Updated: 2022/03/09 14:41:48 by mmorriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

int		ft_isalpha(int c);

/* Please change toggle to 1 for full company name,
 *  0 for abbreviated then recompile*/
static char	*toggle(int toggle)
{
	FILE	*file;
	char	*temp;
	char	*str2;

	temp = 0;
	file = fopen("consolelog.txt", "a");
	if (toggle == 1)
		str2 = "Welcome to Fancy Development Services - ";
	if (toggle == 0)
		str2 = "Welcome to FDS - ";
	if (str2 > temp)
		return (str2);
	else
	{
		fprintf(file, "Toggle was invalid (insert 1 or 0)\n");
		printf("Toggle invalid, please insert 1 or 0");
	}
	return (NULL);
}

/* Handles errors, outputs logs and help */
int	error_handle(int e, FILE *file, char *name, char *str)
{
	while (ft_isalpha(*name++) == 0)
        e++;
	if (e > 1)
	{
		fprintf(file, "[Error 1]\n");
		printf("Input is not valid, please only use alphabetical characters\n");
		fprintf(file, "Error: string was NULL\n");
		fprintf(file, "incorrect input (non-alphabetical) or not enough mem\n");
		return (1);
	}
	if (str == NULL)
	{
		fprintf(file, "[Error 2]\n");
		printf(", please input your name\n");
		fprintf(file, "Error: string was NULL\n");
		fprintf(file, "no user input\n");
		return (2);
	}
	else
		return (0);
}
/* change str = toggle(1 or 0) 0 for abbreviation, 1 for full company name */
int	main(void)
{
	char	*name;
	char	*str;
	FILE	*file;
	int		i;

	name = malloc(sizeof(*name) * sizeof(char));
	printf("Input your username: ");
	scanf("%s", name);
	str = toggle(1);
	str = ft_strjoin(str, name);
	file = fopen("consolelog.txt", "a");
	fprintf(file, "User Input: %s\nUser Output: %s\n", name, name);
	i = 0;
	while (1)
	{
		i = error_handle(i, file, name, str);
		if (i >= 1)
			return (i);
		break ;
	}
	printf("%s", str);
	return (0);
}

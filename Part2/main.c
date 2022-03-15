/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorriga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:16:07 by mmorriga          #+#    #+#             */
/*   Updated: 2022/03/15 12:21:14 by mmorriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <strings.h>
#include "libft.h"
/* Please change toggle to 1 for full company name,
 *  0 for abbreviated then recompile (toggle is at the very bottom)*/

/* Handles errors, outputs logs and assists the user on the correct input */
static int	error_handle(int e, FILE *file, char *name)
{
	if (e == 2)
	{
		fprintf(file, "Toggle was invalid (insert 1 or 0)\n");
		return (printf("Toggle invalid, please insert 1 or 0"), 3);
	}
	if (name == NULL)
	{
		fprintf(file, "[Error 2]\n");
		printf(", please input your name\n");
		fprintf(file, "Error: string was NULL\n");
		fprintf(file, "no user input\n");
		return (2);
	}
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
	else
		return (0);
}

/* The toggle function using ft_strlcat for error handling and
 * ft_substr to subdivide the full company name down to FDS
 * This is NOT where you change the value of toggle */
static char	*toggle(int toggle, FILE *file)
{
	int		i;
	char	*a[3];
	char	*res;

	a[0] = "Fancy";
	a[1] = " Development";
	a[2] = " Services";
	if (toggle == 0)
	{
		res = malloc(4 * sizeof(char *));
		res = (char *)ft_strjoin(ft_substr(a[0], 0, 1), ft_substr(a[1], 1, 1));
		i = (int)ft_strlcat(res, ft_substr(a[2], 1, 1), 3);
		res = (char *)ft_strjoin(res, ft_substr(a[2], 1, 1));
	}
	if (toggle == 1)
	{
		res = malloc(27 * sizeof(char *));
		res = ft_strjoin(a[0], a[1]);
		i = (int)ft_strlcat(res, a[2], 27);
	}
	if (i > 2 && i < 27)
		return (res);
	return (error_handle(2, file, res), NULL);
}

/* The main that calls other functions to then output:
 * "Welcome to FDS or Fancy Development Services - (First name)" */
int	main(void)
{
	char	*str;
	char	*name;
	char	*welcome;
	FILE	*file;
	int		value;

	welcome = "Welcome to ";
	name = malloc(255 * sizeof(char *));
	printf("Input your username: ");
	scanf("%s", name);
	file = fopen("consolelog.txt", "a");
	fprintf(file, "User Input: %s\n", name);
	value = 0;
	while (1)
	{
		value = error_handle(value, file, name);
		if (value >= 1)
			return (value);
		break ;
	}
	str = ft_strjoin(welcome, toggle(0, file));
	printf("%s %s %s", str, "-", name);
	fprintf(file, "Output: %s %s %s\n", str, "-", name);
	return (0);
}
/* The toggle is above the return (0) and the two printfs
 * at str = ft_strjoin(welcome, "toggle"(1 or 0)
 * 1 for full name of company or 0 for the abbreviation */

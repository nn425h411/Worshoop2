/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorriga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:16:07 by mmorriga          #+#    #+#             */
/*   Updated: 2022/03/18 13:20:43 by mmorriga         ###   ########.fr       */
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
	if (e == 6)
		return (printf("Counting Students...\n"), e);
	if (e == 3)
		return (fprintf(file, "StudentData.txt was unable to open\n"), 3);
	if (e == 2)
	{
		fprintf(file, "Toggle was invalid (insert 1 or 0)\n");
		return (printf("Toggle invalid, please insert 1 or 0"), 2);
	}
	while (1)
	{
		if (ft_isalpha(*name++) == 0)
			e++;
		if (e == (int)ft_strlen(name) || e > 1)
			break ;
	}
	if (e > 1)
	{
		printf("Input is not valid, please only use alphabetical characters\n");
		fprintf(file, "[Error 1]\nError: string had non-valid characters\n");
		fprintf(file, "incorrect input (non-alphabetical) or not enough mem\n");
		return (1);
	}
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

/* This function closes the StudentData.txt file,
 * writes an error if unsuccessful.
 * It also counts the amount of students if value is 6 in the main. */
static int	groupfile(FILE *f, FILE *group, int d)
{
	int		amount;
	int		close;
	char	c;

	amount = 1;
	close = 0;
	if (d == 6)
	{
		group = fopen("StudentData.txt", "r");
		while (1)
		{
			c = fgetc(group);
			if (c == '\n')
				amount++;
			if (c == EOF)
			{
				printf("Amount of Students %d\n", amount);
				return (42);
			}
		}
	}
	close = fclose(group);
	if (close == EOF)
		fprintf(f, "StudentData file was unable to close\n");
	return (d);
}

/* Sorts names into groups e.g., a name that starts with A will be 1
 * but a name that starts with U will be 5
 * Outputs an error if it's not able to assign a group. 
 * Creates the StudentData.txt file as well to store student info.*/
static int	grouper(int vl, FILE *file, const char *name, const char *welcome)
{
	FILE	*group;

	group = NULL;
	if (vl != 6)
	{
		group = fopen("StudentData.txt", "a");
		if (name[0] >= 'A' && name[0] <= 'E')
			vl = 1;
		if (name[0] >= 'F' && name[0] <= 'J')
			vl = 2;
		if (name[0] >= 'K' && name[0] <= 'O')
			vl = 3;
		if (name[0] >= 'P' && name[0] <= 'T')
			vl = 4;
		if (name[0] >= 'U' && name[0] <= 'Z')
			vl = 5;
		fprintf(group, "%s | %s | Group %d\n", welcome, name, vl);
	}
	if (vl == 0)
	{
		fprintf(file, "Was unable to assign %s to a grouping\n", name);
		printf("Grouping was unassignable for %s\n", name);
	}
	vl = groupfile(file, group, vl);
	return (vl);
}

/* The main that calls other functions to then output:
 * "Welcome to FDS or Fancy Development Services - (First name)"
 * then closes the logging file at the end.
 * To enable the counting feature of the Student Data logger,
 * change the value to = 6 . */
int	main(void)
{
	char	*str;
	char	*name;
	char	*welcome;
	FILE	*file;
	int		value;

	value = 0;
	welcome = "Welcome to ";
	name = malloc(255 * sizeof(char *));
	printf("Input your username: ");
	scanf("%s", name);
	file = fopen("consolelog.txt", "a");
	fprintf(file, "User Input: %s\n", name);
	value = error_handle(value, file, name);
	if (value >= 1 && value < 6)
		return (value);
	name[0] = ft_toupper(name[0]);
	str = ft_strjoin(welcome, toggle(0, file));
	value = grouper(value, file, name, str);
	fprintf(file, "Output: %s - %s - Group %d\n", str, name, value);
	printf("%s - %s - Group %d", str, name, value);
	value = fclose(file);
	if (value == EOF)
		fprintf(file, "consolelog.txt file was unable to close\n");
	return (0);
}
/* The toggle is above the return (0), the check for EOF, and the two printfs
 * at str = ft_strjoin(welcome, "toggle"(1 or 0)
 * 1 for full name of company or 0 for the abbreviation */

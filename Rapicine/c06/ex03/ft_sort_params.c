/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_paramas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:39:40 by doyun             #+#    #+#             */
/*   Updated: 2020/11/05 00:13:35 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchr(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	char *a;
	char *b;

	a = s1;
	b = s2;
	while (1)
	{
		if (*a != *b)
		{
			return (*a > *b ? 1 : -1);
		}
		if (*a == '\0' && *b == '\0')
			return (0);
		if (*a == '\0')
		{
			return (-1);
		}
		if (*b == '\0')
		{
			return (1);
		}
		a++;
		b++;
	}
}

void	swap(char **argv, char **argv2)
{
	char *temp;

	temp = *argv;
	*argv = *argv2;
	*argv2 = temp;
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 1)
			{
				swap(&argv[i], &argv[j]);
			}
			j++;
		}
		i++;
	}
	putchr(argc, argv);
}

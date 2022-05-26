/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:32:48 by doyun             #+#    #+#             */
/*   Updated: 2020/10/28 19:55:53 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int		main(void)
{
	char *a = "aaaaa";
	char *b = "aaaaaa";
	unsigned int n;
	
	n = 7;
	printf(	"%d",ft_strncmp(a, b, n));
	return (0);
}

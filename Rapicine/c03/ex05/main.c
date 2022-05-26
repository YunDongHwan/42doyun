/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:47:02 by doyun             #+#    #+#             */
/*   Updated: 2020/11/01 03:09:20 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int				main(void)
{
	char dest[10] = "abcde";
	char src[10] = "efg";
	unsigned int size;

	size = 4;
	printf("%d\n",ft_strlcat(dest, src, size));
	printf("%lu",strlcat(dest, src, size));
	return (0);
}

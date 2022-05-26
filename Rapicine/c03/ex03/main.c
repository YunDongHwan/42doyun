/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:54:46 by doyun             #+#    #+#             */
/*   Updated: 2020/11/01 03:48:48 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char		*ft_strncat(char *dest, char *src, unsigned int nb);

int			main(void)
{
	char des[50] = "abcdefg";
	char sr[50] = "hijklmnopqrstuv";
	unsigned int n;
	char *k;
	unsigned int i;
	
	i = 0;
	n = 13;
	k = ft_strncat(des, sr, n);
	while(i < n)
	{
		printf("%c",k[i]);
		i++;
	}
	return (0);
}

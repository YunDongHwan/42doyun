/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:50:46 by doyun             #+#    #+#             */
/*   Updated: 2020/10/28 16:15:01 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strncpy(char *dest, char *src, unsigned int n);

int		main(void)
{
	unsigned int n;

	n = 1;
	char dest[14] = "asdfasfasd";
	char src[10] = "DDDSSSDD";
	char *h;

	h = ft_strncpy(dest, src, n);
	while(*h)
	{
		write(1, h, 1);
		h++;
	}

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:13:54 by doyun             #+#    #+#             */
/*   Updated: 2020/11/01 03:48:45 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				a;
	int				b;
	unsigned int	n;

	a = 0;
	b = 0;
	n = nb;
	while (dest[a])
	{
		a++;
	}
	while (src[b] != '\0' && n != 0)
	{
		dest[a] = src[b];
		a++;
		b++;
		n--;
	}
	dest[a] = '\0';
	return (dest);
}

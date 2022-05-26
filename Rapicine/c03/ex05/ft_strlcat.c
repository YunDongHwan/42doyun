/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:53:31 by doyun             #+#    #+#             */
/*   Updated: 2020/11/01 03:56:43 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	deslen;
	unsigned int	srclen;
	unsigned int	j;

	deslen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	j = deslen;
	while (i < (int)(size - deslen - 1) && *dest && *src)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (size < deslen)
		return (srclen + size);
	else
		return (deslen + srclen);
}

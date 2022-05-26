/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:40:18 by doyun             #+#    #+#             */
/*   Updated: 2020/11/01 03:38:31 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	if (!(*to_find))
		return (str);
	while (str[i] != 0 && to_find[j] != 0
			&& ft_strlen(str) >= ft_strlen(to_find))
	{
		if (str[i] == to_find[j])
		{
			count = 1;
			i++;
			j++;
			continue ;
		}
		count = 0;
		i++;
		j = 0;
	}
	if (count)
		return (&str[i - j]);
	return (0);
}

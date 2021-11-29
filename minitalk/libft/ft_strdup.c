/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:05:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/19 17:51:46 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s1, len + 1);
	return (tmp);
}

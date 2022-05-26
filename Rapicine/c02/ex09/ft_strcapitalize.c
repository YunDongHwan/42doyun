/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:15:04 by doyun             #+#    #+#             */
/*   Updated: 2020/10/29 05:25:23 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			checknum(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		return (1);
	}
	return (0);
}

int			checkalpha(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		return (1);
	}
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		return (2);
	}
	return (0);
}

char		*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (checkalpha(str, i) == 1)
	{
		str[i] -= 32;
	}
	i++;
	while (str[i])
	{
		if (!(checknum(str, i - 1) || checkalpha(str, i - 1))
				&& checkalpha(str, i) == 1)
		{
			str[i] -= 32;
		}
		if ((checknum(str, i - 1) || checkalpha(str, i - 1))
				&& checkalpha(str, i) == 2)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

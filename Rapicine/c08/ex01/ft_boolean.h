/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:53:00 by doyun             #+#    #+#             */
/*   Updated: 2020/11/05 02:59:21 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_BOOLEAN.H
# define FT_BOOLEAN.H

# include <unistd.h>

typedef int		t_bool;

# define EVEN(nbr) (nbr % 2 == 0)
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

#endif

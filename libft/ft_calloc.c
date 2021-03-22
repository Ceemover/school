/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:53:19 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/29 20:03:35 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char *y;

	if (size == 0 || num == 0)
	{
		num = 1;
		size = 1;
	}
	y = (char*)malloc(num * size);
	if (y == 0)
		return (0);
	ft_bzero(y, num * size);
	return (y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 07:29:07 by dbolg             #+#    #+#             */
/*   Updated: 2020/06/02 10:04:00 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_make_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		ft_find_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*new_n;
	int		len;

	len = ft_find_len(n);
	if (!(new_n = (char*)malloc(len + 1)))
		return (NULL);
	new_n[len] = '\0';
	if (n < 0)
		new_n[0] = '-';
	else if (n == 0)
		new_n[0] = '0';
	while (n != 0)
	{
		len--;
		new_n[len] = ft_make_positive(n % 10) + '0';
		n = n / 10;
	}
	return (new_n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:55:29 by dbolg             #+#    #+#             */
/*   Updated: 2020/11/18 18:55:30 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				free2(char **str, char **str2)
{
	if (*str)
		free1(str);
	if (*str2)
		free1(str2);
	return (0);
}

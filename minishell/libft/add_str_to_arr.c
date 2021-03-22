/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:23:04 by dbolg             #+#    #+#             */
/*   Updated: 2020/11/24 02:23:09 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	add_str_to_arr(char **arr, char *str_to_add)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (arr && arr[i])
		i++;
	if (!(new = malloc(sizeof(char*) * (i + 1))))
		return (1);
	j = 0;
	while (arr && (j <= i))
	{
		new[j] = arr[j];
		j++;
	}
	new[i] = str_to_add;
	new[i + 1] = NULL;
	free(arr);
	arr = new;
	return (0);
}

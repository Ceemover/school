/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:27:02 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:27:04 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

char	*check_arguments(t_all *all, int argc, char **argv)
{
	int			i;

	i = 0;
	while (argv[1][i] && (ft_isalnum(argv[1][i]) ||
		argv[1][i] == '/' || argv[1][i] == '.'))
	{
		if (argv[1][i] == '.' && i != 0 && !ft_strchr("./", argv[1][i - 1]))
			break ;
		i++;
	}
	if (i == 0 || ft_strncmp(&argv[1][i], ".cub", 5))
		return ("wrong first argument format");
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		all->screenshot = 1;
	else if (argc == 3)
		return ("wrong second argument");
	return (OK);
}

int		complete(t_all *all)
{
	int			i;

	i = 1;
	i = i & (all->w != -1);
	i = i & (all->txtrs.no ? 1 : 0);
	i = i & (all->txtrs.so ? 1 : 0);
	i = i & (all->txtrs.ea ? 1 : 0);
	i = i & (all->txtrs.we ? 1 : 0);
	i = i & (all->txtrs.f != -1 ? 1 : 0);
	i = i & (all->txtrs.c != -1 ? 1 : 0);
	i = i & (all->txtrs.s ? 1 : 0);
	return (i);
}

int		skip_space(char *ln, int *i)
{
	int			j;

	j = *i;
	while (ln[*i] == ' ')
		*i += 1;
	return (*i - j);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

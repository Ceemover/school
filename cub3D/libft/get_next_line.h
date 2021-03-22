/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 07:37:17 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/14 04:32:46 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

int			f_ree(char **str1, char **str2, char **str3);
int			find_n(char *buf, size_t len);
char		*f_calloc(size_t num, size_t size);
size_t		f_strlen(const char *str);
char		*f_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
#endif

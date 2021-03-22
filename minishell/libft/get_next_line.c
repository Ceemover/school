/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 03:37:22 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/14 04:34:17 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_in_tail(char **head, char **tail, char **buf)
{
	int		nl;
	char	*tmp;

	nl = find_n(*tail, f_strlen(*tail));
	tmp = *tail;
	*(*tail + nl) = '\0';
	if (!(*head = f_strjoin(*tail, NULL)))
		return (f_ree(buf, &tmp, &tmp) ? -1 : -1);
	if (f_strlen(*tail + nl + 1))
	{
		if (!(*tail = f_strjoin((*tail + nl + 1), NULL)))
			return (f_ree(buf, &tmp, head) ? -1 : -1);
	}
	else
		*tail = NULL;
	f_ree(buf, &tmp, &tmp);
	return (1);
}

int	n_in_buf(char **head, char **tail, char **buf)
{
	int		nl;
	char	*tmp;

	tmp = NULL;
	nl = find_n(*buf, f_strlen(*buf));
	if (f_strlen(*buf + nl + 1))
	{
		if (!(*tail = f_strjoin((*buf + nl + 1), NULL)))
		{
			(*head ? f_ree(buf, head, head) :
				f_ree(buf, buf, buf));
			return (-1);
		}
	}
	*(*buf + nl) = '\0';
	tmp = *head;
	if (!(*head = f_strjoin(*head, *buf)))
	{
		(tmp ? f_ree(buf, tail, &tmp) : f_ree(buf, tail, tail));
		return (-1);
	}
	(tmp ? f_ree(buf, &tmp, &tmp) : f_ree(buf, buf, buf));
	return (1);
}

int	buf_mng(char **head, char **tail, char **buf, int buffsize)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if ((find_n(*buf, f_strlen(*buf))) > -1)
		return (n_in_buf(head, tail, buf));
	tmp = *head;
	if (!(*head = f_strjoin(*head, *buf)))
	{
		(*tmp ? f_ree(buf, &tmp, &tmp) : f_ree(buf, buf, buf));
		return (-1);
	}
	if (tmp)
		f_ree(&tmp, &tmp, &tmp);
	while (i++ < buffsize)
		*(*buf + i) = '\0';
	return (-2);
}

int	ft_exit(char **tail)
{
	int fd;

	fd = 0;
	while (fd < 1024)
	{
		if (tail[fd])
			f_ree(&tail[fd], &tail[fd], &tail[fd]);
		fd++;
	}
	return (-1);
}

int	get_next_line(int fd, char **head)
{
	static char	*tail[1025];
	char		*buf;
	int			ret;

	ret = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0) == -1) || !head
		|| !(buf = f_calloc((BUFFER_SIZE + 1), sizeof(char))))
		return (ft_exit(tail));
	*head = NULL;
	if (tail[fd] && (find_n(tail[fd], f_strlen(tail[fd])) > -1))
		return (n_in_tail(head, &tail[fd], &buf));
	if (tail[fd])
		*head = tail[fd];
	tail[fd] = NULL;
	while ((read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if ((ret = buf_mng(head, &tail[fd], &buf, BUFFER_SIZE)) > -2)
			return (ret);
	}
	if (!*head)
	{
		if (!(*head = f_strjoin(NULL, NULL)))
			return (f_ree(&buf, &buf, &buf) ? -1 : -1);
	}
	return (f_ree(&buf, &buf, &buf) ? 0 : 0);
}

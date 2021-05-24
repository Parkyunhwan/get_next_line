/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:35:58 by ypark             #+#    #+#             */
/*   Updated: 2021/05/24 13:21:49 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_enter(char *prev_record)
{
	int		i;

	i = 0;
	while (prev_record[i])
	{
		if (prev_record[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		getdata_join(int fd, char **prev_record)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			read_ret;

	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret <= 0)
		return (read_ret);
	buf[read_ret] = '\0';
	tmp = ft_strjoin(*prev_record, buf);
	free(*prev_record);
	*prev_record = tmp;
	return (read_ret);
}

int		append_to_line(char **line, char **prev_record, int index)
{
	char		*tmp;
	char		*tmp_prev;

	(*prev_record)[index] = '\0';
	*line = ft_strdup(*prev_record);
	tmp_prev = *prev_record + index + 1;
	if (!tmp_prev[0])
	{
		free(*prev_record);
		*prev_record = 0;
	}
	else
	{
		tmp = ft_strdup(tmp_prev);
		free(*prev_record);
		*prev_record = tmp;
	}
	return (1);
}

int		check_eof(char **line, char **prev_record)
{
	int		index;

	if (!*prev_record)
		*line = ft_strdup("");
	else if (*prev_record && (index = check_enter(*prev_record)) < 0)
	{
		*line = *prev_record;
		*prev_record = 0;
	}
	else if (*prev_record && index >= 0)
		return (append_to_line(line, prev_record, index));
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*prev_record[OPEN_MAX];
	int				index;
	int				read_ret;
	int				eof_ret;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while (1)
	{
		read_ret = getdata_join(fd, &prev_record[fd]);
		if (read_ret <= 0)
			break ;
		if ((index = check_enter(prev_record[fd])) >= 0)
		{
			append_to_line(line, &prev_record[fd], index);
			return (1);
		}
	}
	if (read_ret < 0)
		return (-1);
	eof_ret = check_eof(line, &prev_record[fd]);
	return (eof_ret);
}

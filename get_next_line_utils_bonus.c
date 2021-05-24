/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:34:50 by ypark             #+#    #+#             */
/*   Updated: 2021/05/24 03:14:34 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	tmp = dst;
	s = src;
	while (n--)
		*tmp++ = *s++;
	return (dst);
}

char		*ft_strjoin(char const *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (!(s1) && !(s2))
		return (0);
	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		else
			return (ft_strdup(s2));
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = 0;
	return (new);
}

char		*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1);
	if (!(tmp = malloc(len + 1)))
		return (0);
	ft_memcpy(tmp, s1, len);
	tmp[len] = 0;
	return (tmp);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

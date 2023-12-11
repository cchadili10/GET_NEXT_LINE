/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 06:33:31 by hchadili          #+#    #+#             */
/*   Updated: 2023/12/11 14:15:47 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_status(char *garbage, int len)
{
	char	*array;
	int		x;

	x = 0;
	if (!garbage)
		return (0);
	array = malloc(len + 1);
	if (!array)
		return (0);
	while (garbage[x])
	{
		if (garbage[x] == 10)
		{
			array[x] = 10;
			break ;
		}
		else
			array[x] = garbage[x];
		x++;
	}
	array[x + 1] = '\0';
	return (array);
}

void	ft_clear(char *garbage)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!garbage)
		return ;
	while (garbage[x])
	{
		if (garbage[x] == 10)
		{
			x++;
			break ;
		}
		x++;
	}
	while (garbage[x])
	{
		garbage[y++] = garbage[x];
		x++;
	}
	ft_bzero(garbage + y, x - y);
}

char	*ft_check_garbege(char *garbage, char *all, int *n)
{
	int	len;

	len = 0;
	*n = new_line_check(garbage, &len);
	if (*n)
	{
		all = ft_status(garbage, len);
		ft_clear(garbage);
		return (all);
	}
	else if (*n == 0 && len > 0)
	{
		all = ft_strjoin(all, garbage);
		ft_clear(garbage);
		return (all);
	}
	return (NULL);
}

char	*ft_getline(char *garbage, char *all, int fd)
{
	int		n;
	int		len;
	char	*holder;

	len = 0;
	while ((read(fd, garbage, BUFFER_SIZE)) > 0)
	{
		n = new_line_check(garbage, &len);
		if (n == 0)
		{
			all = ft_strjoin(all, garbage);
			ft_clear(garbage);
		}
		else
		{
			holder = ft_status(garbage, len);
			ft_clear(garbage);
			all = ft_strjoin(all, holder);
			return (free(holder), all);
		}
	}
	return (all);
}

char	*get_next_line(int fd)
{
	static char	garbage[OPEN_MAX][BUFFER_SIZE + (size_t)1];
	char		*all;
	int			n;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_bzero(garbage[fd], BUFFER_SIZE), NULL);
	n = 0;
	all = NULL;
	all = ft_check_garbege(garbage[fd], all, &n);
	if (n && all)
		return (all);
	all = ft_getline(garbage[fd], all, fd);
	if (all)
		return (all);
	return (free(all), NULL);
}

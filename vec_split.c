/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toramo <toramo.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:48:48 by toramo            #+#    #+#             */
/*   Updated: 2023/10/31 12:59:15 by toramo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	vec_free_if_exists(void *arg)
{
	if (arg)
		free(arg);
}

int	free_split_vec(t_vec *strs)
{
	vec_iter(strs, vec_free_if_exists);
	vec_free(strs);
	return (1);
}

void	vec_print_elem_str(void *elem)
{
	ft_printf("%s\n", (char *)elem);
}

int	vec_split(t_vec *dst, const char *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	vec_new(dst, 32, sizeof(char *));
	if (dst == 0)
		return (1);
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			vec_push(dst, malloc(sizeof(char)
					* (ft_strlen_member(&s[j], c) + 1)));
			if ((char *)vec_get(dst, dst->len - 1) == 0)
				return (free_split_vec(dst));
			ft_strlcpy((char *)vec_get(dst, dst->len - 1),
				&s[j], (ft_strlen_member(&s[j], c) + 1));
			j = j + ft_strlen_member(&s[j], c);
			i++;
		}
	}
	return (0);
}

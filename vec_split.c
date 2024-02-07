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
	char	*str;

	str = *(char **) arg;
	if (str)
		free(str);
}

int	free_split_vec(t_vec *strs)
{
	vec_iter(strs, vec_free_if_exists);
	vec_free(strs);
	return (1);
}

void	vec_print_elem_str(void *elem)
{
	ft_printf("%s\n", *(char **)elem);
}

int	vec_split(t_vec *dst, const char *s, char c)
{
	int		j;
	char	*str;

	j = 0;
	vec_new(dst, 32, sizeof(char *));
	if (dst == 0)
		return (1);
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			str = ft_calloc(1, ft_strlen_member(&s[j], c) + 1);
			if (!str)
				return (free_split_vec(dst));
			ft_strlcpy(str, &s[j], (ft_strlen_member(&s[j], c) + 1));
			vec_push(dst, str);
			j = j + ft_strlen_member(&s[j], c);
			free(str);
		}
	}
	return (0);
}

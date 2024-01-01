#include "libft.h"

static size_t	vec_strlen(const char *str)
{
	int	n;

	n = 0;
	if (str[0] != 0)
	{
		while (str[n] != 0)
		{
			n++;
		}
	}
	return (n);
}

static size_t	ft_vec_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && *dst)
	{
		dst++;
		i++;
	}
	if (i == size)
		return (i + vec_strlen((char *)src));
	j = 0;
	while (src[j])
	{
		if (j < size - i - 1)
			*dst++ = src[j];
		j++;
	}
	*dst = 0;
	return (j + i);
}

int	vec_strlcat(t_vec *dst, char *src, size_t l)
{
	if (!dst)
		return (-1);
	if (!dst->memory)
		vec_new(dst, l, 1);
	if (dst->elem_size != 1)
		return (-1);
	if (l + dst->len < dst->alloc_size)
	{
		if (vec_resize(dst, l + dst->len) <= 0)
			return (-1);
	}
	ft_vec_strlcat((char *)dst->memory, src, l);
	dst->len += l;
	return (dst->len);
}
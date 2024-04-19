/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprunty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:00:08 by mprunty           #+#    #+#             */
/*   Updated: 2024/01/06 16:12:01 by mprunty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	count_char(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

int	get_len(char const *s, char *end)
{
	int	len;

	if (!end)
		len = ft_strlen(s);
	else
		len = (end - s);
	return (len);
}

char	*get_ptr(int len, char const *s)
{
	char	*ptr;

	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	*end;
	int		len;
	int		i;
	char	**dblptr;

	i = 0;
	n = count_char(s, c);
	dblptr = (char **)malloc((n + 1) * (sizeof(char *)));
	if (!dblptr || !s)
		return (NULL);
	while (*s)
	{
		len = 1;
		if (*s != c)
		{
			end = ft_strchr(s, c);
			len = get_len(s, end);
			if (s != end && i <= n && len)
				dblptr[i++] = get_ptr(len, s);
		}
		s += len;
	}
	dblptr[i] = NULL;
	return (dblptr);
}
/*
void	printdp(char **dblptr)
{
        int	i = 0;
        while(dblptr[i]){
                printf("\nft_split, str %i :%s", i ,(dblptr[i]));
                i++;
        }
        return;
}

int main()
{
	char	*s;
	s = "      split       this for   me  !       ";
        printdp(ft_split(s, ' '));

}*/

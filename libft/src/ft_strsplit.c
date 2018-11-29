/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:26:25 by fwerner           #+#    #+#             */
/*   Updated: 2018/11/19 11:17:16 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		count_words(char const *str, char sep)
{
	int		words_count;
	int		lst_char_was_sep;
	int		index;

	words_count = 0;
	lst_char_was_sep = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != sep)
		{
			if (lst_char_was_sep == 1)
			{
				words_count += 1;
			}
			lst_char_was_sep = 0;
		}
		else
		{
			lst_char_was_sep = 1;
		}
		++index;
	}
	return (words_count);
}

static void		dup_next_word(char const **str, char sep, char **tab)
{
	int		word_len;

	while (**str == sep)
	{
		++(*str);
	}
	word_len = 0;
	while ((*str)[word_len] != sep)
	{
		++word_len;
	}
	*tab = ft_strnew(word_len);
	if (*tab != NULL)
	{
		ft_strncpy(*tab, *str, word_len);
		(*str) += word_len;
	}
}

static void		tab_free_not_null(char **tab)
{
	int		index;

	index = 0;
	while (tab[index] != NULL)
	{
		ft_memdel((void**)(&(tab[index])));
		++index;
	}
	ft_memdel((void**)(&tab));
}

char			**ft_strsplit(char const *s, char c)
{
	int		words_count;
	char	**words_tab;
	int		index;

	if (s == NULL)
		return (NULL);
	words_count = count_words(s, c);
	words_tab = (char**)ft_memalloc(sizeof(*words_tab) * (words_count + 1));
	if (words_tab == NULL)
	{
		return (NULL);
	}
	words_tab[words_count] = NULL;
	index = 0;
	while (index < words_count)
	{
		dup_next_word(&s, c, &(words_tab[index]));
		if (words_tab[index] == NULL)
		{
			tab_free_not_null(words_tab);
			return (NULL);
		}
		++index;
	}
	return (words_tab);
}

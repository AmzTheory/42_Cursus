/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalzubai <aalzubai.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:25:43 by aalzubai          #+#    #+#             */
/*   Updated: 2022/11/13 17:25:43 by aalzubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_number_of_elements(char const *s, char c)
{
	int		i;
	char	prev;
	int		close;

	i = 0;
	close = 1;
	prev = c;
	while (*s != '\0')
	{
		if (*s == prev && *s == c)
		{
			s++;
			continue ;
		}
		else if (*s == c)
		{
			close = 0;
			i++;
		}
		else
			close = 1;
		prev = *s;
		s++;
	}
	return (i + (close));
}

static	char	*form_word(char const *s, size_t l)
{
	size_t		j;
	char		*word;
	size_t		index;
	size_t		i;

	i = 0;
	index = 0;
	j = l - 1;
	if (l == 0)
		return (NULL);
	while (i < l && *(s - (l - i)) == ' ' )
		i++;
	if (j < i)
		return (NULL);
	word = malloc((j - i + 1 + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i <= j)
		word[index++] = *(s - (l - i++));
	word[index] = '\0';
	return (word);
}

static	char	**split_end(char **w, size_t i, char const *s, int l_word)
{
	char	*tmp;

	tmp = form_word(s, l_word);
	if (tmp != NULL)
		w[i++] = tmp;
	w[i] = NULL;
	return (w);
}

static char	**loop(char const *s, char c, char	**words)
{
	int			l_word;
	size_t		i;
	char		*tmp;

	l_word = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			tmp = form_word(s, l_word);
			if (tmp != NULL)
				words[i++] = tmp;
			s++;
			while (*s == c)
				s++;
			l_word = 0;
			continue ;
		}
		s++;
		l_word++;
	}
	return (split_end(words, i, s, l_word));
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		n_words;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_calloc(1, 8));
	while (*s == ' ' || *s == c)
		s++;
	n_words = get_number_of_elements(s, c);
	words = malloc((n_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (loop(s, c, words));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_splitter_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:18:02 by mkoch             #+#    #+#             */
/*   Updated: 2022/05/13 12:18:09 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_len_in_quotes(char *str, char quote)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[++i] != quote)
		len++;
	return (len);
}

char	*red_as_arg(char *str)
{
	char	*ret;
	char	*tmp;
	char	*joined;
	char	ch;
	int		len;

	len = 0;
	ret = malloc(sizeof(char) * 2);
	ret[0] = 7;
	ret[1] = '\0';
	ch = str[len];
	len++;
	while (str[len] != ch)
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	ft_strlcpy(tmp, str + 1, len);
	tmp[len] = '\0';
	joined = ft_strjoin(ret, tmp);
	free(ret);
	free(tmp);
	return (joined);
}

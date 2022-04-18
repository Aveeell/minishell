/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:31:39 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/18 12:16:24 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int	ft_strcmp(char *s1, char *s2)
{
	int			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (i < ft_strlen(s1))
	{
		if (s11[i] != s22[i] || (s11[i] == '\0' && s22[i] == '\0'))
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

int main()
{
	char *input;
	while(1)
	{
		input = readline("minishell% ");
		if (!ft_strcmp(input, "exit"))
			exit(0);
		else
		{
			add_history(input);
			free(input);
		}
	}
	return 0;
}

/*
Function: int rl_redisplay ()
Change what's displayed on the screen to reflect the current contents of rl_line_buffer.

Function: int rl_on_new_line ()
Tell the update routines that we have moved onto a new (empty) line, usually after ouputting a newline.

Function: void rl_clear_history (void)
Clear the history list by deleting all of the entries, in the same manner as the History library's clear_history() function. 
This differs from clear_history because it frees private data Readline saves in the history list.

Function: void rl_replace_line (const char *text, int clear_undo)
Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.


readline,
rl_clear_history,
rl_on_new_line,
rl_replace_line,
rl_redisplay,
add_history,
printf,
malloc,
free,
write,
access,
open,
read,
close,
fork,
wait,
waitpid,
wait3,
wait4,
signal,
sigaction,
sigemptyset,
sigaddset,
kill,
exit,
getcwd,
chdir,
stat,
lstat,
fstat,
unlink,
execve,
dup,
dup2,
pipe,
opendir,
readdir,
closedir,
strerror,
perror,
isatty,
ttyname,
ttyslot,
ioctl,
getenv,
tcsetattr,
tcgetattr,
tgetent,
tgetflag,
tgetnum,
tgetstr,
tgoto,
tputs



*/

#include "minishell.h"

t_command	*init_cmd(char **buff)
{
	int			len;
	t_command	*command;

	command = NULL;
	if (!buff || buff[0] == NULL)
		return (NULL);
	len = 0;
	while (buff[len])
		len++;
	command = (t_command *) malloc (sizeof(t_command));
	command -> options = NULL;
	command -> args = (char **) malloc ((len + 1) * sizeof(char *));
	command -> args[0] = NULL;
	command -> program = NULL;
	command -> next = NULL;
	command -> redirection = NULL;
	command -> files = NULL;
	// command -> flags = O_WRONLY | O_CREAT;
	return (command);
}

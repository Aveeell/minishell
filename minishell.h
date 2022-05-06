
#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <readline/history.h>
# include <readline/readline.h>

# define WHITE_SPACES " \t\v\r\f"
# define DELIMS " \t\v\r\f>|<"

typedef struct	s_files
{
	char			*file;
	struct s_files	*next;
}				t_files;

struct	s_minishell
{
	int	g_exites;
	int	is_running;
}		g_variable;

typedef struct	s_command
{
	char				*redirection;
	t_files				*files; //файлы при редиректах
	char				*program; //название бинарника
	char				**args; //аргументы команды
	char				*options; //флаги команд
	char				**execve; //путь к бинарнику
	int					is_append; //добавляем ли к файлу данные
	int					heredoc; //флаг использования heredoc (при редиректе <<)
	struct s_command	*next; //если пайпы, то здесь следующая команда
}				t_command;

typedef struct	s_envlist // linked lst
{
	char				*var_name;
	char				*var_content;
	char				*stock; //исходная строка до разбивки на переменную и значение
	struct s_envlist	*next;
}				t_envlist;

/*  PROTOTYPES  */

t_command	*get_command(char **buff, int i, int tmp, t_envlist *lst);
char		**args_splitter(char **ret, char *s);
t_envlist	*init_env_list(char **envp);
t_envlist	*ft_lstnew(char *s);
t_envlist	*ft_lstnew_2(char **s);
t_envlist	*ft_lstlast(t_envlist *lst);
void		ft_lstadd_back(t_envlist **lst, t_envlist *new);
int			signal_handler(void);
int			ft_tab_len(char **tab);
char		**ft_split_smart(char const *s, char c);
int			check_quotes(char	*str);
char		**get_execve(char **buff, int i);
int			error_checker(char **buff);
char		*get_env(char *read, t_envlist *lst);
int			export_printer(t_envlist *lst);
void		pipe_handler(t_command *command, t_envlist *lst);
void		redirection_handler(t_command *command, t_envlist *lst);
int			heredoc(t_command *command, t_envlist *lst);
void		parser(t_command *command, char **buff, int *i, int *j);
int			is_redir(char *str);
char		*strjoin_free(char *s1, char *s2);
void		set_error(char *s);
char		*is_builtin(char *cmd);
void		execve_builtin_binary(t_command *command, t_envlist *lst);
int			cd_builtin(t_command *command, t_envlist *lst);
int			export_builtin(t_envlist *lst, t_command *command);
int			echo_builtin(t_command *commad);
int			unset_builtin(t_command *commad, t_envlist *lst);
int			env_builtin(t_envlist *lst);
int			pwd_builtin(void);

#endif

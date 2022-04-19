/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:31:39 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/19 11:59:39 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *input;
	char **split_input;
	
	while(1)
	{
		input = readline("minishell> ");
		split_input = ft_split(input, ' ');
		choose_func(split_input);
		
		add_history(input);
		for(int i = 0; split_input[i]; i++)
			free(split_input[i]);
		free(split_input);
		free(input);
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
Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible.
If clear_undo is non-zero, the undo list associated with the current line is cleared.

int chdir(const char *path);
chdir изменяет текущий каталог каталог на path.

int access(const char *pathname, int mode);
access проверяет, имеет ли процесс права на чтение или запись, или же просто проверяет, существует ли файл (или другой объект файловой системы), с именем pathname.
Если pathname является символьной ссылкой, то проверяются права доступа к файлу, на который она ссылается.

pid_t wait3(int *status, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
Функция wait3 приостанавливает исполнение текущего процесса до того, как дочерний процесс завершит свою работу, или он не получит сигнал, прекращающий его работу, или не будет произведен вызов обработчика прерывания.
Если дочерний процесс уже прекратил свою работу на момент вызова этой функции (такой процесс называется "зомби" ("zombie")), то функция немедленно возвращается.
Все системные ресурсы, использованные дочерним процессом, будут освобождены.
Функция wait4 приостанавливает исполнение текущего процесса до того, как свою работу завершит дочерний процесс с номером pid, или этот процесс не получит сигнал, прекращающий его работу, или не будет произведен вызов обработчика прерывания.
Если дочерний процесс pid уже прекратил свою работу на момент вызова этой функции (такой процесс называется "зомби"), то функция немедленно возвращается. Все системные ресурсы, использованные дочерним процессом, будут освобождены.

char *getcwd(char *buf, size_t size);
Функция getcwd() копирует абсолютный путь к текущему рабочему каталогу в массиве, на который указывает buf, имеющий длину size.

int stat(const char *file_name, struct stat *buf);
int fstat(int filedes, struct stat *buf);
int lstat(const char *file_name, struct stat *buf);  
https://www.opennet.ru/man.shtml?topic=lstat&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

int execve(const char *filename, char *const argv [], char *const envp[]);
https://www.opennet.ru/man.shtml?topic=execve&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man

int dup(int oldfd);
int dup2(int oldfd, int newfd);
dup и dup2 создают копию файлового дескриптора oldfd.
Старый и новый дескрипторы можно использовать друг вместо друга. Они имеют общие блокировки, указатель позиции в файле и флаги; например, если позиция в файле была изменена с помощью lseek, на одном из дескрипторов, то эта позиция также меняется и на втором.
Два дескриптора, однако, каждый имеют свой собственный флаг закрыть-при-exec.
dup использует самый маленький свободный номер дескриптора.
dup2 делает newfd копией oldfd, закрывая newfd, если требуется. 

#include <sys/types.h>
#include <dirent.h>
DIR *opendir(const char *name);
Функция opendir() открывает поток каталога, соответствующий каталогу name, и возвращает указатель на этот поток. 
Поток устанавливается на первой записи в каталоге.

int isatty(int desc);
Возвращает 1, если desc является открытым описателем, соединенным с терминалом, в противном случае возвращает 0.  

char *ttyname(int fd);
Функция ttyname() возвращает указатель на полное имя устройства терминала, заканчивающееся на NUL, открытого на описателе файла fd, или NULL при ошибках (например, если fd не подключен к терминалу).
Возвращаемое значение может указывать на статические данные, которые могут быть перезаписаны следующим вызовом.
Функция ttyname_r() сохраняет полный путь в буфере buf длиной buflen.  

int ttyslot(void);
https://www.opennet.ru/man.shtml?topic=ttyslot&russian=0&category=&submit=%F0%CF%CB%C1%DA%C1%D4%D8+man


--------------------------------------------------------------------------------
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

#include "minishell.h"

void	cltr_c(int sig) // обработчик для сигнала cltr_c(SIGINT), его код = 2
{
	printf("\n");
	g_variable.g_exites = 128 + sig; // чтобы в  выводе было 130, как в zsh
	if (!g_variable.is_running)  //g_variable.is_running = 1, когда выполняется какая-то команда или пайп
	{
		rl_replace_line("", 0); //Replace the contents of rl_line_buffer with text. 
		rl_on_new_line();		//Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
		rl_redisplay();			//Change what's displayed on the screen to reflect the current contents of rl_line_buffer.
	}
}

int	signal_handler(void)
{
	signal(SIGINT, cltr_c); // если сигнал SIGINT (т.е. ctrl+C), вызыыаем функцию cltr_c
	signal(SIGQUIT, SIG_IGN); // если сигнал SIGQUIT, мы его игнорируем (SIG_IGN)
							//Passing SIG_IGN as handler ignores a given signal 
							//(except the signals SIGKILL and SIGSTOP which can't caught or ignored).
	return (0);
}

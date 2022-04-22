#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
    //  #include <sys/types.h>
    //  #include <sys/dir.h>

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 1;
	word = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[0] != c)
		word++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

static int	ft_len_word(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **res, int i)
{
	int	j;

	j = 0;
	while (i > j && res[j] != 0)
	{
		free(res[j]);
		j++;
	}
	free(res);
	return ((void *)0);
}

int	ft_write_str(char *res, char const *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[j] != c && s[j] != '\0')
	{
		res[i] = s[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return ((void *)0);
	res = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!res)
		return ((void *)0);
	while (i < ft_count_word(s, c))
	{
		res[i] = malloc(sizeof(char) * (ft_len_word(s, c, j) + 1));
		if (!res[i])
			return (ft_free(res, i));
		while (s[j] == c)
			j++;
		j = ft_write_str(res[i], s, c, j);
		i++;
	}
	res[i] = ((void *)0);
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (i < n)
	{
		if (s11[i] != s22[i] || (s11[i] == '\0' && s22[i] == '\0'))
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int main(int argc, char **argv)
{
	char 			*command;
	char			*dir_paths_str;
	char			**dir_paths;
	int				i;
	DIR				*dir;
	struct dirent 	*entity;

	if (argc == 2) //check if input is valid!!!
		command = argv[1];
	else
		{
			printf("No input\n");
			exit(1);
		}
	// printf("command is %s\n", command);
	dir_paths_str = getenv("PATH"); //check return values
	printf("%s\n", dir_paths_str);
	dir_paths = ft_split(dir_paths_str, ':'); //check return values 
	i = 0;
	while (dir_paths[i])
		printf("%s\n", dir_paths[i++]);
	char *pwd = malloc(1024); //check if directiry changes
	i = 0;
	while (dir_paths[i])
	{
		chdir(dir_paths[i]); //check return values
		dir = opendir(dir_paths[i]);
		if (dir == NULL)
			return (1);
		getcwd(pwd, 1024);
		printf("Im here: %s\n", pwd);
		entity = readdir(dir);
		while (entity != NULL)
		{
			printf("%hhd %s\n", entity->d_type, entity->d_name);
			// if ((entity->d_type == DT_REG) && (ft_strncmp(entity->d_name, command, ft_strlen(command) + 1) == 0))
			// // if (ft_strncmp(entity->d_name, command, ft_strlen(command) + 1) == 0)
			// {
			// 	printf("Found an equal in %s\n", pwd);
			// 	execve(entity->d_name, 0, 0);
			// }
			
			entity = readdir(dir);
		}
		i++;
	}
	free(pwd);
	closedir(dir);

	i = 0;
	while (dir_paths[i])
		free(dir_paths[i++]);
	free(dir_paths);
	return (0);
}
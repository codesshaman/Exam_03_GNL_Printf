#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int ft_strlen(char *str) {
	int i = 0;
	while (str[i])
		i++;
	return i;
}
char *ft_strjoin(char *s1, char *s2) {
	int i = -1, j = -1;
	char *res;
	if (!s2)
		return (NULL);
	if (!s1) {
		res = malloc(2);
		res[0] = s2[0];
		res[1] = '\0';
		return res;
	}
	res = malloc(sizeof(char) * ft_strlen(s1) + 2);
	if (!res)
		return NULL;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	res[i+j] = '\0';
	free(s1);
	return res;
}

char *get_next_line(int fd) {
	char *str = NULL, *buf = malloc(2);
	if (!buf)
		return (NULL);
	while (read(fd, buf, 1) == 1 && buf[0] != '\0') {
		buf[1] = '\0';
		str = ft_strjoin(str, buf);
		if (buf[0] == '\n')
			break;
	}
	free(buf);
	return str;
}

int main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	// printf("%d\n", fd1);
	// fd1 = open("tests/test.txt", O_RDONLY);
//	fd2 = open("tests/test2.txt", O_RDONLY);
//	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 4)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	biggest_word(const char *s)
{
	int len;
	int	i;

	len = 0;
	i = 0;
	while (*s)
	{
		i = 0;
		while (*s && *s != ' '){
			i++; s++;
		}
		if (i > len)
			len = i;
		if (*s)
			s++;
	}
	return (len);
}

void	print_banner(int n)
{
	for (int i=0; i < n + 4; i++)
		printf("*");
	printf("\n");
}

void	print_word(int n, const char *s)
{
	int	len;

	len = strlen(s);
	printf("* %s", s);
	for (int i=0; i < n - len; i++)
		printf(" ");
	printf(" *\n");
}

void	print_in_frame(char *s)
{
	int		len;
	char*	token;

	len = biggest_word(s);
	print_banner(len);
	token = strtok(s, " ");
	while (token) {
		print_word(len, token);
		token = strtok(NULL, " ");
	}
	print_banner(len);
}

int	main(int ac, char** av)
{
	for (int i=1; i < ac; i++) {
		print_in_frame(av[i]);
	}
	return (0);
}

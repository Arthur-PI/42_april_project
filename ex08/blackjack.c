#include <stdio.h>
#include <string.h>

int	valid_hand(char *s)
{
	char	*alphabet = "23456789TJDKA";

	for (int i=0; s[i]; i++) {
		if (!strchr(alphabet, s[i]))
			return (0);
	}
	return (1);
}

int	main(int ac, char** av)
{
	int			aces;
	int			total;
	const char*	s;

	if (ac != 2) {
		printf("Invalid number of args\nUsage: %s <hand>\n", av[0]);
		return (1);
	}
	if (!valid_hand(av[1])) {
		printf("Invalid hand, allowed characters: 23456789TJDKA\n");
		return (2);
	}
	s = av[1];
	aces = 0;
	total = 0;
	for (int i=0; s[i]; i++) {
		if (s[i] == 'A')
			aces++;
		else if (s[i] >= '2' && s[i] <= '9')
			total += s[i] - '0';
		else
			total += 10;
	}
	while (aces > 0) {
		if (total + 11 + (aces - 1) <= 21)
			total += 11;
		else
			total++;
		aces--;
	}
	if (total == 21)
		printf("Blackjack!");
	else
		printf("%d", total);
	return (0);
}

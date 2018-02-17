#include "lem_in.h"

int		main(int argc, char **argv)
{
	char *line;

	line = NULL;
	printf("%d\n", argc);
	while (get_next_line(0, &line) == 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}

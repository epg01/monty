#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	size_t line_num;

	if (argc != 2) 
		dprintf(STDERR_FILENO, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	line_num = 1;
	while ((nread = getline(&line, &len, fd)) != -1) 
	{
		(list.inst_oper)[0] = strtok(line, "\t\n ");
		(list.inst_oper)[1] = strtok(NULL, "\t\n ");
		if (list.inst_oper[0])
			get_op((list.inst_oper)[0])(NULL, line_num);
		line_num++;
		free(line);
		line = NULL;
		len  = 0;
	}

	fclose(fd);
	free(line);
	return (0);
}

#include "monty.h"

/**
 * Destroy - Function destroy
 */

void Destroy(List *list)
{
	while (list->Size)
		List_Rem(list, NULL);
}

/**
* main - function to passed file such an arguments in interpreter
* @argc: number of arguments
* @argv: arguments
* Return: Exit sucess if program is in the end
*/

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
	Destroy(&list);
	fclose(fd);
	free(line);
	return (0);
}

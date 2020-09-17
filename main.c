#include "monty.h"

#define s "L%lu: unknown instruction %s\n"

/**
 * Destroy - Function destroy
 * @list: Pointer to data structure of type List.
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
	size_t len = 0, line_num = 1;
	void (*Pointer_Function)(stack_t **, unsigned int);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	list.Fd = fd;
	while (getline(&line, &len, fd) != EOF)
	{
		list.Solve_line = line;
		(list.inst_oper)[0] = strtok(line, "\t\n ");

		if (list.inst_oper[0] && list.inst_oper[0][0] == '#')
		{
			free(line), line = list.inst_oper[0] = NULL;
			continue;
		}
		(list.inst_oper)[1] = strtok(NULL, "\t\n ");
		if (list.inst_oper[0])
		{
			Pointer_Function = get_op((list.inst_oper)[0]);
			if (Pointer_Function)
				Pointer_Function(NULL, line_num);
			else
			{
				char *string =  list.inst_oper[0];

				fprintf(stderr, s, line_num, string);
				free(line), fclose(list.Fd), Destroy(&list), exit(EXIT_FAILURE);
			}
		}
		line_num++, free(line),	line = NULL, len  = 0;
	}
	fclose(fd), free(line), Destroy(&list);
	return (0);
}

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
 * stack_or_queue - Implement the stack and queue opcodes.
 * @string: pointar string character.
 * Return: Returns 1 if 0 matches otherwise
 */

int stack_or_queue(char *string)
{
	if (string)
		if (strcmp("queue", list.inst_oper[0]) == 0)
		{
			list.State = 0;
			return (1);
		}
		else if (strcmp("stack", list.inst_oper[0]) == 0)
		{
			list.State = 1;
			return (1);
		}
		else
			return (0);
	else
		return (0);
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
	char *line = NULL, *string = NULL;
	size_t len = 0, line_num = 1;
	void (*Pointer_Function)(stack_t **, unsigned int);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	list.Fd = fd, list.State = 1;
	while (getline(&line, &len, fd) != EOF)
	{
		list.Solve_line = line, (list.inst_oper)[0] = strtok(line, "\t\n ");
		if (list.inst_oper[0] && list.inst_oper[0][0] == '#')
		{
			free(line), line = list.inst_oper[0] = NULL, line_num++;
			continue;
		}
		if (stack_or_queue(list.inst_oper[0]))
		{
			line_num++;
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
				string =  list.inst_oper[0], fprintf(stderr, s, line_num, string);
				free(line), fclose(list.Fd), Destroy(&list), exit(EXIT_FAILURE);
			}
		}
		line_num++, free(line), line = NULL, len  = 0;
	}
	fclose(fd), free(line), Destroy(&list);
	return (0);
}

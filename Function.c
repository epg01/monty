#include "monty.h"

void _push(stack_t **stack, unsigned int lin_num)
{
	extern char *inst_oper[];
	int index = 0;
	(void)stack;

	while (inst_oper[1][index])
		if (isdigit(inst_oper[1][index]))
			index++;
		else
		{
			printf("L%d: usage: push integer\n", lin_num);
			exit (EXIT_FAILURE);
		}

	Push_Stack(&list, atoi(inst_oper[1]));
}

void _pall(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	Pall(list.Head);
}

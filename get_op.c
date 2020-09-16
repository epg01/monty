#include "monty.h"

void (*get_op(char *inst_oper))(stack_t **stack, unsigned int lin_num)
{
	int i = 0;
	instruction_t instructions_fun[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (instructions_fun[i].opcode)
	{
		if (strcmp(inst_oper, instructions_fun[i].opcode) == 0)
			return (instructions_fun[i].f);
		i++;
	}
	return (NULL);
}

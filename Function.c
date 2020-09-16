#include "monty.h"

void _push(stack_t **stack, unsigned int lin_num)
{
	int index = 0;
	(void)stack;

	while ((list.inst_oper)[1][index])
		if ((isdigit((list.inst_oper)[1][index])))
			index++;
		else
		{
			printf("L%d: usage: push integer\n", lin_num);
			exit (EXIT_FAILURE);
		}

	Push_Stack(&list, atoi((list.inst_oper)[1]));
}

void _pall(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	Pall(list.Head);
}

void _sub(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size > 1)
	{
		int Number1, Number2;

		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		Push_Stack(&list, Number2 - Number1);
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", lin_num);
		exit (EXIT_FAILURE);
	}
}

void _mul(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size > 1)
	{
		int Number1, Number2;

		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		Push_Stack(&list, Number2 * Number1);
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", lin_num);
		exit (EXIT_FAILURE);
	}
}

#include "monty.h"

void _div(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size)
	{
		int Number1, Number2;

		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		if (Number1)
			Push_Stack(&list, Number2 / Number1);
		else
			printf("No se puede dividir por cero");
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", lin_num);
		exit (EXIT_FAILURE);
	}
}
void _mod(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size)
	{
		int Number1, Number2;

		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		Push_Stack(&list, Number2 % Number1);
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", lin_num);
		exit (EXIT_FAILURE);
	}
}

void _pchar(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size)
	{
		if(list.Head->n > 32 && list.Head->n <= 126)
			printf("%c\n", list.Head->n);
		else
		{
			printf("L%d: can't pchar, value out of range\n", lin_num);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("L%d: can't pchar, stack empty\n", lin_num);
		exit (EXIT_FAILURE);
	}
}

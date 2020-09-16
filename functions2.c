#include "monty.h"
/**
 * _add- add the two nodes on the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _add(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size > 1)
	{
		int Number1, Number2;

		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		Push_Stack(&list, Number2 + Number1);
	}
	else
	{
		printf("L%d: can't add, stack too short\n", lin_num);
		exit(EXIT_FAILURE);
	}
}
/**
 * _sub- substract the two nodes on the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
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
		exit(EXIT_FAILURE);
	}
}
/**
 * _mul- multiply  the two nodes on the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
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
		exit(EXIT_FAILURE);
	}
}

/**
 * _div- divide the two nodes on the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
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
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod- get the module between the two nodes on the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
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
		exit(EXIT_FAILURE);
	}
}
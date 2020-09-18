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
		fprintf(stderr, "L%d: can't add, stack too short\n", lin_num);
		free(list.inst_oper[0]);
		fclose(list.Fd);
		Destroy(&list);
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", lin_num);
		free(list.inst_oper[0]);
		fclose(list.Fd);
		Destroy(&list);
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", lin_num);
		free(list.inst_oper[0]);
		fclose(list.Fd);
		Destroy(&list);
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

	int Number1, Number2;
	(void)stack;

	if (list.Size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lin_num);
		free(list.inst_oper[0]), fclose(list.Fd);
		Destroy(&list), exit(EXIT_FAILURE);
	}
	else
	{
		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		if (Number1 == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", lin_num);
			free(list.inst_oper[0]), fclose(list.Fd);
			Destroy(&list), exit(EXIT_FAILURE);
		}
		Push_Stack(&list, Number2 / Number1);
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
	int Number1, Number2;
	(void)stack;

	if (list.Size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lin_num);
		free(list.inst_oper[0]), fclose(list.Fd);
		Destroy(&list), exit(EXIT_FAILURE);
	}
	else
	{
		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);

		if (Number1 == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", lin_num);
			free(list.inst_oper[0]), fclose(list.Fd);
			Destroy(&list), exit(EXIT_FAILURE);
		}
		Push_Stack(&list, Number2 % Number1);
	}
}

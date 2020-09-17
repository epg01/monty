#include "monty.h"

/**
 * _push- insert new element on the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */

void _push(stack_t **stack, unsigned int lin_num)
{
	int index = 0;
	(void)stack;

	while (list.inst_oper[1] && (list.inst_oper)[1][index])
	{
		if ((isdigit((list.inst_oper)[1][index])))
			index++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", lin_num);
			free(list.inst_oper[0]);
			fclose(list.Fd);
			Destroy(&list);
			exit(EXIT_FAILURE);
		}
	}
	if (list.inst_oper[1])
		Push_Stack(&list, atoi((list.inst_oper)[1]));
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lin_num);
		free(list.inst_oper[0]);
		fclose(list.Fd);
		Destroy(&list);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pall- prints the first element at the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _pall(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	if (list.Size)
		Pall(list.Head);
}
/**
 * _pint- prints the element of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _pint(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	if (list.Size)
		printf("%d\n", list.Head->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lin_num);
		free(list.inst_oper[0]);
		fclose(list.Fd);
		Destroy(&list);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pop- remove the element at the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _pop(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	if (list.Size)
		Pop_Stack(&list);
	else
	{
		printf("L%d: can't pop an empty stack", lin_num);
		exit(EXIT_FAILURE);
	}
}
/**
 * _swap-swap the two elements of the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _swap(stack_t **stack, unsigned int lin_num)
{
	int number1 =  0, number2 = 0;
	(void)stack;
	if (list.Size)
	{
		number1 = Pop_Stack(&list);
		number2 = Pop_Stack(&list);
		Push_Stack(&list, number1);
		Push_Stack(&list, number2);
	}
	else
	{
	printf("L%d: can't swap, stack too shortc\n", lin_num);
		exit(EXIT_FAILURE);
	}
}

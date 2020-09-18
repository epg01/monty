#include "monty.h"
/**
 * _rotr - rotates the stack the last eleemnt to the top.
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 */

void _rotr(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	if (list.Size)
	{
		stack_t *tmp;

		tmp = list.Tail;/*rotación igual al último elemento*/
		tmp->next = list.Head;/* el ultimo le apunta al siguiente*/
		list.Head->prev = tmp;/*conecto el primero con el rotado*/
		list.Tail = list.Tail->prev; /*la cola le apunta al penúltimo*/
		tmp->prev->next = NULL; /* desconecto el penultimo del último*/
		list.Head = tmp;
	}
}

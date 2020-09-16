#include "monty.h"
/**
 * Push_Stack- add new node at the top of the queue
 * @list: pointer to strcture
 * @Data: nvalue of element
 * Return: new node
 */
int Push_Stack(List *list, int Data)
{
	return (List_Ins_Next(list, NULL, Data));
}
/**
 * Push_Queue- add new node at the top of the queue
 * @list: pointer to strcture
 * @Data: value of element
 * Return: the new node
 */
int Push_Queue(List *list, int Data)
{
	return (List_Ins_Next(list, List_Tail(list), Data));
}

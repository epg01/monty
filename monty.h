#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

typedef struct List_
{
        int Size;
        struct stack_s *Head;
        struct stack_s *Tail;
}List;

/*
 * Macros
 */

#define List_Size(list)   ((list)->Size)
#define List_Next(list)   ((list)->next)
#define list_Head(list)   ((list)->head)
#define List_Tail(list)   ((list)->Tail)

/*
 * Function of the data structure.
 */

int List_Ins_Next(List *list, stack_t *Element, int Data);
int Push_Stack(List *list, int Data);
int Push_Queue(List *list, int Data);
void Pall(stack_t *Element);

/* extern variables*/

char *inst_oper[2];
unsigned int line_num;
List list;

/*fn tokenaze and, open and read file*/

void (*get_op(char *inst_oper))(stack_t **stack, unsigned int lin_num);

/* functions to instructions*/

void _push(stack_t **stack, unsigned int lin_num);
void _pall(stack_t **stack, unsigned int lin_num);


#endif

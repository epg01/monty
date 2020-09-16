#include "monty.h"
 
int List_Ins_Next(List *list, stack_t *Element, int Data)
{
        stack_t *New_Element = NULL;
        New_Element = (stack_t *)malloc(sizeof(stack_t));
        
        if (!New_Element)
                return (1);
        
        New_Element->n = Data;
        if (!Element)
        {
		if (!List_Size(list))  
                        list->Tail  = New_Element;
		New_Element->next = list->Head;
		if (!list->Head)
                        New_Element->prev = list->Head;
		else
		{
                        New_Element->prev = list->Head->prev;
                        list->Head->prev  = New_Element;
		}
		list->Head = New_Element;
        }
        else
        {
		New_Element->next = Element->next;
		New_Element->prev = Element;
                  
		if (!Element->next)
		{
                        list->Tail    = New_Element;
                        Element->next = New_Element;
		}
		else
		{
                        Element->next->prev = New_Element;
                        Element->next       = New_Element;
		}
        }
        list->Size++;
        return (0);
}

void Pall(stack_t *Element)
{
	if (Element)
	{
		printf("%d\n", Element->n);
		Pall(Element->next);
	}
}

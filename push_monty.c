#include "monty.h"

/**
* instruction_push - pushes an element to the stack
* @stack: double pointer to the first node
* @line_number: value of new node
* Return: nothing
*/
void instruction_push(stack_t **stack, unsigned int line_number)
{
stack_t *element = malloc(sizeof(stack_t));
char *op;
int num;

if (element == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
op = strtok(NULL, DELIMS);
if (op == NULL || stack == NULL)
{
printf("L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
num = _strtol(op, line_number);
element->n = num;
element->prev = NULL;
element->next = *stack;
if (element->next != NULL)
(element->next)->prev = element;
*stack = element;
}

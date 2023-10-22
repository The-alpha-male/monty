#include "monty.h"

/**
 * print_stack - prints all the elements of a stack_t list.
 * @h: pointer to stack_t head
 * Return: the number of nodes
 */
size_t print_stack(const stack_t *h)
{
	int i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	/*add new node in the beginning of the list*/
	if (*head)
	{
		(*head)->prev = new_node;
		new_node->next = *head;
	}
	*head = new_node;

	return (new_node);
}

/**
 * add_stackint_end - add new node at the end of a stack_t list.
 * @head: pointer to head pointer
 * @n: integer value
 * Return: node address or null in fail
 */
stack_t *add_stackint_end(stack_t **head, const int n)
{
	stack_t *new_node, *current;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	/*add new node in the beginning of the list*/
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;

		new_node->prev = current;
		current->next = new_node;
	}

	return (new_node);
}

/**
 * free_stack - free all the elements of a stack_t list.
 * @head: pointer to stack_t
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head;
		head = head->next;
		if (current)
			free(current);
	}
}

/**
 * delete_top_node - free all the elements of a stack_t list.
 * @stack: pointer to stack_t
 */
void delete_top_node(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("Error: Stack is empty.\n");
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	temp->next = NULL;
	free(temp);
}

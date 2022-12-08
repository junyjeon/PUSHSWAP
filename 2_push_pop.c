#include "push_swap.h"

t_info	*lstnew(int val)
{
	t_info	*elem;

	elem = malloc(sizeof(elem));
	if (!elem)
		return (0);
	elem->prev = NULL;
	elem->val = val;
	elem->next = NULL;
	return (elem);
}

int	push_front(t_stack *s, int val)
{
	t_info *new;
	t_info *cur;

	new = lstnew(val);
	if (!s->bottom)
	{
		s->bottom = malloc(sizeof(a->bottom));
		s->top = malloc(sizeof(a->top));
		s->bottom->dir = new;
		s->top->dir = new;
		new->next = NULL;
	}
	else
	{
		s->bottom->dir->prev = new;
		new->next = s->bottom->dir;
		s->bottom->dir = new;
	}
	s->bottom->dir->index = 0;
	s->size++;
	cur = s->bottom->dir;
	while (cur)
	{
		cur = cur->next;
		cur->index++;
		printf("%zu\n", cur->index);
	}
}

int	push_front(t_stack *s, int val)
{
	t_info *new;
	t_info *cur;

	new = lstnew(val);
	if (!new)
		return (0);
	ft_lstadd_front(s->bottom, new);
	if (s->bottom->val == -1)
	{
		new->next = new;
		s->top = new;
	}
	else
	{
		new->next = s->top;
		s->top = new;
	}
	new->next = s->bottom;
	new->index = 0;
	s->size++;
	cur = s->bottom->dir;
	while (cur)
	{
		cur = cur->next;
		cur->index++;
		printf("%zu\n", cur->index);
	}
}


int	push_back(t_stack *s, int val)
{
	t_info *new;

	new = lstnew(val);
	if (!new)
		return (0);
	ft_lstadd_back(&s->bottom, new);
	if (s->bottom->val == -1)
	{
		new->prev = new;
		s->top = new;
	}
	else
	{
		new->prev = s->top;
		s->top = new;
	}
	new->next = NULL;
	new->index = s->size;
	s->size++;
	return (1);
}

int	pop_front(t_stack *s)
{
	int		front_val;
	t_info	*tmp;

	front_val = s->bottom->dir->val;
	if (!s->size)
		return (0);
	tmp = s->bottom->dir;
	s->bottom->dir = s->bottom->dir->next;
	s->bottom->dir->prev = NULL;
	s->size--;
	free(tmp);
	return (front_val);
}

int	pop_back(t_stack *s)
{
	int		back_val;
	t_info	*tmp;

	back_val = s->top->dir->val;
	if (!s->size)
		return (0);
	tmp = s->top->dir;
	s->top->dir = s->top->dir->prev;
	s->top->dir->next = NULL;
	s->size--;
	free(tmp);
	return (back_val);
}

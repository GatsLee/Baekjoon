#include <iostream>
#include <string>
using namespace std;

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*first;
}       t_stack;

t_node	*make_a_node(int data)
{
	t_node	*node;

	node = new t_node;
	node->num = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


void pop(t_stack *stack)
{
	int tmp;
	t_node	*next_top;
	t_node	*to_delete;

	if (stack->first == NULL)
	{
		cout<<-1<<'\n';
		return ;
	}
	to_delete = stack->first;
	if (to_delete->next == NULL)
	{
		tmp = to_delete->num;
		stack->first = NULL;
		cout<<tmp<<'\n';
		stack->size--;
		return ;
	}
	while (to_delete->next != NULL)
		to_delete = to_delete->next;
	tmp = to_delete->num;
	next_top = to_delete->prev;
	to_delete->prev = NULL;
	next_top->next = NULL;
	cout<<tmp<<'\n';
	stack->size--;
	return ;
}


void push(t_stack *stack, int data)
{
	t_node	*node;
	t_node	*tmp;

	node = make_a_node(data);
	if (stack->first == NULL)
	{
		stack->first = node;
		(stack->size)++;
		return ;
	}
	tmp = stack->first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	node->prev = tmp;
	tmp->next = node;
	(stack->size)++;
	return ;
}

void size(t_stack *stack)
{
	cout<<stack->size<<'\n';
	return ;
}

void empty(t_stack *stack)
{
	if (stack->first == NULL)
		cout<<1<<'\n';
	else
		cout<<0<<'\n';
}

void top(t_stack *stack)
{
	t_node *top;

	if (stack->first == NULL)
		cout<<-1<<'\n';
	else
	{
		top = stack->first;
		while (top->next != NULL)
			top = top->next;
		cout<<top->num<<'\n';
	}
}

void	ops_init(string ops, t_stack *stack)
{
	int num;

	if (ops == "pop")
		pop(stack);
	else if (ops == "push")
	{
		cin>>num;
		push(stack, num);
	}
	else if (ops == "size")
		size(stack);
	else if (ops == "empty")
		empty(stack);
	else
		 top(stack);
}

t_stack	*stack_init(void)
{
	t_stack	*one;

	one = new t_stack;
	one->first = NULL;
	one->size = 0;
	return (one);
}

int main(void)
{
	int ops_cnt;
	string str;
	t_stack	*one;

	cin>>ops_cnt;
	one = stack_init();
	while (ops_cnt--)
	{
		cin>>str;
		ops_init(str, one);
	}
}
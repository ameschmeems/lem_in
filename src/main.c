#include "../incl/lem_in.h"

t_list *get_input()
{
	t_list *head = NULL;
	t_list *node;
	char *line;
	while (42069)
	{
		line = get_next_line(0);
		if (!line)
			break;
		node = ft_lstnew((void *)line);
		ft_lstadd_back(&head, node);
	}
	return (head);
}

int main()
{
	t_list *input = get_input();
	t_list *temp = input;
	// while (temp)
	// {
	// 	ft_printf("%s", (char *)temp->content);
	// 	temp = temp->next;
	// }
	ft_lstclear(&input, free);
	return (0);
}
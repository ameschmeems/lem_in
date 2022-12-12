#include "../incl/lem_in.h"

t_list *get_input()
{
	t_list *head;
	t_list *test;
	char *line;
	while (69)
	{
		line = get_next_line(0);
		if (!line)
			break;
		test = ft_lstnew((void *)line);
		ft_lstadd_back(&head, test);
	}
	return (head);
}

int main()
{
	t_list *input = get_input();
	t_list *temp = input;
	while (temp)
	{
		ft_printf("%s", (char *)temp->content);
		temp = temp->next;
	}
	ft_printf("%d", ft_strlen("frog"));
	ft_lstclear(&input, free);
	return (0);
}
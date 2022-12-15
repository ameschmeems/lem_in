#include "../incl/lem_in.h"

//gets input. duh.
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

//can probably generalize the next 2 with ft_listiter or something, not sure if I care

//searches through all rooms to find a certain name, returns room pointer
t_room *find_room(char *name, t_room *start)
{
	if (!name || !start)
		return (NULL);
	t_room *temp = start;
	while (temp && temp->name && ft_strncmp(name, temp->name, ft_strlen(name) + 1))
		temp = temp->next;
	return (temp);
}

//finds the list element with content equals to addr and returns it. returns NULL if no existo or error
t_list *lst_find(void *addr, t_list *lst)
{
	if (!addr || !lst)
		return (NULL);
	t_list *temp = lst;
	while (temp && temp->content && temp->content != addr)
		temp = temp->next;
	return (temp);
}

//finds two room based on their names and adds links between them. Returns -1 if shit goes sideways
// int add_link(char *name1, char *name2)
int add_link(char *line)
{
	t_room *room1, *room2;
	char *name1, *name2;
	name1 = line;
	name2 = line;
	while (name2 && *name2 != 45)
		name2++;
	*name2 = 0;
	name2++;
	if (!name1 || !name2)
		return (-1);
	if (!(room1 = find_room(name1, start)) ||
		!(room2 = find_room(name2, start)))
		return (-1);
	if (!lst_find(&room2, room1->links))
		ft_lstadd_back(&room1->links, ft_lstnew((t_room *)room2));
	if (!lst_find(&room1, room2->links))
		ft_lstadd_back(&room2->links, ft_lstnew((t_room *)room1));
	return (0);
}

t_room *new_room(char *line)
{
	char *temp = line;
	while (temp && *temp != 32)
		temp++;
	if (!temp)
		return (NULL);
	else
		*temp = 0;
	t_room *new = ft_calloc(sizeof(t_room), 1);
	new->name = ft_strdup(line);
	new->ant = NULL;
	new->links = NULL;
	new->next = NULL;
	return (new);
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
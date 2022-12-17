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
		if (line[ft_strlen(line) - 1] == 10)
			line[ft_strlen(line) - 1] = 0;
		node = ft_lstnew((void *)line);
		ft_lstadd_back(&head, node);
	}
	return (head);
}

//can probably generalize the next 2 with ft_listiter or something, not sure if I care

//searches through all rooms to find a certain name, returns room pointer
t_room *find_room(char *name)
{
	if (!name || !g_start)
		return (NULL);
	t_room *temp = g_start;
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
	while (*name2 && *name2 != 45)
		name2++;
	*name2 = 0;
	name2++;
	if (!name1 || !name2)
		return (-1);
	if (!(room1 = find_room(name1)) ||
		!(room2 = find_room(name2)))
		return (-1);
	if (!lst_find(&room2, room1->links))
	{
		ft_lstadd_back(&room1->links, ft_lstnew((t_room *)room2));
	}
	if (!lst_find(&room1, room2->links))
	{
		ft_lstadd_back(&room2->links, ft_lstnew((t_room *)room1));
	}
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


//initializes ant array, g_start must already be initialized before
t_ant *init_ants(int n)
{
	if (n < 1 || !g_start)
		return (NULL);
	t_ant *ants = ft_calloc(sizeof(t_ant), n);
	for (int i = 0; i < n; i++)
	{
		ants[i].id = i;
		ants[i].room = g_start;
	}
	return (ants);
}

int add_room(t_room *room)
{
	if (!room || !g_start)
		return (-1);
	t_room *temp = g_start;
	while (temp->next)
		temp = temp->next;
	temp->next = room;
	return (0);
}

int init(t_list **input)
{
	int n = ft_atoi((char *)(*input)->content);
	t_list *temp = (*input)->next;
	t_room *newroom;
	char *line;
	while (temp)
	{
		line = (char *)temp->content;
		if (!ft_strncmp("##start", line, 8))
		{
			temp = temp->next;
			g_start = new_room((char *)temp->content);
		}
		else if (!ft_strncmp("##end", line, 6))
		{
			temp = temp->next;
			g_end = new_room((char *)temp->content);
			add_room(g_end);
		}
		else if (line[0] != 35 && \
				line[0] != 76 && \
				ft_strchr(line, 32))
		{
			newroom = new_room(line);
			add_room(newroom);
		}
		else
			add_link(line);
		if (temp)
			temp = temp->next;
	}
	if (!(g_ants = init_ants(n)))
		return (-1);
	return (0);
}

int lst_size(t_list **lst)
{
	t_list *temp = *lst;
	int n = 0;
	while (temp)
	{
		n++;
		temp = temp->next;
	}
	return (n);
}

void print_links(t_room *room)
{
	t_list *temp = room->links;
	while (temp)
	{
		printf(" %s", ((t_room *)(temp->content))->name);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	t_list *input = get_input();
	printf("%d\n", init(&input));
	// printf("%p\n%p\n%p", g_ants, g_start, g_end);
	t_room *temp = g_start;
	while (temp)
	{
		printf("room %s with %d links to:", temp->name, lst_size(&temp->links));
		print_links(temp);
		temp = temp->next;
	}
	printf("start is %s\n", g_start->name);
	printf("end is %s\n", g_end->name);
	ft_lstclear(&input, free);
	return (0);
}
#ifndef LEM_IN_H
#define LEM_IN_H
#include "../ft_printf/libft/libft.h"
#include "../gnl/get_next_line.h"
#include "../ft_printf/includes/ft_printf.h"
typedef struct s_ant
{
	int id;
	struct s_room *room;
} t_ant;

typedef struct s_room
{
	char *name;
	struct s_ant *ant;
	// struct s_room **links;
	t_list *links;
	struct s_room *next;
} t_room;

extern t_ant *ants;
extern t_room *start;
extern t_room *end;
#endif
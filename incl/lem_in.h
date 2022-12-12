#ifndef LEM_IN_H
#define LEM_IN_H

typedef struct s_ant
{
	int id;
	struct s_room *room;
} t_ant;

typedef struct s_room
{
	struct s_ant *ant;
	struct s_room **links;
	struct s_room *next;
} t_room;

extern t_ant *ants;

#endif
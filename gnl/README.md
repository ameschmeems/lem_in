# **get_next_line**
Get_next_line is a project from the 42 school with the goal of creating a function which will allow us to read from a file one line at a time. Files whose names end with 
*"\_bonus"* contain a version of the function, which allows get_next_line to work with multiple file descriptors.

## **Usage:**
```C
char  *get_next_line(int fd);
```
get_next_line returns a line read from the file descriptor fd as an allocated string. In case of error, or if the end of file was reached, get_next_line returns NULL.

## **Main concepts learned:**
* Static variables
* File descriptors
* Buffers

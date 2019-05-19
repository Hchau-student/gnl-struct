#ifndef STRUCT_H
# define STRUCT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 20

typedef struct				s_gnl
{
    char					*content;
    int						num;
}							t_gnl;

t_list			*ft_struct(char *put, int num, t_list **put_in);

#endif

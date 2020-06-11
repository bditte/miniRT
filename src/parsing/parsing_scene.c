#include "miniRT.h"

void    parse_r(char *line, t_scene *scene)
{
        char    tmp[5];
        int     i;
        int     j;
        int     n;

        n = 0;
        i = 1;
        while (line[i])
        {
                if (48 <= line[i] && line [i] <= 57)
                {
                        j = 0;
                        while (48 <= line[i] && line [i] <= 57)
                                tmp[j++] = line[i++];
                        tmp[j] = 0;
                        if (n == 0)
                                scene->width = ft_atoi(tmp);
                        else if (n == 1)
                                scene->height = ft_atoi(tmp);
                        else
                                error(-2);
                        n++;
                        i--;
                }
                i++;
        }
}

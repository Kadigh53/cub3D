#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>

#define CUB3D "MORABA3AT"

///////////////////////// get_next_line//////////////////////
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *keep);
size_t	ft_strlen(char *str);
int		ft_strchr( char *str, char c);
char	*ft_strdup( char *s);
char	*ft_strjoin(char *s1, char *s2);
/////////////////////////////////////////////////////////////

typedef struct s_data
{
    char **map_array;
    size_t map_width;
    size_t map_height;
    char **map_path;

    int x_pos;
    int y_pos;

    char player;
    char *n_path;
    char *s_path;
    char *w_path;
    char *e_path;
    char *f_path;
    char *c_path;

} t_data;

int     ft_parsing(int ac, char *av, t_data *data);
char	**ft_split(char const	*s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char    *ft_strdup_newline(char *line);
char	*ft_itoa(int n);
void    print_array(t_data *data);
void    print_map(t_data *data);
void    ft_fill_array(t_data *data, char *map);
void    ft_get_width(t_data *data);
void    get_path(t_data *data);
int     is_digit(char *str);
void    check_map(t_data *data);
void    check_name(char *map);
char    *ft_get_path(char *path);
char    *ft_get_color(char *path);
int     check_path(t_data *data);
void    allocate_map(t_data *data);

#endif
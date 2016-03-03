/*
** struct.h for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Fri Nov 27 18:03:07 2015 Maisonnave Florian
** Last update Mon Dec  7 17:46:39 2015 Maisonnave Florian
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <dirent.h>
# include <time.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>

typedef struct  s_my_struct
{
  DIR		*dirp;
  struct dirent *dp;
  struct stat	nfo;
  struct passwd	*name;
  struct group	*group;
  char		*time;
  int		len;
  int		i;
}		t_my_struct;

void	get_uid(t_my_struct);
int	main(int, char **);
void	ls_alone();
int	ls_mult(char **, int);
void	flags(int, char **);
int	tab(char **, char);
int	ls_l(char **);
void	rights(t_my_struct);
void	blocks(t_my_struct);
void	calc(char **, t_my_struct);
void	my_putchar(char);
void	my_putstr(char *);
void	my_putnbr(int);
char	*my_strcpy(char *, char *);
char	*my_strcat(char *, char *);
int	my_strlen(char *);
void	stats(char **, t_my_struct);
void	file(t_my_struct);

#endif /* !STRUCT_H_ */

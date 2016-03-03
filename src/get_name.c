/*
** get_name.c for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Nov 29 17:42:12 2015 Maisonnave Florian
** Last update Sun Nov 29 18:18:23 2015 Maisonnave Florian
*/

#include "struct.h"

void	get_uid(t_my_struct	s)
{
  struct passwd *name;

  name = getpwuid(s.nfo.st_uid);
  my_putstr(name->pw_name);
}

/*
** fonctions2.c for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Nov 29 18:41:47 2015 Maisonnave Florian
** Last update Sun Nov 29 19:20:24 2015 Maisonnave Florian
*/

#include "struct.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

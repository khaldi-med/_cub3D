#include "cub.h"

char *ft_skip_space(char *line) {
  int i = 0;
  if (!line)
    return NULL;
  while (line[i]) {
    if (line[i] != '\t' && line[i] != ' ')
      break;
    i++;
  }
  return (&line[i]);
}

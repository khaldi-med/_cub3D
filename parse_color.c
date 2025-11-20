#include "cub.h"
#include "libft/libft.h"
#include <stdbool.h>

bool ft_is_color_line(char *line) {
  char *new_line;
  if (!line)
    return false;
  new_line = ft_skip_space(line);
  if (!new_line)
    return false;
  if (ft_strncmp(new_line, "F ", 2) == 0)
    return true;
  if (ft_strncmp(new_line, "C ", 2) == 0)
    return true;
  return false;
}

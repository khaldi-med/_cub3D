#include "cub.h"
#include "libft/libft.h"

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

void ft_fill_rgb(t_config*config, char*line){
	
}

void ft_fill_color_line(t_config *config, char *line){
	if(ft_strncmp("F ", line, 2)==0)
		ft_fill_rgb(line);
	else if(ft_strncmp("C ", line, 2)==0)
		ft_fill_rgb(config, line);
}

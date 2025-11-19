#include "cub.h"

bool ft_is_texture_line(char *line) {
  if (!line)
    return false;
  char *new_line = ft_skip_space(line);
  if (!new_line)
    return false;
  if (ft_strncmp(new_line, "NO ", 3) == 0)
    return true;
  if (ft_strncmp(new_line, "SO ", 3) == 0)
    return true;
  if (ft_strncmp(new_line, "WE ", 3) == 0)
    return true;
  if (ft_strncmp(new_line, "EA ", 3) == 0)
    return true;
  return false;
}

char *ft_extract_path(char *line) {
  char *path;
  if (!line)
    return NULL;
  path = ft_skip_space(line);
  if (!path || ft_strlen(path) < 3)
    return NULL;
  path += 2;
  if (!path || path[0])
    return NULL;
  char *new_path = ft_strtrim(path, " \t\n");
  return new_path;
}

void ft_fill_path(t_config *config, char *line) {
  char *path;
  char *new_path;
  path = ft_skip_space(line);
  new_path = ft_extract_path(path);
  if (!new_path || ft_is_valid_path(new_path))
    ft_free_exit_err("file path not valide\n");
}

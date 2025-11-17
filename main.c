#include "cub.h"

bool ft_valid_arg(char *str) {
  int fd;

  fd = open(str, O_RDONLY);
  if (fd < 0) {
    perror("file not found\n");
    return (false);
  }
  close(fd);
  if (ft_strcmp(str, "./map.cub") == 0)
    return (true);
  return (false);
}

char *ft_parce_map_file(char *str) {
  char *line;
  int fd;

  line = NULL;
  if (!ft_valid_arg(str))
    return (NULL);
  fd = open(str, O_RDONLY);
  if (fd < 0) {
    perror("open");
    return (NULL);
  }
  line = ft_get_next_line(fd);
  close(fd);
  return (line);
}

int main(int ac, char **av) {
  char *line;

  if (ac != 2) {
    perror("Error: argument not valid\n");
    exit(EXIT_FAILURE);
  }
  line = ft_parce_map_file(av[1]);
  if (!line) {
    perror("Error: failed to read map file\n");
    exit(EXIT_FAILURE);
  }
  printf("%s\n", line);
  free(line);
  // free(map);
  return (0);
}
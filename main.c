#include "cub.h"

bool ft_valid_path(char *str) {
  int file_fd;

  file_fd = open(str, O_WRONLY);
  if (file_fd < 0) {
    perror("file not found\n");
    return (false);
  }
  if (strstr(str, ".cub")) {
    return (true);
  }
  return (false);
}

int main(int argc, char **argv) {
  char *line;
  int file_fd;

  line = NULL;
  if (argc != 2) {
    perror("Error: argument not valid\n");
    exit(EXIT_FAILURE);
  }
  if (!ft_valid_path(argv[1])) {
    return (1);
  }
  file_fd = open(argv[1], O_WRONLY);
  if (file_fd < 0) {
    perror("open");
    return (1);
  }
  line = ft_get_next_line(file_fd);
  if (!line)
    printf("empty line\n");
  while (line != NULL) {
    printf("%s", line);
    free(line);
    line = ft_get_next_line(file_fd);
  }
  close(file_fd);
  return (0);
}

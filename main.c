#include "./cub.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ft_valid_file(char *file) {
  size_t len = ft_strlen(file);
  if (len < 5) {
    perror("file");
    return (false);
  }
  char *extention = ft_strchr(file, '.');
  if (ft_strcmp(".cub", extention) != 0)
    return false;
  return true;
}

int ft_open_file(char *str) {
  int fd;

  fd = open(str, O_RDONLY);
  if (fd < 0) {
    perror("file not found\n");
    return (-1);
  }
  return (fd);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    perror("Error: argument not valid\n");
    return (EXIT_FAILURE);
  }
  if (!ft_open_file(argv[1]))
    return (EXIT_FAILURE);
  if (ft_valid_file(argv[1]))
    printf("the file exiseted!");
  return (0);
}

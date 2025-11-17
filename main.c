#include "cub.h"
#include "libft/libft.h"
#include <complex.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

bool ft_valid_arg(char *str) {
  int fd;
  fd = open(str, O_RDONLY);
  if (fd <= 0) {
    perror("argummment note valide");
    return false;
  } else {
    if (ft_strcmp(str, "./map.cub") == 0) {
      return true;
    }
  }
  return false;
}

int main(int ac, char **av) {
  if (ac != 2) {
    /* TODO:  write the error func */
    // ft_error(ac);
    perror("Error: argummment not valid\n");
  }
  if (ft_valid_arg(av[1]))
    printf("the file is exicted!\n");
  else {
    perror("the file not exicted\n");
  };
  /* TODO:  ft_pacre */
  // ft_parce(av[1]);
  return (0);
}

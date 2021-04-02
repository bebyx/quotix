#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include "quotix.h"

int main(int argc, char const *argv[]) {
  /*
  open file with a quote per line
  check number of lines
  choose one of the lines randomly
  display a quote from a chosen line
  clean, close file, etc.

  check if first argument exists to point to the file of default to quotes.txt
  options for time in seed
  */

  FILE *fptr;
  const char filename[] = "quotes.txt";
  int lines_count;

  check_file(filename);

  lines_count = count_lines(filename);

  print_random_quote(filename, lines_count);

  return 0;
}

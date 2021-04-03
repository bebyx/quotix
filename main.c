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

  check if first argument exists to point to the file or default to quotes.txt
  options for time in seed
  */
  char filename[] = "quotes.txt";
  int lines_count;

  for (size_t i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-f") == 0 ||
        strcmp(argv[i], "--file") == 0) {
      if (argv[i+1] != NULL) {
        strcpy(filename, argv[i+1]);
      } else {
        printf("No file name stated.\n");
        exit(EXIT_FAILURE);
      }
      i++;
    } else if (argc == 2 &&
               (strcmp(argv[i], "-h") == 0 ||
                strcmp(argv[i], "--help") == 0)) {
      printf("%s\n", "Use -f or --file flag to define source file name with quotes.");
      exit(0);
    } else {
      printf("Wrong flag: '%s'\n", argv[i]);
      exit(EXIT_FAILURE);
    }
  }

  check_file(filename);

  lines_count = count_lines(filename);

  print_random_quote(filename, lines_count);

  return 0;
}

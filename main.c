#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include "quotix.h"

int main(int argc, char const *argv[])
{

  char filename[] = "quotes.txt";
  int lines_count;
  char iteration[] = "second";

  // Opts handling chunk
  for (size_t i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-f") == 0 ||
        strcmp(argv[i], "--file") == 0)
    {
      if (argv[i+1] != NULL)
      {
        strcpy(filename, argv[i+1]);
      }
      else
      {
        printf("Error: No file name is stated.\n");
        exit(EXIT_FAILURE);
      }
      i++;
    }
    else if (strcmp(argv[i], "-i") == 0)
    {
      if (argv[i+1] != NULL)
      {
        if (strcmp(argv[i+1], "%M") == 0 ||
            strcmp(argv[i+1], "minute") == 0)
          strcpy(iteration, "minute");
        else if (strcmp(argv[i+1], "%H") == 0 ||
                 strcmp(argv[i+1], "hour") == 0)
          strcpy(iteration, "hour");
        else if (strcmp(argv[i+1], "%d") == 0 ||
                 strcmp(argv[i+1], "day") == 0)
          strcpy(iteration, "day");
        else
          printf("Iterator is not understood. Go with default (seconds).\n");
        i++;
      }
      else
      {
        printf("Error: No iterator is stated.\n");
        exit(EXIT_FAILURE);
      }
    }
    else if (argc == 2 &&
               (strcmp(argv[i], "-h") == 0 ||
                strcmp(argv[i], "--help") == 0))
    {
      printf("%s\n", "Use -f or --file flag to define source file name with quotes.");
      exit(0);
    }
    else
    {
      printf("Wrong flag: '%s'\n", argv[i]);
      exit(EXIT_FAILURE);
    }
  }

  //Program's functions

  check_file(filename);

  lines_count = count_lines(filename);

  seed_random(iteration);

  print_random_quote(filename, lines_count);

  return 0;
}

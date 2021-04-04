#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include "quotix.h"

int main(int argc, char const *argv[])
{

  char filename[256] = "quotes.txt";
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
        fprintf(stderr, "%s\n", "Error: No file name is stated.");
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
          fprintf(stderr, "%s\n", "Iterator is not understood. Go with default (seconds).");
        i++;
      }
      else
      {
        fprintf(stderr, "%s\n", "Error: No iterator is stated.");
        exit(EXIT_FAILURE);
      }
    }
    else if (argc == 2 &&
               (strcmp(argv[i], "-h") == 0 ||
                strcmp(argv[i], "--help") == 0))
    {
      fprintf(stdout, "%s\n\n%s\n%s\n%s\n%s\n%s\n",
                      "Quotix (qtx) is a random quote C program. It runs through a plain text file (named quotes.txt by default) and prints out a random line.",
                      "Use -f or --file flag to define source file name with quotes.",
                      "Use -i to change the time iteration (each second by default):",
                      "- %M or 'minute'",
                      "- %H or 'hour'",
                      "- %d or 'day'");
      exit(0);
    }
    else
    {
      fprintf(stderr, "Wrong flag: '%s'\n", argv[i]);
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

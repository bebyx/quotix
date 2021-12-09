#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>

#include "core.h"
#include "checks.h"

int main(int argc, char **argv)
{
  char filename[256] = "/usr/local/share/quotix/quotes.list";
  char iteration[] = "second";
  int c;

  // Opts chunk
  while (1)
  {
    static struct option long_options[] =
    {
      {"file", required_argument, 0, 'f'},
      {"iterate", required_argument, 0, 'i'},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}
    };

    int option_index = 0;

    c = getopt_long (argc, argv, "f:i:h",
                     long_options, &option_index);

    if (c == -1)
      break;

    switch (c)
    {
      case 'h':
        fprintf(stdout, "%s\n\n%s\n%s\n%s\n%s\n%s\n",
                "Quotix (qtx) is a random quote C program. "
                "It runs through a plain text file "
                "(/usr/local/share/quotix/quotes.list by default) "
                "and prints out a random line.",
                "Use -f or --file flag to define source file name with quotes.",
                "Use -i or --iterate to change the time iteration (each second by default):",
                "- %M or 'minute'",
                "- %H or 'hour'",
                "- %d or 'day'");
        return(0);

      case 'f':
        strcpy(filename, optarg);
        break;

      case 'i':
        if (strcmp(optarg, "%M") == 0 ||
            strcmp(optarg, "minute") == 0)
          strcpy(iteration, "minute");
        else if (strcmp(optarg, "%H") == 0 ||
                 strcmp(optarg, "hour") == 0)
          strcpy(iteration, "hour");
        else if (strcmp(optarg, "%d") == 0 ||
                 strcmp(optarg, "day") == 0)
          strcpy(iteration, "day");
        else
          fprintf(stderr, "%s\n", "Iterator is not understood. Going with default (seconds).");
        break;

      case '?':
        fprintf(stderr, "Wrong flag: %c\n", optopt);
        exit(EXIT_FAILURE);
        break;

      default:
        abort();
      }
  }

  // Print error, if unknown arguments are used
  if (optind < argc)
  {
    fprintf (stderr, "Unknown input: ");
    while (optind < argc)
      fprintf (stderr, "%s ", argv[optind++]);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
  }

  //Program functions

  check_file(filename);

  seed_random(iteration);

  print_random_quote(filename);

  return 0;
}

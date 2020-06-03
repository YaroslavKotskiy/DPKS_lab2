#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int
main (int argc, char **argv)
{
  int c;

  while (1)
    {
      static struct option long_options[] =
        {
          {"help",      no_argument,      0, 'h'},
          {"force",    no_argument,       0, 'f'},
          {"list",     optional_argument, 0, 'l'},
          {"kill",     required_argument, 0, 'k'},
          {"value",    required_argument, 0, 'v'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "hfl:k:v:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
         
        case 'h':
          puts ("Here is help message\n");
          break;

        case 'f':
          puts ("Force execution\n");
          break;

        case 'k':
          printf ("Kill procces with arg -`%s'\n", optarg);
          break;


        case 'v':
          printf ("Input value: `%s'\n", optarg);
          break;

        case 'l':
          printf ("List command with value `%s'\n", optarg);
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("invalid arguments: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}

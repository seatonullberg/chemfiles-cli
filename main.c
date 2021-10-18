#include <stdio.h>
#include <stdlib.h>

#include "argparse/argparse.h"

/* program usage string */
static const char *const usage[] = {
    "cf [options] [--] <src> <dst>",
    NULL,
};

/* program description */
static const char *const description =
    "A simple chemistry file conversion CLI which wraps the chemfiles library";

/* program epilogue */
static const char *const epilogue =
    "\nAuthor: Seaton Ullberg <seatonullberg@gmail.com>\nVersion: 0.1.0";

int main(int argc, const char **argv) {
  /* initialize positional arguments */
  const char *src = NULL;
  const char *dst = NULL;

  /* initialize options */
  const char *in_fmt = NULL;
  const char *out_fmt = NULL;

  /* define all options */
  struct argparse_option options[] = {
      OPT_HELP(),
      OPT_STRING('i', "in-fmt", &in_fmt, "format of the input file"),
      OPT_STRING('o', "out-fmt", &out_fmt, "format of the output file"),
      OPT_END(),
  };

  /* create the argument parser */
  struct argparse argparse;
  argparse_init(&argparse, options, usage, 0);
  argparse_describe(&argparse, description, epilogue);

  /* parse the arguments */
  argc = argparse_parse(&argparse, argc, argv);
  src = argv[0];
  dst = argv[1];

  printf("src = %s\n", src);
  printf("dst = %s\n", dst);
  printf("in-fmt = %s\n", in_fmt);
  printf("out-fmt = %s\n", out_fmt);

  return 0;
}
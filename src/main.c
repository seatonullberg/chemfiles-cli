#include <stdio.h>
#include <stdlib.h>

#include "argparse.h"
#include "chemfiles.h"

#include "config.h"

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
  /* iteration counter */
  int i;

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

  
  /* read a trajectory from the input file */
  CHFL_TRAJECTORY* in_trajectory = NULL;
  if (in_fmt == NULL)
    in_trajectory = chfl_trajectory_open(src, 'r');
  else
   in_trajectory = chfl_trajectory_with_format(src, 'r', in_fmt);

  /* determine the number of frames (steps) in the input trajectory */
  uint64_t nframes = 0;
  chfl_trajectory_nsteps(in_trajectory, &nframes);


  /* initialize the necessary number of frames */
  CHFL_FRAME* frames[nframes];

  /* read each frame from the input trajectory */
  for (i = 0; i < nframes; i++) {
      CHFL_FRAME* frame = chfl_frame();
      chfl_trajectory_read(in_trajectory, frame);
      frames[i] = frame;
  }

  /* create an empty output trajectory with the desired format */
  CHFL_TRAJECTORY* out_trajectory = NULL;
  if (out_fmt == NULL)
    out_trajectory = chfl_trajectory_open(dst, 'a');
  else
    out_trajectory = chfl_trajectory_with_format(dst, 'a', out_fmt);

  /* write each frame from the input trajectory into the output trajectory */
  for (i = 0; i < nframes; i++) {
      chfl_trajectory_write(out_trajectory, frames[i]);
  }

  return 0;
}
#include "uniconv.h"

void print_usage() {
  fprintf(stderr, "Usage:\n");
  fprintf(stderr, "\n");
  fprintf(stderr,
          "convert [-t t|T|d|D|a|A|v|V|m|M] [-i <number><unit>] [-o <unit>] "
          "[...options]");
}

void print_help() { printf("HELP MENU\n"); }
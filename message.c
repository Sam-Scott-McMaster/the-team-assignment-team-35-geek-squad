#include "uniconv.h"

void print_usage() {
  fprintf(stderr, "Usage:\n");
  fprintf(stderr, "\n");
  fprintf(stderr,
          "convert [-t t|T|d|D|a|A|v|V|m|M] [-i <number><unit>] [-o <unit>] "
          "[...options]");
}

void print_help() {
  printf("HELP MENU\n");
  printf("Options:\n");
  printf("  -t TYPE             Specify the type of conversions.\n");
  printf("                      t|T: Temprature\n");
  printf("                      d|D: Distance\n");
  printf("                      a|A: Area\n");
  printf("                      v|V: Volume\n");
  printf("");
}
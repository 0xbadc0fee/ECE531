/*************************
* _               _       
*| |             | |      
*| |__   __ _  __| |      
*| '_ \ / _` |/ _` |      
*| |_) | (_| | (_| |      
*|_.__/ \__,_|\__,_|      
*      _____  __          
*     |  _  |/ _|         
*  ___| |/' | |_ ___  ___ 
* / __|  /| |  _/ _ \/ _ \
*| (__\ |_/ / ||  __/  __/
* \___|\___/|_| \___|\___|
*
************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct arguments
{
  int a;
  int b;
  int c;
  int area;
  int perimeter;
};


void print_usage(){
  printf("Usage: triangle [Ap] -a num -b num -c num\n");
}

int main(int argc, char *argv[]) {
  int opt= 0;
  struct arguments arguments;

  /* Default values. */
  arguments.a = -1;
  arguments.b = -1;
  arguments.c = -1;
  arguments.area = 0;
  arguments.perimeter = 0;


  static struct option long_options[] = {
    {"area",      no_argument,       0,    'A'},
    {"perimeter", no_argument,       0,    'p'},
    {"hypotenuse",required_argument, 0,    'c'},
    {"opposite",  required_argument, 0,    'a'},
    {"adjacent",  required_argument, 0,    'b'},
    {0,           0,                 0,     0 }
  };

  int long_index =0;
  while ((opt = getopt_long(argc, argv, "Apa:b:c:",
                            long_options, &long_index )) != -1) {
    switch (opt) {
    case 'A':
      arguments.area = 1;
      break;
    case 'p':
      arguments.perimeter = 1;
      break;
    case 'a':
      arguments.a = atoi(optarg);
      break;
    case 'b':
      arguments.b = atoi(optarg);
      break;
    case 'c':
      arguments.c = atoi(optarg);
      break;
    default: print_usage();
      exit(EXIT_FAILURE);
    }
  }

  if (arguments.a == -1 || arguments.b == -1 || arguments.c == -1) {
    print_usage();
    exit(EXIT_FAILURE);
  }

  if (arguments.area){
    arguments.area = (arguments.a*arguments.b)/2;
    printf("Area: %d\n", arguments.area);
  }

  if (arguments.perimeter) {
    arguments.perimeter = arguments.a + arguments.b + arguments.c;
    printf("Perimeter: %d\n", arguments.perimeter);
  }

  return 0;
}

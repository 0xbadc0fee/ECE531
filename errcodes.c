#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Opt
{
    int opts[3];    //   e       h      s
    char *word,
         *tag;
} Opt;

enum E_Numbers { USAGE_ERROR };

static void error_exit(enum E_Numbers e, const char *tag)
{
    fprintf(stderr, "%d: %s\n", e, tag);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    Opt options = { { 0 }, 0, 0 };
    int args;
    while((args = getopt(argc, argv, "ehs:")) != -1){
        switch (args) {
            case 'e':
                if (options.opts[0] == 1)
                    error_exit(USAGE_ERROR, "option multiple times");
                else
                    options.opts[0] = 1;
                break;
            case 'h':
                if (options.opts[1] == 1)
                    error_exit(USAGE_ERROR, "option multiple times");
                else
                    options.opts[1] = 1;
                break;
            case 's':
                if (options.opts[2] == 2)
                    error_exit(USAGE_ERROR, "option multiple times");
                else
                    options.opts[2] = 2;
                char *saveptr;
                if((options.word = strtok_r(optarg, ":", &saveptr)) == NULL)
                    error_exit(USAGE_ERROR, "WORD MISSING");
                if((options.tag  = strtok_r(NULL, ":", &saveptr)) == NULL)
                    error_exit(USAGE_ERROR, "TAG MISSING");
                char *temp = NULL;
                if((temp = strtok_r(NULL, ":", &saveptr)))
                    error_exit(USAGE_ERROR, "WORD and TAG already set!");
                break;
            case '?': //Never enters this case or default. WHY???
            default:
                error_exit(USAGE_ERROR, "Unexpected option");
                break;
        }
    }

    printf("e = %d, h = %d, s = %d\n", options.opts[0], options.opts[1], options.opts[2]);
    printf("word = <<%s>>\n", options.word ? options.word : "NULL");
    printf("tag  = <<%s>>\n", options.tag  ? options.tag  : "NULL");

    return 0;
}

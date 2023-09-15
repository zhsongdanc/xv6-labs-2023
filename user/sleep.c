#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

    if(argc < 2){
        fprintf(2, "error usage\n");
        exit(1);
    }

    const char* arg1 = argv[1];
    int time = atoi(arg1);
    sleep(time);


    exit(0);
}

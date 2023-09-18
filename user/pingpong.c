#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

//todo note: 一个进程中，关闭管道读端后，就不能读；关闭管道写端后，就不能写

int main(int argc, char *argv[]) {



    int pfd[2];

    if (pipe(pfd) == -1) {
        fprintf(2, "pipe error...\n");
        exit(1);
    }

    int pid = fork();
    if (pid == -1) {
        fprintf(2, "fork error...\n");
        exit(1);
    } else if (pid == 0) {

        char buffer[4];
        read(pfd[0], buffer, 4);
        fprintf(1, "%d: received %s\n", pid, buffer);

        close(pfd[0]);


        char str[] = "pong";
        write(pfd[1], str, 4);
        close(pfd[1]);


        exit(0);
    } else {
        char str[] = "ping";
        write(pfd[1], str, 4);
        wait(0);

        close(pfd[1]);
        char buffer[4];
        read(pfd[0], buffer, 4);
        fprintf(1, "%d: received %s\n", pid, buffer);
        close(pfd[0]);

        exit(0);

    }

}
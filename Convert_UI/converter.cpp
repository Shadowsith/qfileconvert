#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int convert(const char* input_file, const char* output_file){
    int pid, status;

    if(pid = fork()) {
        waitpid(pid, &status, 0);
    }
    else{
        const char exec[] = "/usr/bin/convert";
        execl(exec,exec,input_file, output_file, NULL);
    }
    return status;
}

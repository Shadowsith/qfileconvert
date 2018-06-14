#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/wait.h>

int convertImg(std::string input, std::string output){
    int pid, status;

    if(pid == fork()) {
        waitpid(pid, &status, 0);
    }
    else{
        const char exec[] = "/usr/bin/convert";
        execl(exec,exec,input.c_str(), output.c_str(), NULL);
    }
    return status;
}

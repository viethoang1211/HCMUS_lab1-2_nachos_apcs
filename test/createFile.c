#include "syscall.h"


int main(int x, char* argv[]){
    char* filename;
    Write("Input filename: ",string_length,1);
    Read(filename,string_length,0);
    if(Create(filename)==0){
        Write("Create successful\n",string_length,1);
    }
    else{
        Write("Create unsuccessful\n",string_length,1);
    }
    return 0;
}

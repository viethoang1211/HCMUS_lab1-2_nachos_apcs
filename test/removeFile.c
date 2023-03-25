#include "syscall.h"


int main(){
    int id;
    char* filename;
    Write("Input filename to read: ",string_length,1);
    Read(filename,string_length,0);
    id =Open(filename,1);
    if(Remove("testCreateFile.txt")==0){
        Write("Remove success",string_length,1);
    }
    else Write("Remove unsuccess",string_length,1);
    return 0;
}

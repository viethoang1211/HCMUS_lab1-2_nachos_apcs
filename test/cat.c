#include "syscall.h"

int main(int x, char* argv[]){
    char filename[string_length];
    char content[string_length];
    int id;
    int len;
    Wait("write_std");
    Write("Input filename to read: ",string_length,1);
    Read(filename,string_length,0);
    Signal("write_std");
    id = Open(filename,1);  // open file
    if(id!=-1){
        len=Seek(-1,id);    // find length of file
        Seek(0,id);         // move cursor back to the beginning
        Read(content,len,id);   // read content into char* content
        content[len]='\n';  // add linefeed to read easily on console
        Write(content,len+1,1);    // write content to console
        Close(id);
    }
    else{
        Write("Open unsuccessful\n",string_length,1);
    }
    Write("cat!",5,1);
    return 0;
}
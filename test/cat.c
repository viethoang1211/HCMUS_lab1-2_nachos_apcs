#include "syscall.h"

int main(int x, char* argv[]){
    char* filename;
    int id;
    int len;
    char* content;
    Write("Input filename to read: \n ",string_length,1);
    Read(filename,string_length,0);
    
    id = Open(filename,1);  // open file
    if(id!=-1){
            

        len=Seek(-1,id);    // find length of file
        Seek(0,id);         // move cursor back to the beginning
        Read(content,len,id);   // read content into char* content
        content[len]='\n';  // add linefeed to read easily on console
        Write(content,len + 1,1);    // write content to console
        Close(id);
    }
    else{
        Write("Open unsuccessful\n",string_length,1);
    }
    return 0;
}
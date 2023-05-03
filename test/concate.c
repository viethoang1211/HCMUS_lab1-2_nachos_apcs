#include "syscall.h"

int main(int x, char* argv[]){
    char src_1[string_length], src_2[string_length];
    char content[string_length];
    int id_src_1;
    int id_src_2;
    int len;
    int t;

    Write("Input src 1 filename: ",string_length,1);
    Read(src_1,string_length,0);

    if((id_src_1 = Open(src_1,1))==-1){
        Write("Open src 1 failed\n",string_length,1);
    }  
    else{
        len=Seek(-1,id_src_1);    // find length of file
        Seek(0,id_src_1);         // move cursor back to the beginning
        Read(content,len,id_src_1);   // read content into char* content
        
        Write("Input src 2 filename: ",string_length,1);
        Read(src_2,string_length,0);
        
        if((id_src_2 = Open(src_2,0))==-1){
            Write("Open src 2 failed\n",string_length,1);
        }  
        else{
            Seek(-1,id_src_2);
            t=Write(content,len,id_src_2);    // write content to des
            if(t!=-1) Write("write success\n",string_length,1);
            Close(id_src_2);
        }
        Close(id_src_1);
    }
    return 0;
}
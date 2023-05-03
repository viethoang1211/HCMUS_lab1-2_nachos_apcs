#include "syscall.h"

int main(int x, char* argv[]){
    char src[string_length], des[string_length];
    char content[string_length];
    int id_src;
    int id_des;
    int len;
    int t;

    Write("Input src filename:",string_length,1);
    Read(src,string_length,0);

    if((id_src = Open(src,1))==-1){
        Write("Open src failed\n",string_length,1);
    }  
    else{
        len=Seek(-1,id_src);    // find length of file
        Seek(0,id_src);         // move cursor back to the beginning
        Read(content,len,id_src);   // read content into char* content
        
        Write("Input destination filename: ",string_length,1);
        Read(des,string_length,0);
        Create(des);
        
        if((id_des = Open(des,0))==-1){
            Write("Open des failed\n",string_length,1);
        }  
        else{
            Seek(0,id_des);
            t=Write(content,len,id_des);    // write content to des
            if(t!=-1) Write("write success\n",string_length,1);
            Close(id_des);
        }
        Close(id_src);
    }
    return 0;
}
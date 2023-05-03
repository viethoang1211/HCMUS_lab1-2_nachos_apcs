
#include "syscall.h"

int main()
{
    char str1[string_length], str2[string_length];
    int write1, tem1;
    SpaceId newProc1;
    // SpaceId newProc2;
    CreateSemaphore("write_std",1);
    // SpaceId newProc3;

    // newProc1 = Exec("cat"); // Project 01
    // newProc2 = Exec("copy"); // Project 01


    // Join(newProc1);
    // Join(newProc2);
    // Join(newProc3);
    while(1){
        Wait("write_std");
        write1 = Read(str1,string_length,0);
        if(write1==-1 || Strcmp(str1,"quit")==0){
            break;
        }
        Signal("write_std");
        newProc1 = Exec(str1); // Project 01
        tem1 =Join(newProc1);  
    }
}
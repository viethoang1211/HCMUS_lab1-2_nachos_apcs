
#include "syscall.h"

int main()
{
    char str1[string_length], str2[string_length];
    int tem1;
    SpaceId newProc1;
    SpaceId newProc2;
    // SpaceId newProc3;

    newProc1 = Exec("createFile"); // Project 01
    newProc2 = Exec("ping"); // Project 01


    Join(newProc1);
    Join(newProc2);
    // Join(newProc3);
    // while(Read(str1,string_length,0)!=-1){
    //     newProc1 = Exec(str1); // Project 01
    //     tem1 =Join(newProc1);  
    // }
}
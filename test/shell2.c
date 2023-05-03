
#include "syscall.h"

int
main()
{
    int tem1;
    int tem2;
    SpaceId newProc1;
    SpaceId newProc2;

    newProc1 = Exec("cat"); // Project 01
    newProc2 = Exec("copy"); // Project 01

    tem1= Join(newProc1);
    tem2= Join(newProc2);
    if (tem1!=0) PrintNum(tem1);
    if (tem2!=0) PrintNum(tem2);

}
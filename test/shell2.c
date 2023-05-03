
#include "syscall.h"

int
main()
{
    int tem1;
    SpaceId newProc1;
    newProc1 = Exec("cat"); // Project 01
    tem1= Join(newProc1);
    if (tem1!=0) PrintNum(tem1);
}
#include <stdio.h>

int stat_var()
{
    static int statcount = 0;
    statcount++;
    return (statcount);
}

int nor_var()
{
    int norcount = 0;
    norcount++;
    return (norcount);
}

int main()
{
    printf("stat func1: %d   ", stat_var());
    printf("stat func2: %d   ", stat_var());
    printf("stat func3: %d  ", stat_var());
    printf("stat func4: %d  ", stat_var());
    printf("stat func5: %d\n", stat_var());

    printf("nor func1: %d  ", nor_var());
    printf("nor func2: %d  ", nor_var());
    printf("nor func3: %d  ", nor_var());
    printf("nor func4: %d  ", nor_var());
    printf("nor func5: %d \n", nor_var());




}
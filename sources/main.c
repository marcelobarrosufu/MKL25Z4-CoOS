#include "ARMCM0plus.h"
#include "core_cm0plus.h"
#include "CoOS.h"

#define STACK_SIZE 128

OS_STK  task_a_stk[STACK_SIZE];
OS_STK  task_b_stk[STACK_SIZE];
OS_STK  task_c_stk[STACK_SIZE];

void task_a (void* pdata) {

    for(;;) 
    {
        static int i = 0;
        i++;
    }
}

void task_b (void* pdata) {

    for(;;) 
    {
        static int i = 0;
        i++;
    }
}

void task_c (void* pdata) {

    for(;;) 
    {
        static int i = 0;
        i++;
    }
}

int main(void)
{
    //SysTick_Config(1000);
    CoInitOS();
    
    CoCreateTask(task_a,0,0,&task_a_stk[STACK_SIZE-1],STACK_SIZE);
    CoCreateTask(task_b,0,0,&task_a_stk[STACK_SIZE-1],STACK_SIZE);
    CoCreateTask(task_c,0,0,&task_a_stk[STACK_SIZE-1],STACK_SIZE);
    
    CoStartOS ();
    
    while(1);
}

/*
void SysTick_Handler(int v)
{
    static uint32_t counter = 0;
    counter++;
    return;
}
*/

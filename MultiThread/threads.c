#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
 int flag[2]; // global variable for accessing in both threads
void *Process1(void *vargp) 
{ 
    sleep(1);   // 1000ms
    printf("\n\nP1 enter CS \n"); 
    // critical section
    
    printf("P1 left CS");
}
void *Process2(void *vargp)
{    
    sleep(2);   // 2000ms
     printf("\n\nP2 enter CS \n"); 
    // critical section
    // for second process 
    printf("P2 left CS");
}
   
int main() 
{ 
    pthread_t thread_id,thread_id2; // this store  thread id
    while(2)  /// for infinite loop
    { 
    pthread_create(&thread_id, NULL, Process1, NULL);   // creating first thread 
    pthread_create(&thread_id2, NULL,Process2, NULL);     // creating second thread 
    pthread_join(thread_id, NULL);      /// it will wain untill thread is live
    pthread_join(thread_id2, NULL); 
    }
    printf("After Thread\n"); 
    exit(0); 
}

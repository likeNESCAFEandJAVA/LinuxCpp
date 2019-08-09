#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void* my_run_2(void* arg)
{
      while(1)
      {
            printf(  "thread 2 is running...\n");
            sleep(1);
      }
      return NULL;
}
int main(  )
{
      pthread_t tid;
      void *ret;
      pthread_create(&tid,NULL,my_run_2,NULL);
      sleep(1);

      pthread_cancel(tid);

      pthread_join(tid,&ret);
      if(ret==PTHREAD_CANCELED)
      {

	
        printf("thread  return,id is:%ld,return code:PTHREAD_CANCELED\n",tid);

      }
      else
      {

        printf("thread  return,id is:%ld,return code:NULL\n",tid);
      }

      return 0;
}


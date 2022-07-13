#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(void)
{
   struct timeval t0;
   struct timeval t1;
   float elapsed;
   
   long *data;
   long num, j,i;
   printf("enter number of elements: ");
   scanf("%ld",&num);
   data = (long *)malloc(sizeof(long)*num);
   
    srand( (unsigned) time(NULL) * getpid());
    
    int x,y,temp,position;

    if(data != NULL)
    {
        for(j = 0; j < num; j++)
        {
            data[j] = rand()%100;
        }
    }
    
   gettimeofday(&t0, NULL);

    for(x = 0; x < num - 1; x++)
    {
        position=x;
        for(y = x + 1; y < num; y++)
        {
            if(data[position] > data[y])
            {
                position=y;
            }
        }
        if(position != x)
        {
            temp=data[x];
            data[x]=data[position];
            data[position]=temp;
        }
    }
    
   gettimeofday(&t1, NULL);

   elapsed = timedifference_msec(t0, t1);
   printf("\telements are:\n");
   for(i=0;i<num;i++)
   {
   printf("%ld\t",data[i]);
   }

   printf("Code executed in %f milliseconds.\n", elapsed);

   return 0;
}

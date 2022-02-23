#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int SUM = 0;
#define P 20

void *func(void *i)
{
        SUM+=*(int*)i;

        return NULL;
}

int main(int argc, char **argv)
{
        int n=5;
        int v1[P] = {1, 2, 3, 4, 5}, v2[P] = {1, 2, 3, 4, 5}, v3[P];

        pthread_t threads[P];

        for (int i=0; i<n; i++)
        {
                int ok = pthread_create(&threads[i], NULL, func, (void*)&v1[i]);

                if (ok!=0)
                        printf("Error!\n");
        }

        for (int i=0; i<n; i++)
        {
                pthread_join(threads[i], NULL);
        }
        printf("SUM: %d", SUM);
        return 0;
}
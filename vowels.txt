#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
int vowels=0;
int constant=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;

void *function(void *n){
        pthread_mutex_lock(&m);
        char *string=(char*)n;
        for(int i=0;i<strlen(string);++i){
                if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u'){              
                        vowels++;
                }else{
                        constant++;
                }
        }
        pthread_mutex_unlock(&m);
        return NULL;
}


int main(int argc,char**argv){
        pthread_mutex_init(&m,NULL);
        int n;
        printf("number of words:");
        scanf("%d",&n);
        pthread_t t[n];
        for(int i=0;i<n;++i){
                char a[100];
                scanf("%s",a);
                int ok=pthread_create(&t[i],NULL,function,(void*)a);
                if(ok!=0)
                        printf("error\n");
        }
        for(int i=0;i<n;++i)
                pthread_join(t[i],NULL);
        printf("the number of vowels:%d\n",vowels);
        printf("the number of constants:%d\n",constant);
        pthread_mutex_destroy(&m);
        return 0;
}
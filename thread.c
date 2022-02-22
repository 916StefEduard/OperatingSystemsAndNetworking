#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int v[100],position=0;

struct pair{
        int index;
        int first;
        int second;
};


void *function(void *param){
        struct pair p=*(struct pair*) param;
        free(param);
        printf("index:%d\n",p.index);
        printf("first:%d\n",p.first);
        printf("second:%d\n",p.second);
        printf("\n");
        if(p.first%2==0){
                v[position++]=p.first;
        }
        return NULL;
}


int main(int argc,char**argv){
        int n;
        printf("number of threads:");
        scanf("%d",&n);
        pthread_t t[n];
        for(int i=0;i<n;++i){
                struct pair *p=malloc(sizeof(struct pair));
                p->first=rand()%10;
                p->second=rand()%10;
                p->index=i;
                int ok=pthread_create(&t[i],NULL,function,p);
                if(ok!=0)
                        printf("error\n");
        }
        for(int i=0;i<n;++i)
                pthread_join(t[i],NULL);
        printf("content of the vector:");
        for(int i=0;i<position;++i){
                printf("%d ",v[i]);
        }
        printf("\n");
        return 0;
}
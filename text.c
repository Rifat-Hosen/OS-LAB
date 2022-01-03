#include <pthread.h>

#include<stdio.h>

pthread_mutex_t key;

int x = 100;

void sum(){

    pthread_mutex_lock(&key);
    printf("Before sum : %d\n",x);
    x = x + 1;
    printf("After sum : %d\n",x);
    pthread_mutex_unlock(&key);


}


void sub(){

    pthread_mutex_lock(&key);
    printf("Before sub          : %d\n",x);
    x = x - 1;
    printf("After sub           : %d\n",x);
    pthread_mutex_unlock(&key);
}

int main(){
    int i;
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,(void *) sum, NULL);

    pthread_create(&tid2,NULL,(void *) sub, NULL);
    pthread_join(&tid1,NULL);

    pthread_join(&tid2,NULL);

    for(i = 0;i <5;i++){
        printf("Main thread, x : %d\n",x);
    }



    return 0;
}



//bootex




//


/*
locking global variable





*/

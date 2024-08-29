#include <sys/mman.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int* create_buffer(){
    int* ptr = (int*)mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON, -1, 0);
    if(ptr == NULL){
        perror("null error");
        exit(1);
    }
    return ptr;
}
int* push_front(int* buffer, int* size, const int element){
    if(*size>(2*1024)){
        perror("overflow");
        exit(1);
    }
    if(*size == 1024){
        int* ptr2 = (int*)mmap(NULL, 2*4096, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON,-1,0);
        for(int i = 0; i < (*size); i++){
            ptr2[i] = buffer[i];
        }
        munmap(buffer,*size);
        buffer = ptr2;
    }
    for(int i = (*size); i > 0; i--){
        buffer[i] = buffer[i-1];
    }
    buffer[0] = element;
    (*size)++;
    return buffer;
}
int* push_back(int * buffer, int * size, const int element){

    if(*size>(2*1024)){
        perror("overflow");
        exit(1);
    }
    if(*size==1024){
        int* ptr3 = (int*)mmap(NULL,2*4096,PROT_WRITE | PROT_READ,MAP_SHARED | MAP_ANON,-1,0);
        for(int i = 0;i<(*size);i++){
            ptr3[i] = buffer[i];
        }
        munmap(buffer,*size);
        buffer = ptr3;
    }
    buffer[*size]=element;
    (*size)++;
    return buffer;
} 
int* remove_element(int* buffer, int* size, const int index){
    for(int i = index; i<(*size)-1;i++){
        buffer[i]=buffer[i+1];
    }
    if(*size>1024){
        munmap(buffer+4096,4096);
    }
    (*size)--;
    return buffer;   
}
void current_state(int* buffer, const int size){
    for(int i=0;i<size;i++){
        printf("%d ",buffer[i]);
    }
}
void destroy_buffer(int** buffer, int* size){
    munmap(*buffer,*size);
    *buffer=NULL;
    *size = 0;
}

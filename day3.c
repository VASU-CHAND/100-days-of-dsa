#include<stdio.h>
int main(){
    int arr[100]={1,2,3,4,5,};
   printf("enter the postion of element to delete\n");
   int n;
   scanf("%d",&n);
   for(int i=n-1;i<4;i++){
    if(i!=4){
        arr[i]=arr[i+1];
    }
 
}
   for(int i=0;i<4;i++){
    printf("%d ",arr[i]);
   }
   }
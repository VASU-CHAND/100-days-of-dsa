#include<stdio.h>
int main(){
int arr[100]={1,2,3,4,5,};
printf("enter target\n");
int n;
scanf("%d",&n);
for(int i=0;i<5;i){
for(int j=i+1;j<5;j++){
if(arr[i]+arr[j]==n){
    int a=arr[i];
    int b=arr[j];
    printf("%d %d",a,b);
    return 0;
}

}
}

}
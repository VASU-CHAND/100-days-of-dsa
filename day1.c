#include<stdio.h>
int main(){
int arr[100]={1,2,3,4,5,};
printf("enter the element to insert\n");
int n;
scanf("%d",&n); 
int pos;
printf("enter the position\n");
scanf("%d",&pos);
for(int i=4;i>=(pos-1);i--){
arr[i+1]=arr[i];
}
arr[pos-1]=n;
for(int i=0;i<6;i++){
printf("%d ",arr[i]);
}

}
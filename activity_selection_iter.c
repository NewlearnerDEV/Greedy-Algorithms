#include<stdio.h>
struct activity
{
    int start;
    int finish;
};
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(struct activity act[],int num)
{
    for(int i=0;i<num;i++){
   int min=i;
   int j;
   for(j=i+1;j<num;j++)  
   {
       if(act[j].finish<act[min].finish)
       {
        min=j;
       }
   }
   swap(&act[i].start,&act[min].start);
   swap(&act[i].finish,&act[min].finish);
}
}
int act_select_iter(struct activity arr[],int num)
{
    int cnt=1;// 1st activity will always be there ie 0 th index one
    int fin1=arr[0].finish;
    
    for(int i=1;i<num;i++)
    {
        if(fin1<arr[i].start)
        {
            cnt++;
            fin1=arr[i].finish;
        }
    }
    return cnt;
}




int main()
{
    struct activity act[20];int num;
    printf("Enter number of activities : \n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("Enter start and finish time for %d activity: \n",i+1);
        scanf("%d %d",&act[i].start,&act[i].finish);
    }
    sort(act,num);
    // iterative method
    int ans=act_select_iter(act,num);
    
    printf("Max activities are(iterative method) %d ",ans);
    
    return 0;

}
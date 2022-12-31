#include<stdio.h>
struct jobsequencing
{
    int profit;
    int deadline;
};
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct jobsequencing job[],int num)
{
    for(int i=0;i<num;i++){
   int min=i;
   int j;
   for(j=i+1;j<num;j++)  
   {
       if(job[j].profit<job[min].profit)
       {
        min=j;
       }
   }
   swap(&job[i].profit,&job[min].profit);
   swap(&job[i].deadline,&job[min].deadline);
}
}
int find_max_time(struct jobsequencing job[],int num)
{   
    int max=job[0].deadline;
    for(int i=1;i<num;i++)
    {
        if(job[i].deadline>max)
        {
            max=job[i].deadline;
        }
    }
    return max;
}
  
int jobseq(struct jobsequencing job[],int num)
{
   int netprofit=0;
   sort(job,num);
   int max_time=find_max_time(job,num);
   int arr[max_time+1];
   for(int i=1;i<=max_time;i++)
   {
    arr[i]=0;
   }
   for(int i=num-1;i>=0;i--)
   {
     for(int k=max_time;k>=1;k--)
     {
        if(arr[job[i].deadline]==0)
        {
            arr[job[i].deadline]=job[i].profit;
            break;
        }
        else if(arr[k]==0&&arr[job[i].deadline]!=0&&k<=job[i].deadline)
        {
            arr[k]=job[i].profit;
            break;
        }
     }
   }
      for(int i=1;i<=max_time;i++)
    {
        netprofit+=arr[i];
    }

    return netprofit;
}

int main()
{   
    int num,ans;
    printf("Enter number of jobs :\n");
    scanf("%d",&num);
    struct jobsequencing job[20];
    for(int i=0;i<num;i++)
    {
        printf("Enter job%d profit and deadline respectively: \n",i+1);
        scanf("%d %d",&(job[i].profit),&(job[i].deadline));
    }
    ans=jobseq(job,num);
    printf("Net profit for the jobs is %d ",ans);
    return 0;
}
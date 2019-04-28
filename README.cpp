# FirstComeFirstServeCPU_Scheduling
#Run in codeblocks


#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n,time_unit,arrival_time[100],burst_time[100],i,waiting_time[100],queue[100],q=0,j,idle=0;
    float total;
    cout<<"Enter the number processes"<<endl;
    cin>>n;
    cout<<"Enter the maximum number of time_unit both for arrival time as well as burst time="<<endl;
    cin>>time_unit;
    cout<<"Enter the arrival time of each process,max="<<time_unit<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Process"<<i<<"=";
        cin>>arrival_time[i];
        cout<<endl;
    }
    for(i=0;i<=time_unit;i++)
    {
    for(j=0;j<n;j++)
    {
        if(i==arrival_time[j])
        {
          queue[q]=j;
          q++;
        }
    }
    }
    cout<<"Enter the burst time of each process"<<endl;
    for(i=0;i<n;i++)
    {
       cout<<"Process"<<i<<"=";
        cin>>burst_time[i];
        cout<<endl;
    }
    for(q=0;q<n;q++)
    {
        if(q==0)
        {
            waiting_time[queue[0]]=
            0;
        }
        else
        {
            total=0;
          for(i=0;i<=q-1;i++)
          {
              total=total+burst_time[queue[i]];
          }
           if(total<=arrival_time[queue[q]])
          {
              idle=arrival_time[queue[q]]-total;
              waiting_time[queue[q]]=0;
          }
          else
          {

              waiting_time[queue[q]]=idle+total-arrival_time[queue[q]];
          }
        }
    }
    cout<<"Waiting time of processes-"<<endl;
    for(q=0;q<n;q++)
    {
        cout<<queue[q]<<"="<<waiting_time[queue[q]]<<endl;
    }
    total=0;
    for(q=0;q<n;q++)
    {
        total=total+waiting_time[queue[q]];
    }
    cout<<"Average waiting time="<<total/n<<endl;
    cout<<"Turnaround time of processes-"<<endl;
    total=0;
    for(q=0;q<n;q++)
    {
        total=total+waiting_time[queue[q]]+burst_time[queue[q]];
        cout<<"Process"<<queue[q]<<"="<<waiting_time[queue[q]]+burst_time[queue[q]]<<endl;
    }
    cout<<"Average waiting time="<<total/n;
    getch();
    return 0;
}


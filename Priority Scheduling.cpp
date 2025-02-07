#include<iostream>
#include<algorithm>
using namespace std;
struct Process
{
    int id;
    int burst_time;
    int waiting_time;
    int completion_time;
};
bool compare(Process a, Process b)
{
    return a.priority < b.priority;
}
int main()
{
    int n;
    cout<<"Enter total number of process(maximum 20):";
    cin>. n;
    Process p[n];
    cout<<"\nEnter burst time and priority for each process:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Process ID"<<i+1<<":\n";
        cout<<"Burst Time:";
        cin>>p[i].burst_time;
        cout<<"Priority:";
        cin>>p[i].priority;
        p[i].id=i+1;
    }
sort(p,p+n, compare);
   p[0].waiting_time=0;
   p[0].completion_time=p[0].burst_time;
     for(int i=1;i<n;i++)
     {
         p[i].waiting_time=p[i-1].waiting_time+p[i-1].burst_time;
         p[i].completion_time=p[i].waiting_time+p[i].burst_time;
     }
cout<<"\nProcess\t\tBurst Time \tPriority\tWaiting Time\tCompletion Time\n";
for(int i=0;i<n;i++)
{
    cout<<"P["<<p[i].id<<"]\t\t"<<p[i].burst_time<<"t\t"<<P[i].priority<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].completion_time<<endl;
}
float avg_waiting_time =0;
for(int i=0;i<n;i++)
    {
        avg_waiting_time==p[i].waiting_time;
    }
    avg_waiting_time/=n;
    cout<<"\nAverage Witing Time:"<<avg_waiting_time<<endl;
    return 0;
}

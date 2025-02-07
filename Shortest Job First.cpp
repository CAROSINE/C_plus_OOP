#include<iostream>
#include<algorithm>
using namespace std;
struct Process
{
    int id;
    int burst_time ;
    int waiting_time;
    int completion_time;
};
bool compare(Process a, Process b)
 {
     return a.burst_time <b.burst_time ;
 }
int main()
{
  int n;
  cout<<"Enter total number of processes(maximum 20):";
  cin>>n;
  Process p[n];
  cout<<"\n Enter burst time for each time for each process:\n";
  for(int i=0; i<n; i++)
  {
      cout<<"P["<<i+1<<"]:";
      cin>>p[i].burst_time;
      p[i].id=i+1;
  }
sort(p, p+n, compare);
p[0].waiting_time=0;
p[0].completion_time=p[0].burst_time;
for(int i=1; i<n; i++)
   {
     p[i].waiting_time=p[i-1].waiting_time+p[i-1].burst_time;
     p[i].completion_time=p[i].waiting_time+p[i].burst_time;
   }
   cout<<"\nProcess\t\tBurst Time\tWaiting Time\tCompletion Time\n";
   for(int i=0; i<n; i++)
   {
       cout<<"P["<<p[i].id<<"]\t\t"<<p[i].burst_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].completion_time<<endl;
   }
   float avg_waiting_time=0;
   for(int i=0;i<n; i++)
   {
       avg_waiting_time+=p[i].waiting_time;
   }
   avg_waiting_time/=n;
   cout<<"\nAvarage Waiting Time: "<<avg_waiting_time<<endl;
   return 0;
}

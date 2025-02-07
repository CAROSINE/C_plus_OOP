#include<iostream>
using namespace std;
int main()
{
    int wtime[10],btime[10],rtime[10],num, quantum, total= 0;
    cout<<"Enter number of processes (MAX 10):";
    cin>> num ;
    cout<< "Enter burst time for each process:\n";
    for (int i=0;i<num;i++)
    {
        cout<<"P ["<<i+1<<"]:";
        cin>> btime[i];
        rtime[i]=btime[i];
        wtime[i]=0;
        total += btime[i];
    }
    cout<<"\n Enter quantum:";
    cin>> quantum ;
    int rp= num;
    int i=0;
    int time= 0;
    while(rp!=0)
    {
    if(rtime[i]>quantum)

    {
        rtime[i] -= quantum;
        time += quantum;
    }

    else if(rtime[i]<= quantum && rtime[i]>0)
    {
     time+= rtime[i];
     rtime[i]=0;
     rp--;
     wtime[i]= time - btime[i];
    }
    i++;
    if(i==num)
        i=0;
}
cout<<"\nProcess\tWaiting Time\tCompletion Time\n";
for (int i=0; i<num; i++)
{
         cout<<"P["<< i+1<<"]\t\t"<<wtime[i]<<"\t\t"<<wtime[i]+btime[i]<<endl;
}
return 0;
}

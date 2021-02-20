void compalgo(int n,struct proc sev[],int quant)
{
int i,j,total=0,count=n,low=30000;
float avgtat=0,avgwait=0;
for(i=0;i<n;i++)
{
if(sev[i].arrivaltime<low)
low=sev[i].arrivaltime;
}
total=low;
while(count)
{
for (i=0;i<n;i++)
{
if(sev[i].arrivaltime<=total)
{
if (sev[i].rem!=0)
{
if (sev[i].rem-quant>0)
{
total=total+quant;
sev[i].rem=sev[i].rem-quant;
}
else
{
total=total+sev[i].rem;
sev[i].rem=0;
count--;
sev[i].turnaround=total-sev[i].arrivaltime;
sev[i].wait=total-sev[i].bt-sev[i].arrivaltime;
}
}
}
}
}
for(int i=0;i<n;i++)
{
avgtat=avgtat+sev[i].turnaround;
avgwait= avgwait +sev[i].wait;
}
avgtat=avgtat/(1.0*n);
avgwait=avgwait/(1.0*n);
printf("\nThe average Turn Around Time of Round robin is : %f",avgtat);
printf("\nThe average Waiting Time of the Round Robin is : %f",avgwait);
for (i=0;i<n;i++)
{
sev[i].rem=sev[i].bt;
}
avgtat=0.0;
avgwait=0.0;
total=0;
count=n;
quant=0;
int flag=1;
for(i=0;i<n;i++)
{
if(sev[i].arrivaltime<low)
low=sev[i].arrivaltime;
}
total=low;
while(count)
{
if (flag)
{
for (i=0;i<n;i++)
{
quant=quant+sev[i].rem;
}
quant=quant/count;
flag= 0;
}
for (i=0;i<n;i++)
{
if (sev[i].arrivaltime<=total)
{
if (sev[i].rem!=0)
{
if (sev[i].rem-quant>0)
{
total=total+quant;
sev[i].rem=sev[i].rem-quant;
}
else
{
total=total+sev[i].rem;
sev[i].rem=0;
count--;
sev[i].turnaround=total-sev[i].arrivaltime;
sev[i].wait=total-sev[i].bt-sev[i].arrivaltime;
flag=1;
}
}
}
}
}
for(int i=0;i<n;i++)
{
avgtat=avgtat+sev[i].turnaround;
avgwait= avgwait +sev[i].wait;
}
avgtat=avgtat/(1.0*n);
avgwait=avgwait/(1.0*n);
 printf("\nThe average Turn Around Time of Dynamic Round robin is : %f",avgtat);
printf("\nThe average Waiting Time of the Dynamic Round Robin is : %f",avgwait);
for (i=0;i<n;i++)
{
sev[i].rem=sev[i].bt;
}
}

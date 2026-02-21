#include<stdio.h>

void findwttime(int process[],int n,int wt[],int bt[]){
	int i;
	wt[0] = 0;
	for(i=1;i<n;i++){
		wt[i] = bt[i-1]+wt[i-1];
	}
}

void findtat(int process[],int n,int wt[],int bt[],int tat[]){
	int i;
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
}

void findavgtime(int process[],int n,int bt[]){
	int i,wt[n],tat[n],total_wt=0,total_tat=0;
	findwttime(process,n,wt,bt);
	findtat(process,n,wt,bt,tat);
	printf("Process    Burst Time   Waiting time    tat  \n");
	for(i=0;i<n;i++){
		total_wt = total_wt+wt[i];
		total_tat = total_tat+tat[i];
		printf("%d",(i+1));
		printf("    %d",bt[i]);
		printf("        %d",wt[i]);
		printf("            %d\n",tat[i]);
	}
	float swt = (float)total_wt/(float)n;
	float atat = (float)total_tat/(float)n;
	printf("avg wt time: %f\n",swt);
	printf("avg tat time: %f",atat);
}

int main(){
	int process[]={1,2,3};
	int n = 3;
	int bt[]={5,3,8};
	findavgtime(process,n,bt);

	return 0;
}

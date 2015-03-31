#include<stdio.h>
#include<stdlib.h>

int * calculate_waiting_time(int *burst,int n){
	int i;
	int *wait = malloc(sizeof(int)*(n+1));
	wait[0]=0;
	for(i=1;i<n+1;i++){
		wait[i]=burst[i-1]+wait[i-1];
	}
	return wait;
}

int main(){

	int n,i;
	float avgWait, avgTurn;
	
	int *wait=NULL;
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	int burst[n];
	
	for(i=0; i<n; i++){
		printf("\nEnter the burst time of %d process: ", i+1);		
		scanf("%d",&burst[i]);
	}

	wait = calculate_waiting_time(burst,n);
	avgWait = 0;
	avgTurn = 0;
	
	printf("\n*****************************");
	printf("\n*Wait Time * Turnaround Time*");
	printf("\n*****************************");
	for(i=0;i<n;i++){
		printf("\n*    %d     *       %d        *",wait[i],burst[i]);
		avgWait += wait[i];
		avgTurn += wait[i+1]; 
	}
	
	printf("\n*****************************");
	printf("\n*Avg. wait time: %0.2f       *", avgWait/n);
	printf("\n*****************************");
	printf("\n*Avg. turnaround time: %0.2f *", avgTurn/n);
	printf("\n*****************************\n");
}

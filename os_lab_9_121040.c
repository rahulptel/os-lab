#include<stdio.h>
#include<stdlib.h>

//This function calculates the waiting time of each process. Here arrival time is assumed to be zero.
int * calculate_waiting_time(int *burst,int n){
	int i;
	int *wait = malloc(sizeof(int)*(n));
	wait[0]=0;
	for(i=1;i<n;i++){
		wait[i]=burst[i-1]+wait[i-1];
	}
	return wait;
}

int main(){

	int n,i;
	float avgWait, avgTurn;
	
	int *wait=NULL;
	//Input number of process
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	int burst[n];

	printf("\nThis code is working under the assumption that the arrival time of all processes is same.");
	printf("\nExpected outputs are waiting time and turnaround time for each process.");
	//Input burst time of each process
	for(i=0; i<n; i++){
		printf("\nEnter the burst time of %d process: ", i+1);		
		scanf("%d",&burst[i]);
	}

	wait = calculate_waiting_time(burst,n);
	avgWait = 0;
	avgTurn = 0;
	
	//Print the calculated results
	printf("\n*****************************");
	printf("\n*Wait Time * Turnaround Time*");
	printf("\n*****************************");
	//loop to calculate the average waiting and turnaround time.
	for(i=0;i<n;i++){
		//The value of turnaround time can be calculated from waiting time plus the burst time.
		//Turn around time = Wait time + Exec Time
		printf("\n*    %2d    *       %2d       *",wait[i],wait[i]+burst[i]);
		avgWait += wait[i];
		avgTurn += (wait[i]+burst[i]); 
	}
	
	printf("\n************************************");
	printf("\n*Avg. wait time: %2.2f              *", avgWait/n);
	printf("\n************************************");
	printf("\n*Avg. turnaround time: %2.2f       *", avgTurn/n);
	printf("\n************************************\n");
}

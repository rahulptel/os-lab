//This code calculates the waiting time and turnaround time of each process, using 
//SJF -Shortest Job First algorithm

#include<stdio.h>

int main(){
	int N,burst,i,j,temp;
	float totalTurn,totalWait;
	totalTurn = 0;
	totalWait = 0;
	//Input number of processes
	printf("\nEnter the number of process: ");
	scanf("%d",&N);
	
	int process[N][2];
	int wait[N];
	int turn[N];

	//Input burst time of each process
	for(i=0;i<N;i++){
		process[i][0]=i+1;
		printf("Enter the burst time of %d process: ",i+1);
		scanf("%d",&process[i][1]);
	}

	//Sort the array according to the shortest finish time
	for(i=0;i<N-1;i++){
		for(j=1;j<N;j++){
			if(process[i][1]>process[j][1]){
				temp = process[i][1];
				process[i][1] = process[j][1];
				process[j][1] = temp;
				process[i][0] = j;
				process[j][0] = i;
			}
		}
	}

	//calculate the waiting time of each process
	wait[0]=0;
	turn[0]=process[0][1];
	for(i=1;i<N;i++){
		wait[i] = wait[i-1] + process[i-1][1];
		turn[i] = wait[i] + process[i][1];
		totalWait = totalWait + wait[i]; 
		totalTurn =	totalTurn + turn[i];
	}
	totalTurn = totalTurn + turn[0];
	printf("\n\n\n\n");
	//Print the calculated results
	printf("\n*******************************************");
	printf("\n** Process * Wait Time * Turnaround Time **");
	printf("\n*******************************************");
	//loop to calculate the average waiting and turnaround time.
	for(i=0;i<N;i++){
		//The value of turnaround time can be calculated from waiting time plus the burst time.
		//Turnaround time = Wait time + Exec Time
		printf("\n**   %2d    *    %2d     *       %2d        **",process[i][0]+1,wait[i],turn[i]);
	}	
	printf("\n*******************************************");
	printf("\n** Avg. wait time: %2.2f                  **", totalWait/N);
	printf("\n*******************************************");
	printf("\n** Avg. turnaround time: %2.2f            **", totalTurn/N);
	printf("\n*******************************************");
	printf("\n\n\n\n");
}


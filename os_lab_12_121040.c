//This C Programs to implement least slack time (LST) scheduling algorithm of Real time
//operating system.
//Assumption that the jobs are arranged in the ascending form of arrival time in the input
#include<stdio.h>
int main(){
	int N,burst,i,j,time,exec,LST,total,flag;

	//Input number of processes
	printf("\nEnter the number of process: ");
	scanf("%d",&N);
	
	//process(arrival time, deadline, burst time)
	int process[N][3];
						
	//Input start time, deadline and burst time of each process
	total = 0;
	for(i=0;i<N;i++){		
		printf("Enter the Release time, Deadline, Execution time of each process for %d process: ",i+1);
		scanf("%d %d %d",&process[i][0],&process[i][1],&process[i][2]);		
		total+=process[i][2];
	}

	//Init Gannt Chart
	int executed[N][total];
	for(i=0;i<N;i++){
		for(j=0;j<total;j++){
			executed[i][j]=0;
		}
	}

	//Iterate over each instance of time
	for(time=0;time<total;time++){		
		flag = 0;
		//For a give time iterate over each process to check if it's executable or not
		for(i=0;i<N;i++){
			//Check if the process has finished execution or not.
			if(process[i][2]>0){		
				//Check if the arrival time of the process is less than the current time.
				//If we receive a process whose arrival time is greater than the current time 
				//we break the loop.
				if(process[i][0]<=time){
					if(flag==0){	
						LST = process[i][1]-time-process[i][2];
						exec = i;
						flag = 1;
					}
					//If the process has still execution time left, than we check whose deadline is
					//more close from the current time 
					if(process[i][1]-time-process[i][2] < LST){
						exec = i;
					}
				}
				else{
					break;					
				}
			}
		}

		//At the end we will have the index of the process which is to be executed. Hence we will decrement the 
		//Burst time of that process by one
		process[exec][2] -= 1;			
		executed[exec][time] = 1;
	}

	printf("\nRows: 1 to %d process",N);
	printf("\nColumns: 1 to %d unit of time", total);
	printf("\nFirst row and column corresponds to the first process and first unit of time respectively");

	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<total;j++){
			printf("%2d ",executed[i][j]);
		}
	}
	printf("\n");
	return 0;
}


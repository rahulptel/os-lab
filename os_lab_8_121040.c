#include<stdio.h>

int indexFree[4][2] = {{0,1},{1,1},{3,1},{6,1}};
int last;
int bestFit(int bsize){
	int j;
	int flag=0;
	if(bsize>0 && bsize<=100){
		j=0;
	}
	else if(bsize>100 && bsize<=200){
		j=1;
	}
	else if(bsize>200 && bsize<=300){
		j=2;
	}
	else if(bsize>300 && bsize<=400){
		j=3;
	}
	else{
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(j!=4){
		if(indexFree[j][1]==1 && ((j+1)*100>=bsize)){
			indexFree[j][1]=0;
			flag=1;			
			//index for next fit
			last=j;
			break;
		}
		j++;
	}
	if(flag==1)
		return 1;
	else 
		return 0;
}

int worstFit(int bsize){
	int j=3,flag=0;
	if(bsize<0 || bsize>400){
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(j>=0){
		printf("%d",indexFree[j][1]);
		if(indexFree[j][1]==1 && ((j+1)*100>=bsize)){
			indexFree[j][1]=0;
			flag=1;			
			//index for next fit
			last=j;
			break;
		}
		j--;
	}
	if(flag==1)
		return 1;
	else 
		return 0;
}

int firstFit(int bsize){
	int j=0,flag=0;
	if(bsize<0 || bsize>400){
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(j!=4){
		if(indexFree[j][1]==1 && ((j+1)*100>=bsize)){
			indexFree[j][1]=0;
			flag=1;			
			//index for next fit			
			last=j;
			break;
		}
		j++;
	}	
	if(flag==1)
		return 1;	
	else 
		return 0;
}

int nextFit(int bsize){
	int j=last+1, i=4, flag=0;
	if(bsize<0 || bsize>400){
		printf("\nEnter a valid size of memory block(100, 200, 300, 400): ");
		return 0;
	}
	while(i){
		if((indexFree[j%4][1]==1) && (((j%4)+1)*100>=bsize)){
			indexFree[j%4][1]=0;
			flag=1;			
			//index for next fit
			last=j;
			break;
		}
		j++;
		i--;
	}
	if(flag==1)
		return 1;
	else 
		return 0;	
}

void current(){
	int i;
	//Display the current scenario
	for(i=0;i<4;i++){		
		
		if(indexFree[i][1]==1)
			printf("\nThe %dKB block is available",(i+1)*100);
		else
			printf("\nThe %dKB block is unavailable",(i+1)*100);
	}
}

void release(){
	int rel, memSize;
	do{
		current();
		printf("\nDo you want to release some memory?(1/0)");
		scanf("%d",&rel);
		if(rel){
			printf("\nEnter the block size(KBs) which you want to release(100, 200, 300, 400): ");
			scanf("%d",&memSize);
			switch(memSize){
				case 100:
					indexFree[0][1]=1;
					break;
				case 200:
					indexFree[1][1]=1;
					break;
				case 300:
					indexFree[2][1]=1;
					break;
				case 400:
					indexFree[3][1]=1;
					break;
				default:
					printf("\nEnter valid block size (100, 200, 300, 400): ");
			}
		}
	}while(rel);
	return;
}

int main(){
	int memSize;
	//Shows the initial condition of the memory blocks
	//display();
	//Now suppose certain blocks gets occupied.
	indexFree[0][1] = 0;
	indexFree[1][1] = 0;
	//display();
	current();	
	//Checking the first fit algorithm
	printf("\n******** First Fit ********\n");	
	//Enter the request
	do{		
		printf("\nEnter the memory required: ");
		scanf("%d",&memSize);
		if(firstFit(memSize))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&memSize);
		if(!memSize)
			break;
	}while(1);
	release();

	//Checking the best fit algorithm
	printf("\n******** Best Fit ********\n");
	//Enter the request
	do{
		printf("\nEnter the memory required: ");
		scanf("%d",&memSize);
		if(bestFit(memSize))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&memSize);
		if(!memSize)
			break;
	}while(1);
	release();

	//Checking the Next fit algorithm
	printf("\n******** Next Fit ********\n");
	//Enter the request
	do{
		printf("\nEnter the memory required: ");
		scanf("%d",&memSize);
		if(nextFit(memSize))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&memSize);
		if(!memSize)
			break;
	}while(1);
	release();

	//Checking the worst fit algorithm
	printf("\n******** Worst Fit ********\n");
	//Enter the request
	do{
		printf("\nEnter the memory required: ");
		scanf("%d",&memSize);
		if(worstFit(memSize))
			printf("\nMemory allocated successfully!");
		else
			printf("\nMemory cannot be allocated successfully!");
		current();
		printf("\nDo you want to allocate more memory?(1/0): ");
		scanf("%d",&memSize);
		if(!memSize)
			break;
	}while(1);
	release();

	return 0;
}

#include<stdio.h>

int main(){
	int row,column,i,m,j,temp,count,k=-2,array[100],Matrix[100][100],decompressMatrix[100][100]; 
	float compressratio;                                                                          
	printf("Enter the number of rows : ");                
	scanf("%d",&row);
	printf("Enter the number of column : ");
	scanf("%d",&column);

	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%dth row and %dth column index of your matrix : ",i+1,j+1);
			scanf("%d",&Matrix[i][j]);
		}
	}
	printf("\n---Matrix---\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%d  ",Matrix[i][j]);
		}
		printf("\n");
	}
	// --- COMPRESS ---
		
	i=0;j=0; // Starting from the beginning.
	while(i!=row){   // If matrix is not completed, indexes being checked by all the columns and then rows..
		count=0;
		temp=Matrix[i][j];
		while(temp==Matrix[i][j]){
			count++;
			if(j!=column-1){  // Checking if the cursor is at the last column or if it's not.
				j++;
			}
			else{
				i++;
				j=0;
			}		
		}
		k+=2;
		array[k]=count;
		array[k+1]=temp;
	}
	printf("\n---Compress Array---\n");
	for(i=0;i<k+2;i++){
		printf("%d ",array[i]);	
	}
	compressratio=1.0-((k+2.0)/(row*column));
	printf("Compress ratio : %f\n",compressratio);

	 // --- COMPRESS HAS DONE. --- 


	// --- DECOMPRESS --- 


	m=0; j=0;count=0;
	for(i=0;i<k+1;i+=2){
		while(count!=array[i]){
			decompressMatrix[m][j]=array[i+1];
			j++;
			count++;
			if(j==column){
				j=0;
				m++;
			}
		}
		count=0;	
	}	
	
	// --- DECOMPRESS HAS DONE. ---

	printf("\n---Decompress Matrix---\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%d  ",decompressMatrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}	
	


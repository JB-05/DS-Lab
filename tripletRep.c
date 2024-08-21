#include <stdio.h>
#include <stdlib.h>
struct matrix{
	int row;
	int col;
	int mem;
};
/*Implementation of sparse matrix*/

void main(){
	
	int row,col,count=0,cou=0;
	
	//ask for the no of rows and columns from the user and declare the matrix
	printf("\nEnter the no of rows : \n");
	scanf("%d",&row);
	printf("\nEnter the no of columns : \n");
	scanf("%d",&col);
	int array[row][col];
	struct matrix res[10];
	
	//input the array elemenst
	printf("Enter the array elements : \n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("Enter the array element %d %d : ",i,j);
			scanf("%d",&array[i][j]);
		}
	}
	
	//display the array elements
	printf("\nThe array elements are : \n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	/*check for sparse of a matrix*/
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(array[i][j]==0){
				count++;
			}
		}
	}
	
	//Adding matrix in a tuple format structure
	
	if(count>((row*col)/2)){
		printf("The matrix is sparse matrix \n");
		for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(array[i][j]!=0){
			//for(int k=j;k<col+1;k++){
				res[i].row=i;
				res[i].col=j;
				res[i].mem=array[i][j];
				
				//}
				cou++;
			}
		}
	}
	printf("Tuple representation : \n");
	printf("Row :      ");
	for(int i=0;i<cou;i++){
		printf("%d\t",res[i].row);
	}
	printf("\n");
	printf("Column :   ");
	for(int i=cou-1;i>=0;i--){
		printf("%d\t",res[i].col);
	}printf("\n");
	printf("Element :  ");
	for(int i=0;i<cou;i++){
		printf("%d\t",res[i].mem);
	}
	printf("\n");
	}
	else{
		printf("The matrix is not a sparse matrix....");
	}
	
}










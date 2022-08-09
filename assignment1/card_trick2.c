/*

Some tips:
1. Preferably write the code in your local environment. It will help you debug the code faster.
2. Always practice writing clean code.

Note:
Use of C++ STL or any external library is strictly prohibited.
*/

#include<stdio.h>

int* find_base3(int  n){
	
	
	static int base3[3];
	for(int i =0;i<3;i++){
		base3[i] = n%3;
		n/=3;
	}
	

	return base3;
}
void print(int arr[27]){
	for(int i =0;i<27;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int find_index(int arr[27],int element){
	int j;
	for(int i=0;i<27;i++){
		if (arr[i] == element){
			j =  i;
		}
	}
	return j;
}
	




int main(void){
	int pile_array[27];
	for(int i=0;i<27;i++){
		scanf("%d",pile_array+i);
	}
	int chosen ,chosen_num;
	scanf("%d %d",&chosen,&chosen_num); 
	
	
	int * base3 = find_base3(chosen_num-1);

	int array_with_columns[27];//0 to 8 first column, 9 to 17 second and so on
	int column1_index = 0;int column2_index = 9; int column3_index = 18;
	for(int i=0;i<27;i++){
		if(i%3 ==0){
			array_with_columns[column1_index] = pile_array[i];
			column1_index++;
		}
		else if(i%3 ==1){
			array_with_columns[column2_index] = pile_array[i];
			column2_index++;

		}
		else{
			array_with_columns[column3_index] = pile_array[i];
			column3_index++;

		}
	}
	
	//step 2 first time
	int index = find_index(array_with_columns,chosen);
	int first_row_from,second_row_from;
	int third_row_from ;
	if (index >= 0 && index <= 8){
		
		
		switch(base3[0]){
			case 0:{
				
				first_row_from = 0;
				second_row_from = 9;
				third_row_from  = 18;
				}
				break;
			case 1:{
				first_row_from = 9;
				second_row_from = 0;
				third_row_from = 18;

			       }
				break;
			case 2:{
				first_row_from = 9;
				second_row_from = 18;
				third_row_from = 0;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 9 && index <= 17){
		
		switch(base3[0]){
			case 0:{
				
				first_row_from = 9;
				second_row_from = 0;
				third_row_from  = 18;
				}
				break;
			case 1:{
				first_row_from = 0;
				second_row_from = 9;
				third_row_from = 18;

			       }
				break;
			case 2:{
				first_row_from = 0;
				second_row_from = 18;
				third_row_from = 9;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	
	
	if (index >= 18 && index <= 26){
		switch(base3[0]){
			case 0:{
				
				first_row_from = 18;
				second_row_from = 0;
				third_row_from  = 9;
				}
				break;
			case 1:{
				first_row_from = 0;
				second_row_from = 18;
				third_row_from = 9;

			       }
				break;
			case 2:{
				first_row_from = 0;
				second_row_from = 9;
				third_row_from = 18;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	
			
	print(pile_array);
	//step3
	column1_index = 0;column2_index = 9;column3_index = 18;
	for(int i=0;i<27;i++){
		if(i%3 ==0){
			array_with_columns[column1_index] = pile_array[ i ];
			column1_index++;
		}
		else if(i%3 ==1){
			array_with_columns[column2_index] = pile_array[ i ];
			column2_index++;

		}
		else{
			array_with_columns[column3_index] = pile_array[i];
			column3_index++;

		}
	}
	
	//step2 second
	index = find_index(array_with_columns,chosen);
	if (index >= 0 && index <= 8){
		
		
		switch(base3[1]){
			case 0:{
				
				first_row_from = 0;
				second_row_from = 9;
				third_row_from  = 18;
				}
				break;
			case 1:{
				first_row_from = 9;
				second_row_from = 0;
				third_row_from = 18;

			       }
				break;
			case 2:{
				first_row_from = 9;
				second_row_from = 18;
				third_row_from = 0;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 9 && index <= 17){
		
		switch(base3[1]){
			case 0:{
				
				first_row_from = 9;
				second_row_from = 0;
				third_row_from  = 18;
				}
				break;
			case 1:{
				first_row_from = 0;
				second_row_from = 9;
				third_row_from = 18;

			       }
				break;
			case 2:{
				first_row_from = 0;
				second_row_from = 18;
				third_row_from = 9;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	
	
	if (index >= 18 && index <= 26){
		switch(base3[1]){
			case 0:{
				
				first_row_from = 18;
				second_row_from = 0;
				third_row_from  = 9;
				}
				break;
			case 1:{
				first_row_from = 0;
				second_row_from = 18;
				third_row_from = 9;

			       }
				break;
			case 2:{
				first_row_from = 0;
				second_row_from = 9;
				third_row_from = 18;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}

	print(pile_array);
	//step 3 second
	column1_index = 0;column2_index = 9;column3_index = 18;
	for(int i=0;i<27;i++){
		if(i%3 ==0){
			array_with_columns[column1_index] = pile_array[ i];
			column1_index++;
		}
		else if(i%3 ==1){
			array_with_columns[column2_index] = pile_array[ i ];
			column2_index++;

		}
		else{
			array_with_columns[column3_index] = pile_array[ i ];
			column3_index++;

		}
	}
	
	//step2 last
	index = find_index(array_with_columns,chosen);
	if (index >= 0 && index <= 8){
		
		
		switch(base3[2]){
			case 0:{
				
				first_row_from = 0;
				second_row_from = 9;
				third_row_from  = 18;
				}
				break;
			case 1:{
				first_row_from = 9;
				second_row_from = 0;
				third_row_from = 18;

			       }
				break;
			case 2:{
				first_row_from = 9;
				second_row_from = 18;
				third_row_from = 0;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 9 && index <= 17){
		
		switch(base3[2]){
			case 0:{
				
				first_row_from = 9;
				second_row_from = 0;
				third_row_from  = 18;
				}
				break;
			case 1:{
				first_row_from = 0;
				second_row_from = 9;
				third_row_from = 18;

			       }
				break;
			case 2:{
				first_row_from = 0;
				second_row_from = 18;
				third_row_from = 9;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}
	
	
	if (index >= 18 && index <= 26){
		switch(base3[2]){
			case 0:{
				
				first_row_from = 18;
				second_row_from = 0;
				third_row_from  = 9;
				}
				break;
			case 1:{
				first_row_from = 0;
				second_row_from = 18;
				third_row_from = 9;

			       }
				break;
			case 2:{
				first_row_from = 0;
				second_row_from = 9;
				third_row_from = 18;

			       }
				break;
		}
		for(int i =0;i<9;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<9;i++){
			pile_array[i+9] = array_with_columns[second_row_from + i];
		}
		for (int i = 0;i<9;i++){
			pile_array[i+18] = array_with_columns[third_row_from+i];	
		}
	}

	
	print(pile_array);
	
	
	
	
	return 0;
}

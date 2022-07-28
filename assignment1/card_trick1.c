#define len 21
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print(int arr[21]){
	for(int i =0;i<21;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int find_index(int arr[21],int element){
	int j;
	for(int i=0;i<21;i++){
		if (arr[i] == element){
			j =  i;
		}
	}
	return j;
}
void copy(int array_with_contents[21],int array_to_receive[21]){
	for(int i=0;i<21;i++){
	array_to_receive[i] = array_with_contents[i];

	}	
}
int random_from_range(int lower, int upper){
	srand(time(0));
	int num = (rand()%(upper - lower + 1)) +lower;
	return num;
}
int main(void){
	int pile_array[21];
	for(int i=0;i<21;i++){
		pile_array[i] = i+1;//let the cards be numbered from 1 to 21
	}
	int chosen =random_from_range(1,21); 
	int array_with_columns[21];//0 to 6 first column, 7 to 13 second and so on
	int column1_index = 0,column2_index = 7,column3_index = 14;
	for(int i=0;i<21;i++){
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
	print(array_with_columns);
	//step 2 first time
	int index = find_index(array_with_columns,chosen);
	if (index >= 0 && index <= 6){
		int first_row_from = (random_from_range(1,2) == 1)?(7):(14);
		int third_row_from  = (first_row_from == 7)?(14):(7);
		
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 7 && index <= 13){
		int first_row_from = (random_from_range(1,2) == 1)?(0):(14);
		int third_row_from  = (first_row_from == 0)?(14):(0);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[7+i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 14 && index <= 20){
		int first_row_from = (random_from_range(1,2) == 1)?(0):(7);
		int third_row_from  = (first_row_from == 0)?(7):(0);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[14+i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	print(pile_array);
	//step3
	column1_index = 0,column2_index = 7,column3_index = 14;
	for(int i=0;i<21;i++){
		if(i%3 ==0){
			array_with_columns[column1_index] = pile_array[len - i -1];
			column1_index++;
		}
		else if(i%3 ==1){
			array_with_columns[column2_index] = pile_array[len - i -1];
			column2_index++;

		}
		else{
			array_with_columns[column3_index] = pile_array[len - i - 1];
			column3_index++;

		}
	}
	print(array_with_columns);
	//step2 second
	index = find_index(array_with_columns,chosen);
	if (index >= 0 && index <= 6){
		int first_row_from = (random_from_range(1,2) == 1)?(7):(14);
		int third_row_from  = (first_row_from == 7)?(14):(7);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 7 && index <= 13){
		int first_row_from = (random_from_range(1,2) == 1)?(0):(14);
		int third_row_from  = (first_row_from == 0)?(14):(0);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[7+i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 14 && index <= 20){
		int first_row_from = (random_from_range(1,2) == 1)?(0):(7);
		int third_row_from  = (first_row_from == 0)?(7):(0);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[14+i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	print(pile_array);
	//step 3 second
	column1_index = 0;column2_index = 7;column3_index = 14;
	for(int i=0;i<21;i++){
		if(i%3 ==0){
			array_with_columns[column1_index] = pile_array[len - i -1];
			column1_index++;
		}
		else if(i%3 ==1){
			array_with_columns[column2_index] = pile_array[len - i -1];
			column2_index++;

		}
		else{
			array_with_columns[column3_index] = pile_array[len - i - 1];
			column3_index++;

		}
	}
	print(array_with_columns);
	//step2 last
	index = find_index(array_with_columns,chosen);
	if (index >= 0 && index <= 6){
		int first_row_from = (random_from_range(1,2) == 1)?(7):(14);
		int third_row_from  = (first_row_from == 7)?(14):(7);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 7 && index <= 13){
		int first_row_from = (random_from_range(1,2) == 1)?(0):(14);
		int third_row_from  = (first_row_from == 0)?(14):(0);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[7+i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	if (index >= 14 && index <= 20){
		int first_row_from = (random_from_range(1,2) == 1)?(0):(7);
		int third_row_from  = (first_row_from == 0)?(7):(0);
		for(int i =0;i<7;i++){
			pile_array[i] = array_with_columns[first_row_from+i];
		}	
		for(int i =0;i<7;i++){
			pile_array[i+7] = array_with_columns[14+i];
		}
		for (int i = 0;i<7;i++){
			pile_array[i+14] = array_with_columns[third_row_from+i];	
		}
	}
	print(pile_array);
	printf("%d\n",chosen);
	
	
	return 0;
}

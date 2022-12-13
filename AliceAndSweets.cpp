#include <iostream>
#define INITIALIZE_MAX -1;
int main(){
    int numOfSweets,allwedNo,numOfSweetsEatenFromFront,numOfSweetsEatenFromBack;
    int max_sweetness = INITIALIZE_MAX;
    int sumFromFront = 0;
    int sumFromBack = 0;
    std::cin>>numOfSweets>>allwedNo;
    int * sweetList = new int[numOfSweets];
    int *FrontCumulativeSum = new int[numOfSweets];
    int *BackCumulativeSum = new int[numOfSweets]; 
    for(int i =0;i<numOfSweets;i++){
        std::cin>>sweetList[i];
    }
    for(int i =0;i<numOfSweets;i++){
        sumFromFront+=sweetList[i];
        FrontCumulativeSum[i] = sumFromFront;
    }
    for(int i =0;i<numOfSweets;i++){
        sumFromBack+=sweetList[numOfSweets-1-i];
        BackCumulativeSum[i] = sumFromBack;
    }

    for(numOfSweetsEatenFromFront=0;numOfSweetsEatenFromFront<=allwedNo;numOfSweetsEatenFromFront++){
        if (numOfSweetsEatenFromFront==0 ){
            if (max_sweetness<BackCumulativeSum[allwedNo-1]){//1 sweet means position at 0th index
                max_sweetness = BackCumulativeSum[allwedNo-1];
            }
        }
        else if (numOfSweetsEatenFromFront==allwedNo ){
            if (max_sweetness<FrontCumulativeSum[allwedNo-1]){
                max_sweetness = FrontCumulativeSum[allwedNo-1];
            }
        }
        else{
            numOfSweetsEatenFromBack = allwedNo-numOfSweetsEatenFromFront;
            if((FrontCumulativeSum[numOfSweetsEatenFromFront-1]+BackCumulativeSum[numOfSweetsEatenFromBack-1])>max_sweetness){
                max_sweetness = FrontCumulativeSum[numOfSweetsEatenFromFront-1]+BackCumulativeSum[numOfSweetsEatenFromBack-1];
            }
        }
        
        
    }

    std::cout<<max_sweetness<<std::endl;





    return 0;
}
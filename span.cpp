#include<iostream>
/*
input 

*/
using namespace std;
class Stack{
	private:
		long long int array[200];//Random large number, INT_MAX giving segfault
		int head = -1;
		
	public:
		bool empty(){
			if (head ==-1){
				return true;
			}
			else{
				return false;
			}
		}
   		void push(int elem){
			head++;
			array[head] = elem;
		}
		
		void pop(){
			if (this -> empty()){
				cout<<"stack is empty"<<endl;
			}
			else{
				head --;
			}
		}
		int top(){
			if (this ->empty()){
				return -1;
			}
			else{
				return array[head];
			}
		}
		void size(){
			cout<<head+1<<endl;
		}
		void isempty(){
			if (this -> empty()){
				cout << 1<<endl;
			}
			else{
				cout <<0<<endl;
			}
		}
};

int main(){
    
  //code goes here
  long long int n;
  cin>>n;
  int * prices = new int[n];
  for(long long int i=0;i<n;i++){
    cin>>prices[i];

  }
  Stack stack;
  int* span = new int[n];
  for(long long int i=0;i<n;i++){
    while(!stack.empty() ){
	   
      if(prices[stack.top()]<=prices[i]){
        stack.pop();
      }
      else{
        break;
      }
    }
    if (stack.empty()){
      span[i] = i+1;
    }
    else{
      span[i]  = i - (stack.top());
    }
    stack.push(i);
  
  }
  for(long long int i =0;i<n;i++){
    cout<<span[i]<<" ";
    }

  cout<<endl;
  delete prices;
  delete span;
  
  return 0;
}

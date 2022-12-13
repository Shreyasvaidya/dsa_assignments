#include<iostream>
using namespace std;
class Stack{
	private:
		int array[40];//Random large number, INT_MAX giving segfault
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
  int n;
  cin>>n;
  int *powers =new int[n];
  for(int i=0;i<n;i++){
    cin>>powers[i]; 
  }
  int *ans = new int[n];
  for(int i=0;i<n;i++){
    ans[i] = 0; 
  }
  Stack stack;
  

  for(int i=0;i<n;i++){//algorithm similar to stock span, just that will be used for both right and left 
    while(!stack.empty()){
      if(powers[stack.top()]<powers[i]){
        stack.pop();
      }
      else{
        break;
      }
    }
    if (stack.empty()){
      ans[i] +=i;
    }
    else{
      ans[i]  +=i - (stack.top()) - 1;
    }
    stack.push(i);
  
  }
  
  Stack stackr ;//for right side
  for(int i=n-1;i>-1;i--){//algorithm similar to stock span, just that will be used for both right and left 
    while(!stackr.empty()){
      if(powers[stackr.top()]<powers[i]){
        stackr.pop();
      }
      else{
        break;
      }
    }
    if (stackr.empty()){
      ans[i] += n - i -1;
    }
    else{
      ans[i]  +=stackr.top()-i-1;
    }
    stackr.push(i);
  
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" "; 
  }
  delete powers;
  delete ans;
  cout<<endl;
  return 0;
}
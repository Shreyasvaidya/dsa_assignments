#include<iostream>
using namespace std;
class Stack{
	private:
		int array[200000];//Random large number, INT_MAX giving segfault
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
		int size(){
			return head+1;
		}
		
};


int max(int len,int *array){
    int max=-1;
    for(int i=0;i<len;i++){
        if (array[i]>max){;
        max = array[i];
        }

    }
    return max;
}
int main(){
    int rightsp,leftsp;
    int len;
    cin>>len;
    Stack srsp;
    Stack slsp;
    int * arr = new int[len];
    int *rsp = new int[len];
    int *lsp = new int[len];
    for (int i=0;i<len;i++){
        cin>>arr[i];
    
    }
    for(int i=0;i<len;i++){
        while(arr[srsp.top()]<arr[i] && !(srsp.empty())){
            rsp[srsp.top()] = i;
            srsp.pop();
        }
        srsp.push(i);
    }
    for(int i=len-1;i>-1;i--){
        while(arr[slsp.top()]<arr[i] && !(slsp.empty())){
            lsp[slsp.top()] = i;
            slsp.pop();
        }
        slsp.push(i);
    }
    int * ans = new int[len];
    for(int i=0;i<len;i++){
        ans[i] = lsp[i]*rsp[i];
    }
    int msp = max(len,ans);
    cout<<msp<<endl;
    return 0;
}
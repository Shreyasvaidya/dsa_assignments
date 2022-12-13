#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
template<class T>
class Stack{
	private:
		T array[200000];//Random large number, INT_MAX giving segfault
		int head = -1;
		bool empty(){
			if (head ==-1){
				return true;
			}
			else{
				return false;
			}
		}
	public:
		void Push(T elem){
			head++;
			array[head] = elem;
		}
		
		void Pop(){
			if ( empty()){
				cout<<"stack is empty"<<endl;
			}
			else{
				head --;
			}
		}
		T peek(){
			return array[head];
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
    string given;
    cin>>given;
    Stack<char>stack;
    int len = given.length();
    for(int i =0;i<len;i++){
        stack.Push(given[i]);
    }
    string reversed;
    for(int i =0;i<len;i++){
        reversed+=stack.peek();
        stack.Pop();
    }
    if (reversed == given){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
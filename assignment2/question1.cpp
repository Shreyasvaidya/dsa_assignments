#include <iostream>
using namespace std;
class Stack{
	private:
		int array[200000];//Random large number, INT_MAX giving segfault
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
		void Push(int elem){
			head++;
			array[head] = elem;
		}
		
		void Pop(){
			if (this -> empty()){
				cout<<"stack is empty"<<endl;
			}
			else{
				head --;
			}
		}
		void peek(){
			if (this ->empty()){
				cout<<-1<<endl;
			}
			else{
				cout<< array[head]<<endl;
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
int main() {
	// your code goes here
	int q;
	cin >>q;
	Stack stack;
	for(int _=0;_<q;_++){
		string command;
		cin>> command;
		if (!command.compare("push")){
			int entered;
			cin>>entered;
			stack.Push(entered);

		}
		else if (!command.compare("pop")){
		
			stack.Pop();
		}
		else if (!command.compare("peek")){
			stack.peek();	
		}
		else if (!command.compare("size")){
			stack.size();
		}
		else if (!command.compare("isempty")){
			stack.isempty();
		}
	}
	return 0;
}

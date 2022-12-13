#include<iostream>
using namespace std;
class Stack{
	private:
		int array[200000];//Random large number, INT_MAX giving segfault
		int head = -1;
		int min=-1;
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
			int to_be_pushed;
			if (empty()){
				min = elem;
				to_be_pushed = elem;
			}
			else if (elem>min){
				to_be_pushed = elem;
			}
			else{
				to_be_pushed = 2*elem - min;
				min = elem;
				
			}
            head++;
			array[head] = to_be_pushed;
		}
		
		void pop(){
			if (this -> empty()){
				;
			}
			else if (top()<min){
				min = 2*min-top();
				head --;
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
		int getmin(){
			return min;
		}
		
};

int main(){
	int tc;
	cin >>tc;
	Stack s;
	for(int _=0;_<tc;_++){
		string command;
		cin>> command;
		if (!command.compare("push")){
			int entered;
			cin>>entered;
			s.push(entered);

		}
		else if (!command.compare("pop")){
		
			s.pop();
		}
		
		else if (!command.compare("getmin")){
			cout<<s.getmin()<<endl;
		}
		else if (!command.compare("top")){
			cout<<s.top()<<endl;
		}
	}

    return 0;
}
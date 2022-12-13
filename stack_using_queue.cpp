#include <iostream>

using namespace std;
class Queue{
  private:
    int array[20000];
  public:
  	int head = 0;
    int tail = 0;
    bool empty(){
      if (tail== head){
        return true;
      }
      else{
        return false;
      }
    }
    int qsize(){
	return tail-head;


    }
    
    void enqueue(int x){
      array[tail] = x;
      tail++;
    }
    int dequeue(){
      if (!this -> empty()){
        int value = array[head];
		head++;
		return value;
      }      
      else{
      	return -1;
      }
    }
    int front(){
	if (!this -> empty()){
           return array[head];
	
      	}   
    	else{
	   return -1;
        }
    }	
    int rear(){
		if (!this -> empty()){
			return array[tail-1];
		
			}   
		else{
		return -1;
			}
		}
   
};
class stack_using_queue{
	private:
		Queue q;
	public:
		void push(int elem){
			q.enqueue(elem);


		}
		void pop(){
			if(!q.empty()){
				int size = q.qsize();
				for(int _=1;_<size;_++){
					int removed = q.dequeue();
					q.enqueue(removed);
				}
			q.dequeue();
			}
		
			else{
				cout<<"stack is empty"<<endl;
			}
		}
		void size(){
			cout<<q.qsize()<<endl;
		}
		void top(){
			cout<<q.rear()<<endl;
		}
		void isempty(){
			if(q.empty()){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		
};
		
int main() {
	// your code goes here
	int q;
	cin >>q;
	stack_using_queue stack;
	for(int _=0;_<q;_++){
		string command;
		cin>> command;
		if (!command.compare("push")){
			int entered;
			cin>>entered;
			stack.push(entered);

		}
		else if (!command.compare("pop")){
		
			stack.pop();
		}
		else if (!command.compare("top")){
			stack.top();	
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


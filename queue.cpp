#include <iostream>
using namespace std;
class Queue{ //my implementation , will later use to make stacks
  private:
    int array[20000];
  public:
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
    int head = 0;
    int tail = 0;
    void enqueue(int x){
      array[tail] = x;
      tail++;
    }
    void dequeue(){
      if (!this -> empty()){
        
		head++;
		
      }      
      else{
      	cout<<"queue is empty"<<endl;
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
	if (!(this -> empty())){
           return array[tail-1];
	
      	}   
    	else{
	   return -1;
        }
    }
   
};
int main() {
	
	// your code goes here
	int tc;
	cin >>tc;
	Queue q;
	for(int _=0;_<tc;_++){
		string command;
		cin>> command;
		if (!command.compare("push")){
			int entered;
			cin>>entered;
			q.enqueue(entered);

		}
		else if (!command.compare("pop")){
		
			q.dequeue();
		}
		else if (!command.compare("front")){
			cout<<q.front()<<endl;	
		}
		else if (!command.compare("back")){
			cout<<q.rear()<<endl;	
		}
		else if (!command.compare("size")){
			cout<<q.qsize()<<endl;
		}
		else if (!command.compare("isempty")){
			cout<<(q.empty()?1:0)<<endl;
		}
	}
	return 0;
}



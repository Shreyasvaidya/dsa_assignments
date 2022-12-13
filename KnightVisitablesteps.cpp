#include<iostream>

using namespace std;
template<class T>
class Queue{ 
	private:
		T* array;
	public:
		int head;
		int tail;
		Queue(){
			array = new T[200];
			head =0;
			tail = 0;
		}
		
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
		
		void enqueue(T x){
			array[tail] = x;
			tail++;
		}
		T dequeue(){
			if (!this -> empty()){
				T value = array[head];
				head++;
				return value;
			}      
			else{
				return NULL;
			}
		}
		T front(){
			if (!this -> empty()){
				return array[head];
		
			}   
			else{
				return NULL;
			}
		}	
		T rear(){
			if (!(this -> empty())){
				return array[tail-1];
			
				}   
			else{
				return NULL;
				}
		}
	
	};
class cell{
	public:
	int x;
	int y;
	int distance;
	public:
		cell(){

		}
		cell(int xcoord,int ycoord,int d){
			x=xcoord;
			y=ycoord;
			distance=d;
		}
};
bool ingrid(int x,int y,int chessX,int chessY){
	return(x<=chessX &&  y<=chessY);
}
int shortest_path(int initX,int initY, int finX,int finY,int chessX,int chessY){
	
	Queue<cell*> queue;
	bool visited[chessX+1][chessY+1];
	cell* first = new cell(initX,initY,0);
	queue.enqueue(first);
	while(!queue.empty()){
		cell* curr = queue.dequeue();
		
		if(curr->x==finX && curr->y==finY)
			return curr->distance;

		if(!(visited[curr->x+2][curr->y+1]) && ingrid(curr->x+2,curr->y+1,chessX,chessY)){
			visited[curr->x+2][curr->y+1] = true;
			queue.enqueue(new cell(curr->x+2,curr->y+1,curr->distance+1));
		}
		if(!(visited[curr->x+2][curr->y-1]) && ingrid(curr->x+2,curr->y-1,chessX,chessY)){
			visited[curr->x+2][curr->y-1] = true;
			queue.enqueue(new cell(curr->x+2,curr->y-1,curr->distance+1));
		}
		if(!(visited[curr->x-2][curr->y-1]) && ingrid(curr->x-2,curr->y-1,chessX,chessY)){
			visited[curr->x-2][curr->y-1] = true;
			queue.enqueue(new cell(curr->x-2,curr->y-1,curr->distance+1));
		}
		if(!(visited[curr->x-2][curr->y+1]) && ingrid(curr->x-2,curr->y+1,chessX,chessY)){
			visited[curr->x-2][curr->y+1] = true;
			queue.enqueue(new cell(curr->x-2,curr->y+1,curr->distance+1));
		}
		if(!(visited[curr->x-1][curr->y+2]) && ingrid(curr->x-1,curr->y+2,chessX,chessY)){
			visited[curr->x-1][curr->y+2] = true;
			queue.enqueue(new cell(curr->x-1,curr->y+2,curr->distance+1));
		}
		if(!(visited[curr->x-1][curr->y-2]) && ingrid(curr->x-1,curr->y-2,chessX,chessY)){
			visited[curr->x-1][curr->y-2] = true;
			queue.enqueue(new cell(curr->x-1,curr->y-2,curr->distance+1));
		}
		if(!(visited[curr->x+1][curr->y-2]) && ingrid(curr->x+1,curr->y-2,chessX,chessY)){
			visited[curr->x+1][curr->y-2] = true;
			queue.enqueue(new cell(curr->x+1,curr->y-2,curr->distance+1));
		}
		if(!(visited[curr->x+1][curr->y+2]) && ingrid(curr->x+1,curr->y+2,chessX,chessY)){
			visited[curr->x+1][curr->y+2] = true;
			queue.enqueue(new cell(curr->x+1,curr->y+2,curr->distance+1));
		}
		

	}
	return -1;
}
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int c,d;
	cin>>c>>d;
	int e,f;
	cin>>e>>f;
	cout<<shortest_path(c,d,e,f,a,b)<<endl;
}
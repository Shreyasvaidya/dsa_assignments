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
			array = new T[2000000];
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

/*
cooord
visited
adjacent
if_present(target,source)
    queue.ins(target)
    getadj(target)
    
*/

class coord{
    public:
    int x;
    int y;
    coord(){}
    coord(int a,int b){
        x=a;
        y=b;
    }
};
coord* adjacent = new coord[8];
bool**  visited;
int** input;
void get_adjacent(int i,int j){
    adjacent[0].x= i+1;
    adjacent[0].y=j+1;
    adjacent[1].x= i+1;
    adjacent[1].y=j;
    adjacent[2].x= i;
    adjacent[2].y=j+1;
    adjacent[4].x= i;
    adjacent[4].y=j-1;
    adjacent[5].x= i-1;
    adjacent[5].y=j-1;
    adjacent[6].x= i-1;
    adjacent[6].y=j;
    adjacent[7].x= i+1;
    adjacent[7].y=j-1;    
    adjacent[3].x= i-1;
    adjacent[3].y=j+1;
}
bool ingrid(int x,int y, int n,int m){
    return (x>=0 && y>=0 && x<n && y<m);
}
bool bfs(int sourcex, int sourcey,int n,int m,int targetx,int targety){
    visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    Queue<coord*> q;
    q.enqueue(new coord(sourcex,sourcey));
    while(!q.empty()){
        coord* curr = q.dequeue();
        if (curr->x == targetx && curr->y == targety)
            return true;
        visited[curr->x][curr->y]=true;
        get_adjacent(curr->x,curr->y);
        for(int i=0;i<8;i++){
            if( ingrid(adjacent[i].x,adjacent[i].y,n,m) && input[adjacent[i].x][adjacent[i].y] && !(visited[adjacent[i].x][adjacent[i].y])){
                q.enqueue(new coord(adjacent[i].x,adjacent[i].y));
            }
        }
        delete curr;
        
    }
    return false;
}
bool solution(int n,int m,int targetx,int targety){
    int count=0;

    for(int i=0;i<n;i++){
        
        if(input[i][0] && bfs(i,0,n,m,targetx,targety))
            return true;
        else if(input[i][m-1] && bfs(i,m-1,n,m,targetx,targety))
            return true;

    }
    for(int i=1;i<m-1;i++){//0 and m taken care above
        if(input[0][i] && bfs(0,i,n,m,targetx,targety))
            return true;
        else if(input[n-1][i] && bfs(n-1,i,n,m,targetx,targety))
            return true;

    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    input = new int*[n];
    for(int i=0;i<n;i++){
        input[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }
    int x,y;
    cin>>x>>y;

    cout<<solution(n,m,x,y)<<endl;
}
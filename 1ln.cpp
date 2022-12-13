#include<iostream>
using namespace std;
int ** adjacency;
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
				return -1;
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
int findmaxconnected(int vertex,int n){
    int maxans=0;
    bool* visited = new bool[n];
    visited[vertex] = true;
    Queue<int> q;
    q.enqueue(vertex);
    while(!q.empty()){
        int curr = q.dequeue();
        for(int i=0;i<n;i++){
            if (adjacency[curr][i] && !visited[i]){
                if(i>maxans)
                    maxans=i;
                q.enqueue(i);
            }


        }
        visited[curr]=true;

    }
    return maxans;
}
int findminconnected(int vertex,int n){
    int minans=n-1;
    bool* visited = new bool[n];
    visited[vertex] = true;
    Queue<int> q;
    q.enqueue(vertex);
    while(!q.empty()){
        int curr = q.dequeue();
        for(int i=0;i<n;i++){
            if (adjacency[curr][i] && !visited[i]){
                if(i<minans)
                    minans=i;
                q.enqueue(i);
            }


        }
        visited[curr]=true;

    }
    return minans;
}
int main(){
    int n,m;
    cin>>n>>m;
    adjacency = new int*[n];
    for(int i=0;i<n;i++){
        adjacency[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            adjacency[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        adjacency[p-1][q-1]=1;
        adjacency[q-1][p-1]=1;
    }
    int maxconnected = findmaxconnected(0,n);
    
    cout<<n-maxconnected-1<<endl;
}
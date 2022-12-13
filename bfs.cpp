#include<iostream>

using namespace std;

class Queue{ 
  private:
  int* array;
  public:
    Queue(){
      array = new int[200];
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
    int head = 0;
    int tail = 0;
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
	if (!(this -> empty())){
           return array[tail-1];
	
      	}   
    	else{
	   return -1;
        }
    }
   
};
class Graph{
    private:
        int num_vertices;
        Queue * adjacency  ;
    public:
        Graph(int v){
            num_vertices=v;
            adjacency= new Queue[v];
        }
        void add_edge(int v,int w){
            adjacency[v].enqueue(w);
            adjacency[w].enqueue(v);
        }
        int bfs(int s,int to_be_ignored,int target){
            bool* visited = new bool[num_vertices];  
            for(int i=0;i<num_vertices;i++){
              visited[i]= false;
            }
            Queue queue;
            queue.enqueue(s);
            visited[s] = true;
            if(queue.qsize()==1 && queue.front()==to_be_ignored)
              return 0;
            while(!queue.empty()){
                int curr = queue.dequeue();
                while(!adjacency[curr].empty()){
                    int elem = adjacency[curr].dequeue();
                    if(elem == target)
                      return 1;
                    if(elem==to_be_ignored)
                      continue;
                    
                    if(!visited[elem]){
                        visited[elem]=true;
                        queue.enqueue(elem);
                    }
                }
                
            }
            return 0;
        }
};
//test
int main()
{
    // Create a graph given in the above diagram
    int n_friends,n_pairs,k;
    cin>>n_friends>>n_pairs>>k;
    Graph g(n_friends);
    for(int i=0;i<n_pairs;i++){
      int u,v;
      cin>>u>>v;
      g.add_edge(u,v);

    }
    cout<<g.bfs(1,k,n_friends)<<endl;
 
    return 0;
}

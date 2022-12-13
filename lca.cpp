/*
python code which does the job(for personal reference)
nt = input()
n= nt.split()[0]
t = nt.split()[1]
n,t=int(n),int(t)
givenstr = input()
givenlist = givenstr.split()
for i in range(len(givenlist)):
  givenlist[i] = int(givenlist[i])

for i in range(t):
  pq= input()
  
  p= pq.split()[0]
  q = pq.split()[1]
  p,q=int(p),int(q)
  if(p not in givenlist or q not in givenlist):
    print("-1\n")
    continue
  lower_index = min(givenlist.index(p),givenlist.index(q))
  greater_index = max(givenlist.index(p),givenlist.index(q))
  previous_parent = 0
  for i in range(lower_index+1):
    if((givenlist[lower_index]>givenlist[previous_parent] and givenlist[greater_index]<givenlist[previous_parent]) or (givenlist[lower_index]<givenlist[previous_parent] and givenlist[greater_index]>givenlist[previous_parent])):
      lca = previous_parent
      break
    elif (givenlist[i]-givenlist[previous_parent])*(givenlist[lower_index]-givenlist[previous_parent])<0:
       #means opposite side of previous parent than the other two
       continue
    else:
      previous_parent = i
  lca = previous_parent
  print(givenlist[previous_parent])

*/
#include<iostream>
using namespace std;
int find_index(int* arr,int len ,  int elem){
    for(int i=0;i<len;i++){
        if(arr[i]== elem){
            return i;
        }
        
       
    }
    return 404; 
}
bool present(int elem, int* arr , int len){
       for(int i=0;i<len;i++){
        if(arr[i]== elem){
            return true;
        }
        
       
    }
    return false; 
}
int main(){
    int n_nodes , n_queries;
    cin>>n_nodes>>n_queries;
    int * elements = new int[n_nodes];
    for(int i=0;i<n_nodes;i++){
        cin>>elements[i];
    }
    for(int _=0;_<n_queries;_++){
        int p,q;
        cin>>p>>q;
        if(!present(p,elements,n_nodes)|| !present(q,elements,n_nodes)){
            cout<<-1<<endl;
            continue;
        }
        int lower_index = min(find_index(elements,n_nodes,p),find_index(elements,n_nodes,q));
        int greater_index = max(find_index(elements,n_nodes,p),find_index(elements,n_nodes,q));
        int previous_parent_at = 0;
        int lca_at;
        for(int i=0;i<=lower_index;i++){
            if((elements[lower_index]>elements[previous_parent_at] && elements[greater_index]<elements[previous_parent_at]) || (elements[lower_index]<elements[previous_parent_at] && elements[greater_index]>elements[previous_parent_at])){
                lca_at = previous_parent_at;
                
                break;

            }
            else if((elements[i]-elements[previous_parent_at])*(elements[lower_index]-elements[previous_parent_at])<0){
                continue;
            }
            else{
                previous_parent_at=i;
                
            }


        }
        lca_at=previous_parent_at;
        cout<<elements[lca_at]<<endl;

    }








    return 0;
}
#include<iostream>
#include <cmath>
using namespace std;
class node{
    public:
        int power;
        int coeff;
        node* next;
};
class MyLinkedList{
    
    private:
        node * head;node* curr; 
    public:
        int lenlist;

        MyLinkedList(int len){

            lenlist = len;
            
            head = new node;
            curr = head;
            for(int i = 1;i<len;i++){
                
                
                node* next_node = new node;
                curr ->next = next_node;
                
                curr = next_node;
            }
            curr -> next = NULL;
        }
        node* pointer_to_postition(int pos){
                node *current_node = this ->head;
                for(int i =1;i<pos;i++){
                    current_node = current_node ->next;
                }
                
                return current_node;
        }
};
class Polynomial{
    private:
        
        MyLinkedList *implementor;
    public:
        int len;
        Polynomial(int lengiven,int *arrayofElements){
            
            len = lengiven;

            implementor = new MyLinkedList(len);
            
            
            for(int i = 1;i<=len;i++){
                
                (implementor ->pointer_to_postition(i)) ->coeff = arrayofElements[i-1];
                (implementor ->pointer_to_postition(i)) ->power = len-i;
                
            }
            
        }
        int calculate(int x){
            int sum = 0;
            
            for(int i = 1;i<=this ->len;i++){
                sum+= (((this ->implementor) -> pointer_to_postition(i)->coeff)*round(pow(x,((this ->implementor) ->pointer_to_postition(i)->power)))) ;
                
            } 
            
            return sum;          
        }
        Polynomial* add(Polynomial* other){
            int max_len = this ->len;
            if(other->len>this ->len){
                max_len = other->len;
                
            }
            int *array_of_sum = new int[max_len];
            for(int i = 0;i<max_len;i++){
                if(i<other->len && i< this ->len){
                    array_of_sum[max_len-i-1] = ((this ->implementor) ->pointer_to_postition((this ->len)-i) ->coeff)+
                    ((other->implementor) -> pointer_to_postition(other ->len-i) ->coeff);
                    
                }
                else if(i >= (this->len)){
                    array_of_sum[max_len-i-1] =((other->implementor) ->pointer_to_postition(other ->len-i) ->coeff);

                }
                else{
                    array_of_sum[max_len-i-1] = ((this ->implementor)->pointer_to_postition(this ->len-i) ->coeff);
                }
                
            }
            Polynomial* ans = new Polynomial(max_len,array_of_sum);
            
            delete array_of_sum;
            
            return ans;
        }
        Polynomial* sub_and_multiply5(Polynomial* other){
            int max_len = this ->len;
            if(other->len>this ->len){
                max_len = other->len;
                
            }
            int *array_of_diff = new int[max_len];
            for(int i = 0;i<max_len;i++){
                if(i<other->len && i< this ->len){
                    array_of_diff[max_len-i-1] = 5*(((this ->implementor) ->pointer_to_postition((this ->len)-i) ->coeff)-
                    ((other->implementor) -> pointer_to_postition(other ->len-i) ->coeff));
                    
                }
                else if(i >= (this->len)){
                    array_of_diff[max_len-i-1] =-5*((other->implementor) ->pointer_to_postition(other ->len-i) ->coeff);

                }
                else{
                    array_of_diff[max_len-i-1] = 5*((this ->implementor)->pointer_to_postition(this ->len-i) ->coeff);
                }
                
            }
            Polynomial* ans = new Polynomial(max_len,array_of_diff);
            delete array_of_diff;
            
            return ans;

        }




};

int main(){
    int n_testcase;
    
    
    cin>>n_testcase;
    for(int _=0;_<n_testcase;_++){
        int degree1,degree2,*array1,*array2;
        cin>>degree1;
        cin>>degree2;
        array1 = new int[degree1+1];
        array2 = new int[degree2+1];
        for(int i=0;i<degree1+1;i++){
            cin>>array1[i];
        }
        for(int i=0;i<degree2+1;i++){
            cin>>array2[i];
        }
        
        int x_value;
        
        cin>>x_value;
        
        Polynomial* P1 = new Polynomial(degree1+1,array1);
        Polynomial* P2 = new Polynomial(degree2+1,array2);
        Polynomial * P3 = P1 ->add(P2);
        Polynomial *P4 = P3 ->sub_and_multiply5(P1);
        
        cout<<P1 ->calculate(x_value)<<" "<<P2 ->calculate(x_value)<<" "<<P3 ->calculate(x_value)<<" "<<P4->calculate(x_value)<<" "<<endl;
    }
    return 0;
}
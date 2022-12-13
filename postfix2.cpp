/*
for i in string 
if i=='+'
    n2= pop
    n1=pop
    new string 
    */
#include<iostream>



using namespace std;
float round_to_2(float num){
    if(num>0){
        float setted = (int)(100*num + 0.5);//int typeecasting will floor the value
        return  ((float)setted)/100 ;
   }
    
    
    else{
        float setted = (int)(100*num - 0.5);//int typeecasting will floor the value
        
        return ((float)setted)/100 ;
    }
}

int str_len(string s){
    int i=0;
    while(s[i]!= '\0'){
        i++;
    }
    return i;

}
class Stack{
	private:
		float array[200000];//Random large number, INT_MAX giving segfault
		int head = -1;
		
	public:
		bool empty(){
			if (head ==-1){
				return true;
			}
			else{
				return false;
			}
		}
    	void push(float elem){
			head++;
			array[head] = elem;
		}
		
		void pop(){
			if (this -> empty()){
				cout<<"stack is empty"<<endl;
			}
			else{
				head --;
			}
		}
		float top(){
			
			if(!empty()){
				return array[head];
			}
            else{
                return -1;
            }
        }
		
		int size(){
			return head+1;
		}
		
};
int main(){
    string input;
    cin>>input;
    Stack stack;
    int strlen = str_len(input);
    
    char element;
    bool error = false;
    /*//what follows is a hack for ˆ (U+02c6) given in input ,instead of ^ ,which is a multibyte character and is causing problems
    
    string input="";
    for(int i =0;i<str_len(input1);i++){
        if (sizeof(input1[i]) ==2){
            input+='^';
        }
        else if (sizeof(input1[i-1]) == 2){
            continue;
        }
        else{
            input+=input1[i];
        }
    }
    //hack ends*/
    //Did not work :-/
    //thankfully test cases updated
    int i=0;
    while(i<str_len(input)){
        element = input[i];
        
        if (element>='0' && element <='9'){
            string to_be_pushed(1,element);
            while(input[i+1]!=','){
                i++;
                to_be_pushed+=input[i];
            }
            stack.push(stoi(to_be_pushed));
            


        }

        else if (element =='+' || element =='-' ||element =='*' ||element =='/' ){
            string elementstr(1,element);
            if(stack.size()>=2){
                float num2 = stack.top();
                stack.pop();
                float num1 = stack.top();
                stack.pop(); 
                
                float to_be_pushed ;
                if(element == '+'){
                    to_be_pushed = num1+num2;
                }
                else if(element == '-'){
                    to_be_pushed = num1-num2;
                }
                else if(element == '*'){
                    to_be_pushed = num1*num2;
                }
                else if(element == '/'){
                    to_be_pushed = ((float)num1)/num2;
                   
                    to_be_pushed = round_to_2(to_be_pushed);
                    
                }
                stack.push(to_be_pushed);
            }
            else{
                error = true;
                cout<<"error"<<endl;
            }
        
        }
        else if ( element =='^'){
            float to_be_pushed;
            string elementstr(1,element);
            if(stack.size()>=1){
                float num = stack.top();
                stack.pop();
                to_be_pushed = num*num;
                
                
                stack.push(to_be_pushed);
            }
            
            else{
                error = true;
                cout<<"error"<<endl;
            }
            
        }
        else if (element == ','){
            i++;
            continue;
        }
        else{
            if (sizeof(input[i]==2)){
            }
        }
        i++;

    }
    if (stack.size()==1 && !error){
        float x = stack.top() - (int) stack.top();
        if(x>= -0.001 && x<= 0.001){//basically has a .00 form
            cout<<(int)stack.top()<<endl;
        }
        else{
            cout<<stack.top()<<endl;
        }
    }
    else{
        cout<<"error"<<endl;
    }
    return 0;
}
#include <iostream> 
using namespace std; 

class node{
    public: 
    int data; 
    node* next; 
    
    node(int d){
        data = d; 
        next = NULL; 
    }

};

class Stack{
    private:
    node* top; 
    
   public: 
    Stack(){
    top = NULL; 
   }
    void push(int d){
        node* newnode = new node(d); 
        if(top == NULL){
            top = newnode; 
        }
        else{
            newnode->next = top; 
            top = newnode;
        }
    }

    int pop(){
        if(top == NULL){
            cout<<"No data"; 
            return -1; 
        }
        else{
            int val = top->data; 
            node* temp = top; 
            top = temp->next; 
            delete temp; 
            return val; 

        }
    }

    void display(){
        node* temp=top; 
        if(top== NULL){
            cout<<"No data\n\n\n"; 
            return; 
        }
        else{
            cout<<"The item on the lists are : \n"; 
            while(temp!=NULL){
                
                cout<<temp->data<< ' ';
                temp = temp->next; 
            }
            cout<< endl;
        }
        
    }

    bool isEmpty(){
        return top==nullptr; 
    }

    int peek(){
        return top->data; 
    }
    
    void reverse(){
            node* prev, *curr, *next; 

            prev = nullptr; 
            curr = top;
            next = nullptr; 
            while(curr!= nullptr){
                next = curr->next; 
                curr->next = prev; 
                prev = curr; 
                curr = next; 

            }
            top = prev; 
             
        }

     Stack copyStack(){
            Stack temp, result; 
            node *curr = top; 
            while(curr!= nullptr){
                temp.push(curr->data); 
                curr= curr->next; 
            }
            curr = temp.top; 
            while(curr!=nullptr){
                result.push(curr->data); 
                curr= curr->next; 
            }
            return result; 
        }
       
     void printbinary(int num){
            if(num == 0){
                cout<<"0"; 
                return; 
            }
            Stack binarySt; 
            while(num>0){
                binarySt.push(num%2); 
                num/=2; 
                
            }
            while(!binarySt.isEmpty()){
                cout<<binarySt.pop();
            }
            
            
            
        }


    void reverse(Stack &s){ 
        Stack temp; 
        while(!s.isEmpty()){
            temp.push(s.pop()); 
        }
       s= temp; 
        }




    int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


bool isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}


void infixtopostfix(char infix[], char postfix[]) {
    Stack st;
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[j++] = st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(') {
                st.pop(); 
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch) && st.peek() != '(') {
                postfix[j++] = st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';


}



    bool areParenthesesBalanced(const char* expr) {
    Stack st;
    for (int i = 0; expr[i] != '\0'; ++i) {
        char ch = expr[i];
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.isEmpty()) return false;
            st.pop();
        }
        
    }
    return st.isEmpty();
}
};


int main(){
    Stack s; 
 
    

    int n, val; 
    cout<<"How many numbers you want to enter(2/3)"; 
    cin>>n; 
    if(n<2 || n>3){
        cout<<"Invalid numbers"; 
    }
    cout<<"Enter " <<n<< " data\n";
    for(int i=0; i<n; i++){
        cout<<"Enter number "<<i+1<<" value"; 
        cin>>val;
        s.push(val);  

    }
    cout<<"Binary values are : "; 
    while(!s.isEmpty()){
        int num = s.pop(); 
        cout<< num<< " -> "; 
        s.printbinary(num); 
        cout<<endl; 

    }


    char infix[101];
    char postfix[101];
    cout << "Enter infix expression (max 100, variables as single letters): ";
    cin >> infix;
    s.infixtopostfix(infix, postfix);
    cout << "Postfix expression is: " << postfix << endl;




    char expr[201];
    cout << "Enter an equation: ";
    cin >> expr;
    if (s.areParenthesesBalanced(expr)) {
        cout << "Parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are NOT balanced." << endl;
    }
    
    return 0; 
}
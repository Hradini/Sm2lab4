#include <iostream>
using namespace std;

struct node{ //creates node type srtucture
	int data;
	node *next;
};
class StackLL{
	node *top;
public:
	StackLL(){//default constructor
	top=NULL;
	}
	//functions
	void push(int data);
	void pop();
	void display();
};
void StackLL::push(int data){ //adds new node to top of the stack
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	if(top!=NULL){
		temp->next = top;
	}
	top = temp;
}
void StackLL::pop(){//removes node from top of the stack
	node *temp;
	temp=top;
	if(temp==NULL){
	cout<<"Can't pop from empty stack";
	}else{
		top=top->next;
		delete temp;
	}
}

void StackLL::display(){ //displays all the elements of the stack
	node*temp;
	temp=top;
	while(temp!=NULL){
	cout<<temp->data<<endl;
	temp=temp->next;
	}
	//cout<<temp->data
}

int main(){
StackLL s;
    int choice;
    int x;
//makes a menu
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tSTACK USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nPlease enter correct choice(1-4)!!";
                break;
        }
    }
    return 0;
}
	
	

#include <iostream>
using namespace std;

struct node{//creates node type structure
	int data;
	node *next;
};
class StackLL{
	public:
		node *top;
		StackLL(){//default constructor
			top=NULL;
		}
	//functions
		void push(int data);
		void pop();
		void display();
};
void StackLL::push(int data){//adds new node to top of stack
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	if(top!=NULL){
		temp->next = top;
	}
	top = temp;
}
void StackLL::pop(){//removes data from top of stack
	node *temp;
	temp=top;
	if(temp==NULL){
	cout<<"Can't pop from empty stack";
	}else{
		top=top->next;
		delete temp;
	}
}
void StackLL::display(){ //diplays all elements of the stack from top to bottom
	node*temp;
	temp=top;
	while(temp!=NULL){
	cout<<temp->data<<endl;
	temp=temp->next;
	}
}
class QueueS{ //creates a queue structure
	public:
		StackLL S1, S2; //creates 2 stacks
	//functions	
		void enqueue(int data);
		void dequeue();
		void display();
};

void QueueS::enqueue(int data){//adds data to the queue at the rear
	S1.push(data);//adds data to stack 1
}

void QueueS::dequeue(){//removes data from front of queue
	if(S1.isEmpty()){ //checks if queue is empty or not
		cout<<"Queue is empty";
	}else{
		while((S1.top)!= NULL){ //moves data from stack 1 to stack 2 so that last elememt becomes first element
			S2.push((S1.top)->data);
			(S1.top)=(S1.top)->next;
		}
		S2.pop(); //removes first element of stack 2
		while((S2.top) != NULL){ //moves data from stack 2 to stack 1 so that last element becomes first element
			S1.push((S2.top)->data);
		}
	}
}

void QueueS::display(){//displays all the elements of the queue - first in first to be displayed
	if(S1.isEmpty()){
		cout<<"Queue is empty";
	}else{
		while((S1.top)!= NULL){//moves data from stack 1 to stack 2 so that last elememt becomes first element
			S2.push((S1.top)->data);
			(S1.top)=(S1.top)->next;
		}
		S2.display();//displays elements of the stack 2
		while((S2.top) != NULL){//moves data from stack 2 to stack 1 so that last element becomes first element
			S1.push((S2.top)->data);
		}
	}
}

int main(){
	QueueS q;
    int choice;
    int x;
//makes a menu
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tQUEUE USING 2 STACKS\n\n";
        cout<<"1:ENQUEUE\n2:DEQUEUE\n3:DISPLAY QUEUE\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
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

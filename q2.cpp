#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};
class StackLL{
	
	public:
		node *top;
		StackLL(){
		top=NULL;
		}
		void push(int data);
		void pop();
		void display();
		bool isEmpty();
};
bool StackLL::isEmpty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

void StackLL::push(int data){
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	if(top!=NULL){
		temp->next = top;
	}
	top = temp;
}
void StackLL::pop(){
	node *temp;
	temp=top;
	if(temp==NULL){
	cout<<"Can't pop from empty stack";
	}else{
		top=top->next;
		delete temp;
	}
}
void StackLL::display(){
	node*temp;
	temp=top;
	while(temp!=NULL){
	cout<<temp->data<<endl;
	temp=temp->next;
	}
}
class QueueS{
	public:
		StackLL S1, S2;
		void enqueue(int data);
		void dequeue();
		void display();
};

void QueueS::enqueue(int data){
	S1.push(data);
}

void QueueS::dequeue(){
	if(S1.isEmpty()){
		cout<<"Queue is empty";
	}else{
		while((S1.top)!= NULL){
			S2.push((S1.top)->data);
			(S1.top)=(S1.top)->next;
		}
		S2.pop();
		while((S2.top) != NULL){
			S1.push((S2.top)->data);
		}
	}
}

void QueueS::display(){
	if(S1.isEmpty()){
		cout<<"Queue is empty";
	}else{
		while((S1.top)!= NULL){
			S2.push((S1.top)->data);
			(S1.top)=(S1.top)->next;
		}
		S2.display();
		while((S2.top) != NULL){
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

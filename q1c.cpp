#include <iostream>
using namespace std;

int Stack[20]; //creates an array of size 20
int top=-1;

bool isEmpty(){ //checks if stack is empty
	if(top==-1)
		return 1;
	else
		return 0;
}
bool isFull(){ //checks if stack is full
	if(top==19)
		return 1;
	else
		return 0;
}

void push(int data){ //adds data to last free space in array
	if(isFull()){
		cout<<"Stack is full";
	}else{
		++top;
		Stack[top]=data;
	}
}

void display(){ //displays all elements in array
int i;
	if(isEmpty()){
		cout<<"Stack is empty";
	}else{
		for(i=0;i<=top;i++){
			cout<<Stack[i]<<"\n";
		}
	}
}

void pop(){//removes the last element in the array
	if(isEmpty()){
		cout<<"Stack is empty";
	}else
		--top;
}

int main(){
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
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
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
	
		
	

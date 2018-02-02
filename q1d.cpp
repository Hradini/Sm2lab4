#include <iostream>
using namespace std;

int queue[20];//creates an array
int front=rear=0;

void enqueue(int data){ //adds elements at the rear
	if (rear == 20)
    	cout << "\nQueue Reached Max!!";
    else 
    	queue[rear++] = data;
}

void dequeue(){	//removes elements from front of queue
	if (front == rear)
    	cout << "\n## Queue is Empty!";
    else
    	front++;
}

void display(){//displays elements from front till rear
	int i=0;
	for(i=front;i<rear;++i){
		cout<<queue[i];
	}
}

int main(){
    int choice;
    int x;
    //makes menu
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tQUEUE USING ARRAY\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                enqueue(x);
                break;
            case 2:
                dequeue();
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
               

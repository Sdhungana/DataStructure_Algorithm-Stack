#include <iostream>
using namespace std;

class Stack
{
    private:    
        int size;    
        int *arr;
        int top;
    public:
       Stack(int stack_size)
        {
            size = stack_size;
            arr = new int[size];
            top = -1;
            for(int i=0 ; i<size; i++)
            {
                arr[i]=0;
            }
        }
        ~Stack()
        {
            delete[] arr;       // clearing heap memory
        }
        bool isEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;           
        }
        bool isFull()
        {
            if(top==size-1)
                return true;
            else
                return false;           
        }
        void push(int val)
        {
            if(isFull())
            {
                cout<<"Stack Overflow"<<endl;
            }
            else
            {
             top++;
             arr[top]=val;   
            }           
        }   
        void display()
        {
            cout<<"All values in the stack are"<<endl;
            for(int i=size-1; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }       
};

int main()
{
    int stack_size;
    cout<<"Enter stack size"<<endl;
    cin>>stack_size;
    Stack s1(stack_size);
    int option,value;
    do
    {
        cout<<"Which operation do you want to perform? Select an option number. Enter 0 to exit."<<endl;
        cout<<"1. Push()"<<endl;
        cout<<"2. Display()"<< endl;
        cout<<"3. Clearscreen"<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Push function called"<<endl;
                cout<<"Enter an item to push in the stack:"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout << "Display function called" << endl;
                s1.display();
                break;
            case 3:
                system("cls");
                break;
            default:
                cout<<"Enter proper option number "<<endl;
        }
    } while (option!=0);

   return 0;
} // s1 is destroyed here, so the ~Stack() destructor function is called here
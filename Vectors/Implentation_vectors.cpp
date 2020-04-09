#include <iostream>
using namespace std;

class Vector
{
    private:
        int cs;
        int ms;
        int *arr;
    public:
        Vector()
        {
            cs=0;
            ms=1;
            arr = new int[ms];
        }
        void push_back(const int d)
        {
            if(cs==ms) ///array is full 
            {
                int *oldArr= arr;
                arr = new int[2*ms];
                ms*=2;
                for(int i=0;i<cs;i++)
                {
                    arr[i]=oldArr[i];  ///copy elements from previous array into the new array, the new element to be added will be done by below part i.e. arr[cs++]=d;
                }
            }
            arr[cs++]=d;
        }
        void pop_back() 
        {
            cs--;
        }
        int front()
        const 
        {   
            if(cs==0)
            {
                cout<<"The vector is currently empty";
                return -1;
            }
            return arr[0];
        }
        int back()
        const 
        {
            if(cs==0)
            {
                cout<<"The vector is currently empty";
                return -1;
            }
            return arr[cs-1]; 
        }
        bool empty()
        const
        {
            return cs==0;
        }
        int size()
        const 
        {
            return cs;
        }
        int capacity()
        const 
        {
            return ms;
        }
        int at(int i)
        {
            if(i<=cs-1)
            {
                return arr[i];
            }
            else cout<<"Out of bounds";
        }

        ///operator overloading
        int operator [] (int i)
        {
            if(i<=cs-1)
            {
                return arr[i];
            }
            else cout<<"Out of bounds";
        }
        void display()
        const
        {
            for(int i=0;i<cs;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        

};


int main() {

    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    v.push_back(5);
    v.display();

    cout<<endl<<v.front()<<endl;
    cout<<v.back()<<endl;

    cout<<v.empty()<<endl;
    cout<<v.capacity()<<endl;
    cout<<v[2]<<" "<<v.at(2)<<endl;

    

    
}

#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

class Car
{   
    public:
    string carname;
    int x,y;

    Car()
    {

    }
    Car(string name,int a,int b)
    {
        carname = name;
        x=a;
        y=b;
    }
    int Distance()
    {   
        int d= x*x + y*y;
        return d;
    }

};

/* bool Lexicographical(string a,string b)
{
    for(int i=0;a[i]!='\0' || b[i]!='\0';i++)
    {
        if(a[i]<b[i])
        {
            return true;
        }
    }
    return true;
} */

bool compare(Car a, Car b)
{
    int d1= a.x*a.x + a.y*a.y;
    int d2= b.x*b.x + b.y*b.y;

    if(d1==d2)
    {
         return a.carname.length()<b.carname.length();
    }

    return d1 < d2;
}

int main() {
    
    int n;      ///no. of cars
    cin>>n;

    vector<Car> v;
    for(int i=0;i<n;i++)
    {
        string carname;
        int x,y;
        cin>>carname>>x>>y;
        Car temp(carname,x,y);
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),compare);

    for(auto w: v)
    {
        cout<<w.carname<<" at distance "<<w.Distance()<<" at location "<<w.x<<","<<w.y<<endl;  ///Distance ki jagah actually sqrt distance daalna hai 
    }
}

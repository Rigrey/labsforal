#include <iostream>
#include <cmath>
using namespace std;

void first(){
    cout <<"1 13 49"<<endl;
}
void second(){
    char b;
    cout << "Symbol for 2nd task:";
    cin >> b;
    cout <<"1"<<b<<"13"<<b<<"49"<<endl;
}
void third(){
    int a,b,c;
    cout << "Numbers for 3rd task: ";
    cin >> a >> b >> c;
    cout <<a<<" "<<b<<" "<<c<<endl;
}
void forth(){
    double a;
    double xy;
    cout << "Number 'a' for 4th task(part a): ";
    cin >> a;
    double x=12*pow(a,2) + 7*a -12;
    cout << "x=" << x <<endl;
    cout << "Number 'x' for 4th task(part b): ";
    cin >> xy;
    double y=3*pow(xy,3)+4*pow(xy,2)-11*xy+1;
    cout << "y=" << y <<endl;
}
double fifth(){
    double v,m;
    cout << "Enter mass and volume for 5th task: ";
    cin >> m >> v;
    cout << "p=";
    return m/v;
}
void sixth(){
    double a,b;
    cout << "Enter 'a' and 'b' for 6th task: ";
    cin >> a >> b;
    if (a==0) {cout<<"No solution"<<endl;}
    if (a!=0) {cout<<"x="<<-b/a<<endl;}
} 
double seventh(){
    double x_1, y_1, x_2, y_2;
    cout << "Enter coordinates for 7th task for 1st point (Ex. 5 3): ";
    cin >> x_1 >> y_1;
    cout << "Enter coordinates for 7th task for 2nd point (Ex. -9 4): ";
    cin >> x_2 >> y_2;
    cout << "D=";
    return sqrt(pow((x_1-x_2),2)+pow((y_1-y_2),2));
}
double eighth(){
    double a, b, h, part, d;
    cout << "Enter 2 bases and height of trapezoid for 8th task: ";
    cin >> a >> b >> h;
    part = abs(a-b)/2;
    d = sqrt(pow(part,2)+pow(h,2));
    cout << "P=";
    return a+b+2*d;
}
void nineth(){
    double a;
    cout << "Enter side of cube for 9th task: ";
    cin >> a;
    cout << "V=" << pow(a,3)<<endl;
    cout << "S=" << 6*pow(a,2)<<endl;
}
double tenth(){
    double a;
    cout << "Enter side of square for 10th task: ";
    cin >> a;
    cout << "P=";
    return 4*a;
}
double eleventh(){
    double r;
    cout << "Enter radius of circle for 11th task: ";
    cin >> r;
    cout << "d=";
    return 2*r;
}
void twelfth(){
    string name;
    cout << "Enter your name for 12th task: ";
    getline(cin,name);
    cout << "Hello, "<<name<<"! My name is C++";
}
int main(){
    first();
    second();
    third();
    forth();
    cout << fifth() <<endl;
    sixth();
    cout << seventh() <<endl;
    cout << eighth() <<endl;
    nineth();
    cout << tenth() <<endl;
    cout << eleventh() <<endl;
    twelfth();
    return 0;
}
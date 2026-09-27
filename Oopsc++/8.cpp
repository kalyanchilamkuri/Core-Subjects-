
// // Friend classes and member friend functions


// // here there are two classes ..to store and handle the complex numbers and to perform operations like summing the real and imaginary of complex numbers
// // The calculator class uses friend functions to access the private members (a,b) of the complex class.

// #include<bits/stdc++.h>
// using namespace std;

// //forward declaration 
// //Here we inform the compiler that a class named complex will be defined later
// class Complex; 

// class Calculator{
//     public:
//       int add(int a,int b){
//         return (a+b);
//       }
      
//       int sumRealComplex(Complex a,Complex b);
//       int sumCompComplex(Complex a,Complex b);
// };

// class Complex{
//     int a,b;
//     // individually declaring functions as friends
//     // only these 2 function get access of the private variables a and but no the other functions of the calculator class
//     // use this only when you want to limit access only to certain functions for encapsulation
//     friend int Calculator :: sumRealComplex(Complex o1,Complex o2);
//     friend int Calculator :: sumCompComplex(Complex o1,Complex o2);

//     // Alter : Declaring the entire calculator class as a friend
//     // This makes the entire calculator class ,including add(), sumrealcomplexsumcompcomplex and any future functions , can access the private variables of complex
//     // use when many functions in calculator need the access to complex's private data 
//     // easier , less repititive , especially if you have 5-10 functions declare
//     friend class Calculator

//     public:
//        void setNumber(int n1,int n2){
//          a=n1;
//          b=n2;
//        }

//        void printNumber(){
//           cout<<"Your number is"<<a<<" , "<<b<<" i "<<endl;
//        }
// };


// int Calculator :: sumRealComplex(complex o1,complex o2){
//     return (o1.a+o2.a);
// }

// int Calculator :: sumCompComplex(complex o1,complex o2){
//     return (o1.b+o2.b);
// }

// int main(){
//     Complex o1,o2;
//     o1.setNumber(1,4);
//     o2.setNumber(5,7);
//     Calculator calc;
//     int result=calc.sumRealComplex(o1,o2);
//     cout<<"The sum of real part of o1 and o2 is "<<result<<endl;
//     int resultco=calc.sumCompComplex(o1,o2);
//     cout<<"The sum of complex part of o1 and o2 is "<<result<<endl;
// }




// // using friend member functions

// #include<bits/stdc++.h>
// using namespace std;

// class Complex;

// class Calculator{
//   public:
//       int sumRealPart(Complex,Complex);
//       int sumImagPart(Complex,Complex);
// };

// class Complex{
//   int a,b;
//   friend int Calculator :: sumRealPart(Complex,Complex);
//   friend int Calculator :: sumRealPart(Complex,Complex);
//   public:
//       void setNumber(int x,int y){
//         a=x;
//         b=y;
//       }
//       void print(){
//         cout<<"complex number:"<<a<<" "<<b<<"i"<<endl;
//       }
// };

// int Calculator :: sumRealPart(Complex o1,Complex o2){
//   return o1.a+o2.a;
// }

// int Calculator :: sumRealPart(Complex o1,Complex o2){
//   return o1.b+o2.b;
// }

// int main(){
//   Complex c1,c2;
//   c1.setNumber(9,8);
//   c2.setNumber(9,7);
//   Calculator calc;
// }













// // using friend class


// #include<bits/stdc++.h>
// using namespace std;

// class calculator;

// class complex{
//   int a,b;
//   friend class calculator;
//   public:
//      void setNumber(int x,int y){
//        a=x;
//        b=y;
//      }
//      void print(){
//       cout<<"complex number: "<<a<<"+"<<b<<"i"<<endl;
//      }
// };

// class calculator{
//    public:
//       int sumRealPart(complex o1,complex o2){
//         return o1.a+o2.a;
//       }
//       int sumImagPart(complex o1,complex o2){
//         return o1.b+o2.b;
//       }
// };

// int main(){
//   Complex c1,c2;
//   c1.setNumber(1,2);
//   c2.setNumber(2,3);
//   calculator calc;
// }





#include<bits/stdc++.h>
using namespace std;

class Engine;

class car{
  private:int speed;
  public:
       Car(int s){speed=s;}

       //make engine class a friend
       friend class Engine; // Corrected: 'friend class Engine;'

       // make function a friend

       friend void func(Car &c)
};

class Engine{
  public:
      void show(Car c){
        cout<<"car speed is "<<c.speed<<endl;
      }
      void boost(Car& c){
        c.speed+=50;
        cout<<"boosted speed: "<<c.speed<<endl;
      }
};

void func(Car &c){
  c.speed+=20;
  cout<<"speed is "<<c.speed<<endl;
}

int main(){
     Car myCar(100);
     Engine e;
     e.show(myCar);
     e.boost(myCar);
     func(myCar);
     return 0;
}

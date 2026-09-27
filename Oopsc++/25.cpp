#include<bits/stdc++.h>
using namespace std;

class student {
    protected:
        int roll_number;
    public:
        void set_number(int a){
            roll_number = a;
        }
        void print_number(){
            cout << "Your roll no is " << roll_number << endl;
        }
};

class Test : virtual public student {
    protected:
        int maths;
        int physics;
    public:
        void set_marks(int m1, int m2){
            maths = m1;
            physics = m2;
        }
        void print_marks(){
            cout << "Maths marks are " << maths << " and Physics marks are " << physics << endl;
        }
};

class Sports : virtual public student {
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        }
        void print_score(){
            cout << "Your PT score is " << score << endl;
        }
};

class result : public Test, public Sports {
    private:
        float total;
    public:
        void display(){
            total = maths + physics + score;
            print_number();  // from student
            print_marks();   // from Test
            print_score();   // from Sports
            cout << "Your total score is: " << total << endl;
        }
};

int main() {
    result harry;
    harry.set_number(2023);
    harry.set_marks(100, 100);
    harry.set_score(80);
    harry.display();
    return 0;
}

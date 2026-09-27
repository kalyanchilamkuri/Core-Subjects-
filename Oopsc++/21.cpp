#include <bits/stdc++.h>
using namespace std;

class Student {
protected:
    int roll_number;

public:
    void set_rollnumber(int);
    void get_rollnumber(void);
};

void Student::set_rollnumber(int ok) {
    roll_number = ok;
}

void Student::get_rollnumber(void) {
    cout << roll_number << " is my roll number" << endl;
}

class Exam : public Student {
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam::set_marks(float m1, float m2) {
    maths = m1;
    physics = m2;
}

void Exam::get_marks() {
    cout << "The marks obtained in maths are: " << maths << endl;
    cout << "The marks obtained in physics are: " << physics << endl;
}

class Result : public Exam {
    float percentage;

public:
    void display() {
        get_rollnumber();
        get_marks();
        percentage = (maths + physics) / 2;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Result harry;
    harry.set_rollnumber(30);
    harry.set_marks(90, 90);
    harry.display();
}

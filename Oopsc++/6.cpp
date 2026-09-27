
// Array of objects and passing objects as function arguements


#include <bits/stdc++.h>
using namespace std;

class Employee {
    int id;
    int salary;

public:
    static int count;  // shared across all objects

    void setData(void) {
        cout << "Enter the id: ";
        cin >> id;
        salary = 122;
        count++;
    }

    void getData(void) {
        cout << "The id is " << id << " and this is employee number " << count << endl;
    }
};

// Definition of static variable
int Employee::count = 0;

int main() {
    Employee fb[4];  // 4 employees: fb[0] to fb[3]

    for (int i = 0; i < 4; i++) {
        fb[i].setData();   // Access individual object
        fb[i].getData();
    }

    return 0;
}




//  🔹 Q4: Can we pass objects from the array as function arguments?
// ✅ “Yes. We can pass fb[i] to a function like:”

void display(Employee e) {
    // use e.getData() or access members
}
display(fb[2]);
(You can expand this file to show that too if you like.)
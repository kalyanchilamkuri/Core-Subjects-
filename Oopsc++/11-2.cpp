#include <bits/stdc++.h>
using namespace std;
class Point {
    int x, y;
public:
    // Constructor
    Point(int a, int b) {
        x = a;
        y = b;
    }
    void displayPoint() {
        cout << "The point is (" << x << " , " << y << " ) " << endl;
    }
    // Friend function to calculate distance between two points
    friend double distanceBetween(Point p1, Point p2);
};
// Function to calculate distance
double distanceBetween(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
int main() {
    Point p(1, 1);
    p.displayPoint();
    Point q(4, 6);
    q.displayPoint();
    Point a(4, 6);          // Implicit constructor call
    Point b =Point(5, 7);   // Explicit constructor call
    double dist = distanceBetween(p, q);
    cout << "Distance between points: " << dist << endl;
    return 0;
}

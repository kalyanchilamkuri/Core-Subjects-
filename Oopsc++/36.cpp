#include <bits/stdc++.h>
using namespace std;

// rules for virtual functions

/*
*) they cannot be static
*) they are accessed but object pointers
*) virtual functions can be a friend of another class
*) a virtual function in base class might not be used
*) If a virtual function is defined in the base class then there is no need of redefining it in a derived class
*/

class cwh {
protected:
    char title[30];
    float rating;
public:
    cwh(char* s, float r) {
        strcpy(title, s);
        rating = r;
    }
    virtual void display() { cout<<"hello"<<endl; }  // pure virtual style optional
};

class cwhvideo : public cwh {
    float videolen;
public:
    cwhvideo(char* s, float r, float vl) : cwh(s, r) {
        videolen = vl;
    }
    void display(void) {
        cout << "This is an amazing video with title \"" << title << "\"" << endl;
        cout << "This video has rating: " << rating << " out of 5" << endl;
        cout << "Length of this video is: " << videolen << " minutes" << endl;
    }
};

class cwhtext : public cwh {
    int words;
public:
    cwhtext(char* s, float r, int wc) : cwh(s, r) {
        words = wc;
    }
    void display(void) {
        cout << "This is an amazing text tutorial with title \"" << title << "\"" << endl;
        cout << "This text has rating: " << rating << " out of 5" << endl;
        cout << "Number of words in this text is: " << words << endl;
    }
};

int main() {
    char title[] = "Django tutorial";
    float rating = 4.89;
    float vlen = 4.56;
    int words = 433;

    // Pointer to base class
    cwh* tutorials[2];

    // Creating video and text objects
    cwhvideo djVideo(title, rating, vlen);
    cwhtext djText(title, rating, words);

    // Storing base class pointers
    tutorials[0] = &djVideo;
    tutorials[1] = &djText;

    // Runtime polymorphism
    tutorials[0]->display();
    cout << "--------------------------" << endl;
    tutorials[1]->display();

    return 0;
}

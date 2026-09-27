// BUild a Google docs

#include<bits/stdc++.h>
using namespace std;

class DocEditor{
private:
     vector<string>docele;
     string renddoc;
public:
     // Add text as plain string
     void addText(string text){
        docele.push_back(text);
     }

     // renders the document by checking the type of each element at runtime 
     string renderDoc(){
        if(renderDoc.empty()){
            string res;
            for(auto ele:docele){
                if(ele.size()>4 && (ele.substr(ele.size()-4)==".jpg" || ele.substr(ele.size()-4)=="png")){
                    res+="[Image: "+ele+"]"++"\n";
                }else{
                    res+=element+"\n";
                }
            }
            renddoc=res;
        }
        return renddoc;
     }

     void savetofile(){
        ofstream file("document.txt");
        if(file is_open()){
            file<<renddoc();
            file.close();
            cout<<"Document saved to Doc.txt"<<endl;
        }else{
            cout<<"Error: Unable to open file for writing"<<endl;
        }
     }
};

int main(){
       DocEditor editor;
       
}

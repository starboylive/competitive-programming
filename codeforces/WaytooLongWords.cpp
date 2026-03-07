// Cpp 
#include <iostream>
#include <string> 
using namespace std;

int main() {

    //Number of Strings 
    int n; 
    cin >> n; 

    while(n--){
        string word; 
        cin >> word; 

            if(word.length() > 10 ){
                // string first,last;
                // int strlen = word.length() - 1;  
                // first = word[0]; 
                // last = word[strlen]; 
                
                cout << word.front() << word.length() - 2 << word.back() <<endl; 
            }
            else{
                cout << word << endl; 
            }

    }
   
    return 0;
}

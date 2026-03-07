#include <iostream>
#include <vector> 

using namespace std; 

int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n;  //size ra munda 
        cin >> n; 
        
        vector<int> a(n); 

        for(auto &x:a) cin >> x; 
        
        bool sorted = true; 
        for(int i=0; i < n; i++){
            if(a[i] > a[i+1]){
                sorted = false; 
                break; 
            }
        }

        if(sorted){
            cout << n <<endl; 
        }
        else{
            cout << 1 <<endl; 
        }

    }

    return 0; 
}
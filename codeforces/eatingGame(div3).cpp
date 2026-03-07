#include <iostream> 
#include <vector> 
using namespace std; 

int main(){


    int T; //Number of TestCases  
    cin >> T; 

    while(T--){

        int n; 
        cin >> n; 

        vector<int> a(n); 
        int mx = 0; 

        for(int i=0; i < n; i++){
            cin >> a[i]; 
            mx = max(mx, a[i]); 
        }
 
        int count = 0; 
        for(int i=0; i < n; i++){
            if(a[i]==mx){
                count++; 
            }
        } 
        
        cout << count << endl; 
    }

    return 0; 
}
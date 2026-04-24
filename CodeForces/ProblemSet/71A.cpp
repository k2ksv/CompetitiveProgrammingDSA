
#include<iostream> 
#include<string>
 
using namespace std;
int main(){
     int t;
     cin>>t;
     for(int i=0 ; i<t ; i++){
        string str;
        cin>>str;
        int len = str.length();
        if(len>10){
            cout<<str[0]<<len-2<<str[len-1]<<endl;
        }else{
            cout<<str<<endl;
        }
     }
     return 0;
}

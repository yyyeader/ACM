#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

bool prime(int n){
    if(n<2)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int n;
    while(cin>>n){
        if(n%2==0)
            cout<<2<<endl;
        else{
            if(prime(n))
                cout<<1<<endl;
            else if(prime(n-2))
                cout<<2<<endl;
            else
                cout<<3<<endl;
        }
    }
    return 0;
}

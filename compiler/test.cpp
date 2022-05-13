#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,token = 0;
    string s;
    getline(cin,s,'\n');
    bool ok = true,ok1 = false,ok2 = false;
    for(i=0;i<s.size();i++){
        if(s[i]=='a'){
            if(i<s.size()-2){
                if(s[i+1]=='b' && s[i+2]=='b'){
                    ok2 = true;
                }
            }
            if(token==1){
                ok = false;
                ok1 = false;
                break;
            }
            continue;
        }else{
            if(token==1){
                if(s[i]!='b'){
                    ok = false;
                    ok1 = false;  //a*b+  aaaaaa
                    break;
                }
                continue;
            }else{
                if(s[i]=='b'){
                    ok = false;
                    ok1 = true;
                    token = 1;
                }else{
                    ok1 = false;
                    ok = false;
                    break;
                }
            }
        }
    }
    if(ok){
        cout<<s<<" is recognized by 'a*'";
        if(ok2){
            cout<<",'abb'";
        }
    }else if(ok1){
        cout<<s<<" is recognized by 'a*b+'";
        if(ok2){
            cout<<",'abb'";
        }
    }else if(ok2){
        cout<<s<<" is recognized by 'abb'";
    }else{
        cout<<"NOT RECOGNIZED";
    }
    cout<<endl;

    return 0;// @Imtiaz_rafi
}

#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    
    long N;
    long M;
    long D;
    long m;
    long d;
    long n;
    
    
    cin >> N >> M >> D;
    
    string account;
    long num;
    long temp;
    vector <string> account_num;
    vector <string> hash;
    
    
    for (m = 0; m < M; m++){
        cin >> account;
        account_num.push_back(account);
        string hashpart;
        for (d = 0; d < D; d++){
            num = (long)(account[d]-'0');
            temp = int((num+pow(d,4)+pow(D-d,4))*pow(D,2)/pow(D-3,2));
            
            if (d < D-1){
                hashpart = hashpart + to_string(temp) + ' ';
            }
            
            if (d == D-1){
                hashpart = hashpart + to_string(temp);
            }
        }
    
        //cout<<hashpart<<endl;
        hash.push_back(hashpart);
        hashpart.clear();
        
        //cout<<account_num[m]<<endl;
    }
    
    map <string,string> hashmap;
    for (m = 0; m < M; m++){
        hashmap[hash[m]] = account_num[m];
    }
    
    vector <string> hashinputs;
    string temp2;
    for (n = 0; n < N; n++){
        string hashentry;
        for (d = 0; d < D; d++){
            cin >> temp2;
            
            if (d < D-1){
                hashentry = hashentry + temp2 + ' ';
            }
            
            if (d == D-1){
                hashentry = hashentry + temp2;
            }

        }
        hashinputs.push_back(hashentry);
        //cout<<hashentry<<endl;
        hashentry.clear();
    }
    
    for (n = 0; n < N; n++){
        cout<<hashmap[hashinputs[n]]<<endl;
        
    }

    return 0;
}















#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int main(){
    
    long N; //number of races
    long M; //determines the length of the inner most lane
    long L; //number of lanes
    long l;
    long n;
    
    //cout << "Insert N,M,L" << endl;
    cin >> N >> M >> L;
    vector <double> lanes;
    
    vector <double> speed;
    vector <long> klist;
    
    //create racetracks
    for (l = 1; l <= L; l++){
            lanes.push_back(M*(10+(l-1)));
        }
    
    //conduct each race
    for (n = 0; n < N;  n++){
        
        long B; //number of bulls in each race
        long R; //number of laps in each race
        long b;
        long r;
        
        //cout << "Insert B, R" << endl;
        cin >> B >> R;
        
        for (b = 0; b < B; b++){
        
            vector <double> data;
            
            //cout << "Insert K and R numbers" << endl;
            
            double time;
    
            for (r = 0; r <= R; r++){
                
                cin >> time;
                if (r == 0){
                    data.push_back((double)time);
                }
                
                if(r > 0){
                    
                    if(time <= 1000000000.){
                        data.push_back((double)time);
                    }
                    if(time > 1000000000.){
                        time = 1000000000.;
                        data.push_back((double)time);
                    }
                }
            }
            
            klist.push_back(data[0]);
            speed.push_back((double)(lanes[b]*(double)R)/(double)accumulate(data.begin()+1,data.end(),(double)0.0));
            //cout<<(double)(lanes[b]*R)/(double)accumulate(data.begin()+1,data.end(),0)<<endl;
            data.clear();
            
            
            
        }

    }
    
    //cout<<speed.size()<<endl;
    //cout<<speed[5]<<endl;
    double num = 0.000001;
    long winner = speed.size()-1;
    double currentts;
    long i;
    currentts = speed[speed.size()-1];
    for (i = speed.size()-2; i >= 0; i--){
        
        //cout<<currentts<<endl;
        //cout<<speed[i]<<endl;
        if (speed[i]-currentts > num){
            currentts = speed[i];
            winner = i;
        }
    }
    //cout << speed[winner]<<endl;
    cout << klist[winner] <<endl;
    return 0;
    
}




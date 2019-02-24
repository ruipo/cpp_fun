#include <iostream>
#include <string>

using namespace std;


void game(string word){
    
    bool gameover = false;
    bool gamewon = false;
    int guess_num = 6;
    string used;
    string answer = word;
    
    for (int i =0; i<word.length(); i++){
        answer[i] = '_';
    }
    
    while(!gameover && !gamewon){
        
        if (used.length() == 0){
            cout<<"\n";
            cout<<answer<<"\n";
            cout<<"\n";
            cout<<"Please enter a guess: ";
            cout<<"\n";
        }
        
        else{
            cout<<"\n";
            cout<<"Letters that you have used so far: " <<used<<"\n";
            cout<<"\n";
            cout<<answer<<"\n";
            cout<<"\n";
            cout<<"Please enter a guess: ";
            cout<<"\n";
        }
        
        char guess;
        cin>>guess;
        used = used + guess;
        system("clear");
        
        bool correct = false;
        bool duplicate = false;
        
        for (int j=0; j<word.length(); j++){
            if (guess == word[j]){
                if (answer[j] == word[j]){
                    cout<<"\n";
                    cout << guess << " has already been used. \n";
                    cout<<"Number of guesses remaining: " << guess_num<<"\n";
                    cout<<"\n";
                    duplicate = true;
                    break;
                }
                else{
                    answer[j] = word[j];
                    correct = true;
                    if (answer == word){
                        system("clear");
                        cout<<"\n";
                        cout<<"You are right! the word is: "<<answer<<"\n";
                        cout<<"Congrats! You have survived! \n"<<endl;
                        gamewon = true;
                    }
                    
                    else{
                        cout<<"Bingo! "<<guess<<" is in the word! \n";
                        cout<<"\n";
                        cout<<"Number of guesses remaining: " << guess_num<<"\n";
                        continue;
                    }
                }
            }
        }
        
        if(duplicate){
            continue;
        }
        
        if (!correct){
            guess_num = guess_num-1;
            
            if (guess_num == 0){
                gameover = true;
                cout<<"\n";
                cout<<guess<<" is not in the word.\n";
                cout<<"\n";
                cout<<"You have run out of guesses...";
                cout<<"\n";
                cout << "You have FAILED! =( "<<endl;
                cout<<"\n";
                cout<<"The word is: " << word<<"\n";
                cout<<"\n";
            }
            
            else{
                cout<<"\n";
                cout<<guess<<" is not in the word.\n";
                cout<<"\n";
                cout<<"Number of guesses remaining: " << guess_num<<"\n";
                
            }
        }

    }
    
}

int main(){
    
    string word;
    cout<<"Please enter a word to guess."<<endl;
    cin>>word;
    system("clear");
    cout<<"You have 6 guesses until you are HANGED!"<<endl;
    game(word);
    
    return 0;
    
}

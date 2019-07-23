#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<ctype.h>
#include <ctime>

using namespace std;


struct Player{
    
    string name  = " ";
    double numPoints = 0;
    int hintcount = 0;
    
};


class Game{
    
private:
    
    int countwrong = 0;
    int wordcount = 0;
    int nopoints = 0;
    double halfpts = 0;
    double total = 0;
    double numRight = 0;
    double totalhalfpoints = 0;
    
    vector <double> halfptsvector;
    vector <string> wordstoreview;
    
public:
    string englishWord;
    string germanWord;
    string translation;
    
    
    
    void expressions(){
        int expression = rand() % 10;
        
        /*
         generate last digit of a random number
         to display expressions
         */
        
        switch (expression){
                
            case 0:
                cout << "SEHR GUT!!" << endl << endl;
                break;
                
            case 1:
                cout << "JAWOHL!" << endl << endl;
                break;
                
            case 2:
                cout << "SUPER!!"<< endl << endl;
                break;
                
            case 3:
                cout << "WEITER SO!"<< endl << endl;
                break;
                
            case 4:
                cout << "DU BIST EIN SUPERSTAR!"<< endl << endl;
                break;
                
            default:
                cout <<"RICHTIG!"<< endl << endl;
        }
        
    }
    
    
    void giveHint(string translation){
        
        // display half the word or phrase as a hint
        cout << translation.substr(0, translation.length()/2) << "..." << endl;
        
    }
    
    void setup(string filename){
        
        ifstream ifs;
        ifs.open(filename);
       
        
        //if file exists
        if (ifs){
        string playerName;
            
        
        // What's your name?
        cout<<"Wie heißt du? "<<endl;
        getline(cin, playerName);
            
        
        //create Player objects
        Player player1;
        Player computer;
            
        
        player1.name = playerName;
        computer.name = "Angela Merkel";
            
        
        //Let's get started
        cout << "Dann legen wir mal los!" << endl << endl;
            
        startGame( player1, computer, filename);
            
        }
        
        
        else{
            cout << " File does not exist :( " << endl;
        }
        
    }
    
    void startGame(Player player1, Player computer, string filename){
        

        ifstream ifs;
        ifs.open(filename);
        

        while(getline(ifs, englishWord)){
            
            //display English word
            cout << englishWord << " ----- "<<endl<<endl;
            wordcount++;
            
            // calculate computer's score
            if (rand() % 2 == 0){
                computer.numPoints++;
                cout << "Angela Merkel got it right! Your turn" << endl<<endl;
            }
            
            else{
                cout<< "Oh no! The chancellor got it wrong! Your turn" << endl<<endl;
            }
            
            // read in German word from file
            getline(ifs, germanWord);
     
            cout << "Your answer: ";
            //read in user input
            getline(cin, translation);

            if (translation == germanWord) {
                
                //increase score
                numRight++;
                
                //call expression function to display expressions of encouragement
                expressions();
  
            }
            
            //add words to "wordstoreview" vector if user passes
            
            else if(translation == "Pass" || translation == "pass"){
                wordstoreview.push_back(englishWord);
                wordstoreview.push_back(germanWord);
                nopoints++;
            }

            else {
  
                while (translation != germanWord) {
                    
                    //check if user input is valid
                    for(char c : translation) {
                        
                        if (!isalpha(c) && !isspace(c)){
                            
                            cout<< c << " is not a letter "<<endl;
                            
                            break;
                            
                        }
                    }
                    
                    //handle hint requests
                    if (translation == "hint" || translation == "Hint" ){
                        
                        if (player1.hintcount < 1){
                            
                            giveHint(germanWord);
                            
                            player1.hintcount++;
                            
                            cout << englishWord << endl;
                            
                            getline(cin, translation);
                            
                            if (translation == germanWord){
                                
                                player1.numPoints++;
                                expressions();
                            }

                            continue;
                        }
                        
                        else{
                            
                            cout << "ONE hint per game. Moving on..." <<endl;
                            wordstoreview.push_back(englishWord);
                            wordstoreview.push_back(germanWord);
                            break;
                            
                        }
                    }
                    

                    cout << "Try again" << endl;
                    
                    countwrong++;

                    cout << englishWord << endl;
                    
                    getline(cin, translation);
                    
                    //if player gets word wrong three times, add to "wordstoreview" vector and move on
                    if (countwrong == 2) {
                        wordstoreview.push_back(englishWord);
                        wordstoreview.push_back(germanWord);
                        break;
                    }
                }
                
                //calculate partial credit
                halfpts = pow(.5, countwrong);
                halfptsvector.push_back(halfpts);
                countwrong = 0;
                
            }
        }
        
        //display results
        ifs.close();
        printResults(player1, computer);
    }
  
    
    
    
    void printResults(Player player1, Player computer){
        
        for (int i = 0; i < halfptsvector.size(); i++) {
            
            totalhalfpoints = totalhalfpoints + halfptsvector[i];
        }
        
        //calculate user's score
        player1.numPoints = (numRight + totalhalfpoints) - nopoints;
        
        //display user's score and Angela Merkel's score
        cout << player1.name << "'s score is " << player1.numPoints <<" / "<< wordcount << endl << endl;
        
        cout << computer.name << "'s score is " << computer.numPoints <<" / "<< wordcount << endl << endl;
        
        (computer.numPoints > player1.numPoints) ? cout << "YOU LOSE!" : cout << "YOU WIN!";
        
        cout <<endl<<endl;
        
        //display words to review, if any
        if (!wordstoreview.empty()){
            
        cout << "WORK ON ---- " << endl<<endl;
        
        }
        for (int i = 0; i < wordstoreview.size(); i=i+2) {
            cout << wordstoreview[i] << " - ";
            
            for (int j = i + 1; j <= i+1 ; j++) {
                cout<<wordstoreview[j] << endl;
            }
           
        }
  
    }
   
};




int main() {
    
    srand((int)time(0));
    
    string filename = " ";
    

    //prompt the user for the name of the file
    //Ex: germanvocab1.txt
    cout << "Insert filename" <<endl;
    getline(cin, filename);
    

    //create Game class object and start game
    Game g;
    
    g.setup(filename);
    

    return 0;
}



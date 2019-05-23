#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>


using namespace std;


int main() {
    
    //#ifdef __APPLE__
    //    freopen("/Users/shadae/Desktop/GERMAN/LangaugeLearning/LangaugeLearning/vocab1.txt", "r", stdin);
    //    // freopen("/Users/shadae/Desktop/EECS281P2/EECS281P2/example.txt", "w", stdout);
    //#endif
    
    
    
    int  wordcount, countwrong, nopoints;
    double halfpts, total, numRight, totalhalfpoints;
    vector < double>halfptsvector;
    vector <string>wordstoreview;
    string vocabword, vocabword2, translation;
    
    ifstream ifs;
    ifs.open("vocab1.txt");
    
    
    countwrong = 0;
    wordcount=0;
    nopoints = 0;
    halfpts = 0;
    total = 0;
    numRight = 0;
    totalhalfpoints = 0;
    
    // while (ifs.good()) {
    while( getline(ifs, vocabword)){
        //  while (cin>>vocabword){
        
        //  getline(ifs, vocabword);
        cout << vocabword << endl;
        wordcount++;
        
        
//        cin>>translation;
        getline(cin, translation);
        //                cin>>vocabword2;
        //        getline(cin, translation);
        getline(ifs, vocabword2);
        
        
        
        if (translation==vocabword2) {
            cout << "Yay!!!" << endl;
            numRight++;
            
        }
        else if(translation=="Pass" || translation=="pass"){
            wordstoreview.push_back(vocabword);
            wordstoreview.push_back(vocabword2);
            nopoints++;
        }
        
        else {
            
            while (translation != vocabword2) {
                
                
                
                cout << "Try again" << endl;
                
                countwrong++;
                
                
                cout << vocabword << endl;
                
                
                getline(cin, translation);
                if (countwrong == 2) {
                    wordstoreview.push_back(vocabword);
                    wordstoreview.push_back(vocabword2);
                    break;
                }
                
                
            }
            halfpts = pow(.5, countwrong);
            halfptsvector.push_back(halfpts);
            countwrong = 0;
            
        }
    }
    for (int i = 0; i < halfptsvector.size(); i++) {
        
        totalhalfpoints=totalhalfpoints+ halfptsvector[i];
    }
    // ifs.close();
    total = (numRight + totalhalfpoints)-nopoints;
    cout << "Score is " << total<<" / "<<wordcount<<endl<<endl;
    
    cout << "WORK ON: " << endl<<endl;
    
    
    for (int i = 0; i < wordstoreview.size(); i=i+2) {
        cout << wordstoreview[i] << " - ";
        for (int j = i + 1; j <= i+1 ; j++) {
            cout<<wordstoreview[j] << endl;
        }
        
        
    }
    
    return 0;
}


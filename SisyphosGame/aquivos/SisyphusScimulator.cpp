#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<thread>
#include<chrono>
#include<fstream> 
#include<cstring> 
using namespace std;

int main(){
    bool L = true;
    string ANS, CON;
    string nome;  
    int metros = 0;
    int recorde = 0;

    srand(time(0));

    cout << "Long ago, a man was cursed by the gods..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Condemned to push a boulder up a mountain..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Every time he reached the top..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "The boulder rolled back down." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "\nAnd now... it's YOUR turn.\n" << endl;
    this_thread::sleep_for(chrono::seconds(2));

    cout<<"Welcome to Sisyphos Simulator \nif you want play, type Y if not N"<<endl;
    cin>>ANS;

    if(ANS == "Y" || ANS == "y"){
        while(L){
            cout<<"You're in "<<metros<<" of height"<<endl;
            cout<<"Do you want continue?(y, n) ";
            cin>>CON;
            if(CON == "y" || CON == "Y"){
                int num = rand() % 101;
                if(num <= metros){
                    cout<<"Oh no! You fell back to 0...\n";
                    metros=0;
                }
                else{
                    metros++;
                    if(metros > recorde){
                        recorde = metros;
                    }
                }
            }
            else{
                cout<<"Good Bye! Your highest record was "<<recorde<<endl;

                
                cout << "Enter your name to save your record: ";
                cin >> nome;

                
                char* userProfile = getenv("USERPROFILE");
                string path;
                if(userProfile != nullptr){
                    path = string(userProfile) + "\\Desktop\\SisyphosRecords.txt";
                } else {
                   
                    path = "SisyphosRecords.txt";
                }

                ofstream arquivo(path, ios::app);
                if(arquivo.is_open()){
                    arquivo << "Player: " << nome << " | Record: " << recorde << " meters\n";
                    arquivo.close();
                    cout << "Record saved on your Desktop (SisyphosRecords.txt)\n";
                } else {
                    cout << "Error: Could not save the record.\n";
                }
               

                break;
            }
        }
    }
    else{
        cout<<"Good Bye!"<<endl;
    }
    return 0;
}
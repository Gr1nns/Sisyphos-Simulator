#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    bool L = true;
    string ANS, CON;
    int metros = 0;
    int recorde = 0; 

    srand(time(0));
    cout << "Hello, welcome to Sisyphos Simulator \n if you want play, type Y if not N" << endl;
    cin >> ANS;

    if(ANS == "Y" || ANS == "y"){ 
        while(L){
            cout << "You're in " << metros << " of height" << endl;
            cout << "Do you want continue?(y, n) ";
            cin >> CON;

            if(CON == "y" || CON == "Y"){ 
                int num = rand() % 101;
                if(num <= metros){
                    cout << "Oh no! You fell back to 0...\n"; 
                    metros = 0;
                }
                else{
                    metros++;
                    if(metros > recorde){  
                        recorde = metros;
                    }
                }
            }
            else{
                cout << "Good Bye! Your highest record was " << recorde << endl;
                break;
            }
        }
    }
    else{
        cout << "Good Bye!" << endl;
    }
    return 0;
}

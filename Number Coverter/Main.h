#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
bool isBinary(string input);
bool isOctal(string input);
string ConverterBase_10_2(string Input,bool Rev=false);
string ConverterBase_10_8(string Input,bool Rev=false);
string ConverterBase_10_16(string Input);
void NumberConverterMenu(History *HistoryList){
    while(true){
    string Path="MAIN MENU/NUMBER CONVERSION/";
    system("cls");
    SubHeader("NUMBER CONVERSION",4,32,5);
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        printf("\n");
        printf("\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n",
               "1.BASE 2 TO 10",
               "2.BASE 10 TO 2",
               "3.BASE 8 TO 10",
               "4.BASE 10 TO 8",
               "5.BASE 10 TO 16",
               "6.BACK TO MAIN MENU");
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        int choice;
            string n;
            cout<<"\n\t\tInput you option: ";cin>>choice;
            if(choice==1){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CONVERT BASE 2 TO 10";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){
                    system("cls");
                    SubHeader("CONVERT BASE 2 TO 10",3,36,4);

                    cout<<"\t\tInput your Number: ";cin>>n;
                    while(!isBinary(n)){
                        cout<<"\t\tInput Invalid!!";
                        cout<<"\n\t\tTry again:";cin>>n;
                    }
                    cout<<"\t\tNumber in Base 10 that represent to "<<n<<" is "<<ConverterBase_10_2(n,true)<<endl;

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }

                }
            }else if(choice==2){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CONVERT BASE 10 TO 2";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){
                    system("cls");
                    SubHeader("CONVERT BASE 10 TO 2",3,36,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    cout<<"\t\tNumber in Base 2 that represent to "<<n<<" is "<<ConverterBase_10_2(n)<<endl;

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }

                }
            }else if(choice==3){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CONVERT BASE 8 TO 10";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("CONVERT BASE 8 TO 10",3,36,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    while(!isOctal(n)){
                        cout<<"\t\tInput Invalid!!";
                        cout<<"\n\t\tTry again:";cin>>n;
                    }
                    cout<<"\t\tNumber in Base 10 that represent to "<<n<<" is "<<ConverterBase_10_8(n,true)<<endl;
                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }

            }else if(choice==4){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CONVERT BASE 10 TO 8";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("CONVERT BASE 10 TO 8",3,36,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    cout<<"\t\tNumber in Base 8 that represent to "<<n<<" is "<<ConverterBase_10_8(n)<<endl;
                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }

            }else if(choice==5){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CONVERT BASE 10 TO 16";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("CONVERT BASE 10 TO 16",3,36,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    cout<<"\t\tNumber in Base 16 that represent to "<<n<<" is "<<ConverterBase_10_16(n)<<endl;
                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }
            }else break;
    }
}

bool isBinary(string input){
    for(int i=0;i<input.size();i++){
        if(input[i]!='0' &&input[i]!='1'){
            return false;
        }
    }
    return true;
}

string ConverterBase_10_2(string Input,bool Rev){
    string OutPut="";
    int Number=stoi(Input),sum=0;
    if(Rev){
        for(int i=0;Number!=0;i++){
            sum+=(Number%10)*pow(2,i);
            Number=Number/10;
        }
        OutPut=to_string(sum);
    }else{
        while(Number!=0){
            OutPut+=to_string(Number%2);
            Number=Number/2;
        }
        reverse(OutPut.begin(),OutPut.end());
    }
    return OutPut;
}

bool isOctal(string input){
    for(int i=0;i<input.size();i++){
        if(input[i]>55 ||input[i]<48){
            return false;
        }
    }
    return true;
}

string ConverterBase_10_8(string Input,bool Rev){
    string OutPut="";
    int Number=stoi(Input),sum=0;
    if(Rev){
        for(int i=0;Number!=0;i++){
            sum+=(Number%10)*pow(8,i);
            Number=Number/10;
        }
        OutPut=to_string(sum);
    }else{
        while(Number!=0){
            OutPut+=to_string(Number%8);
            Number=Number/8;
        }
        reverse(OutPut.begin(),OutPut.end());
    }
    return OutPut;
}

bool isHexa(string input){
    for(int i=0;i<input.size();i++){
        if(input[i]<47 ||(input[i]>57 && input[i]<97) || input[i]>70 ){
            return false;
        }
    }
    return true;
}


string ConverterBase_10_16(string Input){
    string OutPut="";
    int Number=stoi(Input),sum=0;
        int remainder;
        while(Number!=0){
            remainder=(Number%16);
            if(remainder>=10){
                OutPut+=remainder+55;
            }else{
                OutPut+=to_string(remainder);
            }
            Number=Number/16;
        }
        reverse(OutPut.begin(),OutPut.end());

    return OutPut;
}





#include <iostream>
#include<conio.h>
#include "DataStructure.h"
using namespace std;
void SubHeader(string Text,int tap=0,int width=0,int textTap=0,char ch='='){
    cout<<"\n";
    for(int i=0;i<tap;i++){
        cout<<"\t";
    }
    for(int i=0;i<width;i++){
        cout<<ch;
    }
    cout<<"\n";
    for(int i=0;i<textTap;i++){
        cout<<"\t";
    }
    cout<<(Text);


    cout<<"\n";
    for(int i=0;i<tap;i++){
        cout<<"\t";
    }
    for(int i=0;i<width;i++){
        cout<<ch;
    }
    cout<<"\n";

}
string toUpperCase(string text){
    int i=0;
    while(text[i]!='\0'){
        if(text[i]>=97 && text[i]<=122){
            text[i]=text[i]-32;
        }
        i++;
    }
    return text;
}
void HistoryMenu(History *HistoryList){
    while(true){
        system("cls");
        SubHeader("HISTORY",4,25,5);
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        printf("\n");
        printf("\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n",
               "1.SEE ALL HISTORY",
               "2.SEARCH",
               "3.CLEAR HISTORY",
               "4.BACK TO MAIN MENU");
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        int choice;
        cout<<"\n\t\tInput your choice:";cin>>choice;
        if(choice==1){
            system("cls");
            SubHeader("ALL HISTORY("+to_string(HistoryList->Size())+")",4,25,5);
            HistoryList->Display();
            system("pause");
        }else if(choice==2){
            int i=0;
            while(true){
                system("cls");
                SubHeader("SEARCH HISTORY",4,30,5);
                HistoryList->Display();
                string Keyword;
                if(i==0){
                    cin.ignore();
                    i++;
                }
                cout<<"\n\t\tInput KeyWord: ";getline(cin,Keyword);
                system("cls");
                SubHeader("SEARCH HISTORY("+to_string(HistoryList->Search_Quantity(Keyword))+")",4,35,5);
                cout<<"\n\t\tSearch"<<"\""<<Keyword<<"\""<<endl;
                HistoryList->Search(Keyword);
                cout<<"\nPress any key to Continue |Esc to Back to Menu...";
                if(_getch()==27){
                    break;
                }
            }
        }else if(choice==3){
            system("cls");
            SubHeader("CLEAR HISTORY",4,30,5);
            HistoryList->Display();
            string ch;
            cout<<"\t\tAre you sure?Y/N:";cin>>ch;
            if(ch[0]=='Y' || ch[0]=='y' || toUpperCase(ch)=="YES"){
                HistoryList->Clear();
                HistoryList->SaveTo("History/Save/file.txt");
                SubHeader("CLEAR SUCCESSFUL",4,30,5);
            }else{
                SubHeader("CLEAR FAILED",4,30,5);

            }
            system("pause");
        }else break;

    }

}

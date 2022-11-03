#include <iostream>
#include "DataStructure.h"
using namespace std;

void NumberTestingMenu(History *HistoryList){
    Number num;
    while(true){
    string Path="MAIN MENU/NUMBER TESTING/";
    system("cls");
    SubHeader("NUMBER TESTING",4,40,5);
            printf("\t\t");
            for(int i=0;i<70;i++){
                printf("=");
            }
            printf("\n");
            printf("\t\t||\t%-60s||\n"
                   "\t\t||\t%-60s||\n"
                   "\t\t||\t%-60s||\n"
                   "\t\t||\t%-60s||\n"
                   "\t\t||\t%-60s||\n",
                   "1.Check if it is a primary number",
                   "2.Check if it is a perfect number",
                   "3.Check if it is a palindrome number",
                   "4.All AT ONCE",
                   "5.BACK TO MAIN MENU");
            printf("\t\t");
            for(int i=0;i<70;i++){
                printf("=");
            }
            int choice;
            int n;
            cout<<"\n\t\tInput you option: ";cin>>choice;
            if(choice==1){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CHECK PRIME NUMBE";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){
                    system("cls");
                    SubHeader("CHECK PRIME NUMBER",3,35,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    if(num.isPrime()){
                        cout<<"\t\t"<<num.getValue()<<" is prime number!!\n";
                    }else{
                        cout<<"\t\t"<<num.getValue()<<" isn't prime number!!\n";
                    }

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){
                        break;
                    }

                }
            }else if(choice==2){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CHECK PERFECT NUMBE";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){
                    system("cls");
                    SubHeader("CHECK PERFECT NUMBER",3,35,4);;
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    if(num.isPerfect()){
                        cout<<"\t\t"<<num.getValue()<<" is perfect number!!\n";
                    }else{
                        cout<<"\t\t"<<num.getValue()<<" isn't perfect number!!\n";
                    }

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }

                }
            }else if(choice==3){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CHECK PALINDROME NUMBE";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("CHECK PALINDROME NUMBER",3,38,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    if(num.isPalindrome()){
                        cout<<"\t\t"<<num.getValue()<<" is palindrome number!!\n";
                    }else{
                        cout<<"\t\t"<<num.getValue()<<" isn't palindrome number!!\n";
                    }

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }

            }else if(choice==4){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="CHECK ALL AT ONCE";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("CHECK ALL AT ONCE",3,35,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    if(num.isPrime()){
                        cout<<"\t\t"<<num.getValue()<<" is prime number!!\n";
                    }else{
                        cout<<"\t\t"<<num.getValue()<<" isn't prime number!!\n";
                    }
                    if(num.isPerfect()){
                        cout<<"\t\t"<<num.getValue()<<" is perfect number!!\n";
                    }else{
                        cout<<"\t\t"<<num.getValue()<<" isn't perfect number!!\n";
                    }
                    if(num.isPalindrome()){
                        cout<<"\t\t"<<num.getValue()<<" is palindrome number!!\n";
                    }else{
                        cout<<"\t\t"<<num.getValue()<<" isn't palindrome number!!\n";
                    }

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }

            }else{
                break;
            }
       }

}

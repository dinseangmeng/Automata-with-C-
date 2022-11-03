
#include<iostream>
#include "DataStructure.h"
using namespace std;

void MathSuitMenu(History *HistoryList){
    MathSuit num;
    while(true){
    string Path="MAIN MENU/MATH SUIT/";
    system("cls");
    SubHeader("MATH SUIT CALCULATOR",4,35,5);
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
               "1.Sum all Number from 1 to n",
               "2.Sum all odd Number from 1 to n",
               "3.Sum all Number with power 2 from 1 to n",
               "4.Sum all Prime Number from 1 to n",
               "5.ALL AT ONCE",
               "6.BACK TO MAIN MENU");
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
                Path+="Sum all Number from 1 to n";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){
                    system("cls");
                    SubHeader("CALCULATE SUM OF NUMBER FROM 1 to N",3,70,5);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    cout<<"\t\t"<<num.Sum_disp()<<" = "<<num.Sum()<<endl;

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }

                }
            }else if(choice==2){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="Sum all odd Number from 1 to n";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){
                    system("cls");
                    SubHeader("CALCULATE SUM OF ODD NUMBER FROM 1 to N",3,70,5);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    cout<<"\t\t"<<num.SumOdd_disp()<<" = "<<num.SumOdd()<<endl;

                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }

                }
            }else if(choice==3){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="Sum all Number with power 2 from 1 to n";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("SUM ALL NUMBER WITH POWER 2 FROM 1 TO N",3,70,5);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    cout<<"\t\t"<<num.SumPower_disp()<<" = "<<num.SumPower()<<endl;
                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }

            }else if(choice==4){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="Sum all Prime Number from 1 to n";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("SUM ALL PRIME NUMBER FROM 1 TO N",3,70,5);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    cout<<"\t\t"<<num.SumPrime_disp()<<" = "<<num.SumPrime()<<endl;
                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }

            }else if(choice==5){
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="ALL AT ONCE";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");
                while(true){

                    system("cls");
                    SubHeader("ALL AT ONCE",3,28,4);
                    cout<<"\t\tInput your Number: ";cin>>n;
                    num.setValue(n);
                    cout<<"\t\t"<<num.Sum_disp()<<" = "<<num.Sum()<<endl;
                    cout<<"\t\t"<<num.SumOdd_disp()<<" = "<<num.SumOdd()<<endl;
                    cout<<"\t\t"<<num.SumPower_disp()<<" = "<<num.SumPower()<<endl;
                    cout<<"\t\t"<<num.SumPrime_disp()<<" = "<<num.SumPrime()<<endl;
                    cout<<"Press any key to continue|Esc back to Menu:";

                    if(_getch()==27){

                        break;
                    }
                }
            }else break;
        }

}


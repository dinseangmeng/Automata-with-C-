#include <iostream>
#include <ctime>
#include "History/Main.h"
#include "Product Management/Main.h"
#include "Book Management/Main.h"
#include "Number Testing/Main.h"
#include "Math suit/Main.h"
#include "Number Coverter/Main.h"
#include "Basic Math/Main.h"
using namespace std;

History HistoryList;


bool MainMenu(){
        system("cls");
        string Path="MAIN MENU";
        time_t result = time(nullptr);
        string time= asctime(localtime(&result));
        Path+="";
        HistoryList.Insert(time,Path);
        HistoryList.SaveTo("History/Save/file.txt");
        SubHeader("MAIN MENU",4,25,5);
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
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n"
               "\t\t||\t%-60s||\n",
               "1.Product Management",
               "2.Book Management",
               "3.Number Testing",
               "4.Basic Math",
               "5.Math Suit Computation",
               "6.Numbering Conversion",
               "7.See History",
               "8.Stop Program");
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        int choice;
        cout<<"\n\t\tInput your option: ";cin>>choice;
        if(choice==1){
            ProductMenu(&HistoryList);
        }else if(choice==2){
            BookMenu(&HistoryList);
        }else if(choice==3){
            NumberTestingMenu(&HistoryList);
        }else if(choice==4){
            BasicMathMenu(&HistoryList);
        }else if(choice==5){
            MathSuitMenu(&HistoryList);
        }else if(choice==6){
            NumberConverterMenu(&HistoryList);
        }else if(choice==7){
            HistoryMenu(&HistoryList);
        }else{
            return false;
        }
    return true;
}

int main()
{
    HistoryList.LoadFrom("History/Save/file.txt");
    while(MainMenu()){};


}

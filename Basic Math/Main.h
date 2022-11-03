
#include <iostream>
#include <tabulate/table.hpp>
using namespace tabulate;
using namespace std;
using Row_t = Table::Row_t;

bool isInt(string text){

    if(text.size()==1){
        for(int i=0;i<text.size();i++){
            if(text[i]>57 || text[i]<46 || text[i]==47 ){
                return false;
            }
        }

    }else{
        for(int i=0;i<text.size();i++){
            if(text[i]>57 || text[i]<40 ||
               text[i]==47 || text[i]==44||
               text[i]==42){
                return false;
            }
        }
    }
    return true;


}
void Calculator(){
string opt=" ",input="",value=" ";
   float num1,num2;
   int x=0;
   while(true){

        Table table,Main,MAIN;
        system("cls");
        if(input==""){
            Main.add_row(Row_t({"NO VALUE"}));
        }else{
            Main.add_row(Row_t({input}));
        }
        table.add_row({"","","^","Clr"});
        table.add_row({"7","8","9","+"});
        table.add_row({"6","5","4","-"});
        table.add_row({"3","2","1","*"});
        table.add_row({".","0","=","/"});
        table.format().font_align(FontAlign::center);
        Main.add_row({table});
        Main.format().font_align(FontAlign::center);
        MAIN.add_row({Main});
        MAIN.format().font_align(FontAlign::center);
        MAIN.format().width(90);
        MAIN.format().hide_border();
        SubHeader("CALCULATOR MODE",4,30,5);
        cout<<MAIN;
        int i;
        cout<<"\t\t\t\tType EXIT TO CLOSE!!";
        if(isInt(value)){
            cout<<"\n\t\t\tInput Opt:";
            i=0;
            if(num2){
                if(opt=="+"){
                    num1=num1+num2;
                }else if(opt=="-"){
                    num1=num1-num2;
                }else if(opt=="*"){
                    num1=num1*num2;
                }else if(opt=="/"){
                    num1=num1/num2;
                }else if(opt=="^"){
                    num1=pow(num1,num2);
                }
                i=1;
                value=to_string(num1);
                input=value;
                num2=NULL;
            }
            cin>>opt;

            if(opt[0]=='E'||opt[0]=='e' || toUpperCase(opt)=="EXIT"){
                break;
            };
            if(toUpperCase(opt)=="CLR" ||toUpperCase(opt)=="CLEAR"||
               opt[0]=='c'||opt[0]=='C'){
                value=" ";input="";
                num1=NULL;num2=NULL;opt=" ";
                continue;
            }
            while(opt!="+" &&opt!="-" &&opt!="*" &&opt!="/" &&opt!="="&&opt!="^"){
                cout<<"\n\t\t\tInput Invalid!!";
                cout<<"\n\t\t\tTry Again:";cin>>opt;
            }
            if(opt!="="){
                value=opt;
            }else{
                value="";
            }
        }else{
            cout<<"\n\t\t\tInput Number:";cin>>value;
            if(value[0]=='E'||value[0]=='e' || toUpperCase(value)=="EXIT"){
                break;
            }
            if(toUpperCase(value)=="CLR" ||toUpperCase(value)=="CLEAR" ||
               value[0]=='c'||value[0]=='C'){
                value=" ";input="";
                num1=NULL;num2=NULL;opt=" ";
                continue;
            }
            while(!isInt(value)){
                cout<<"\t\t\tInput Invalid:";
                cout<<"\n\t\t\tTry Again: ";cin>>value;
            }
            if(opt==" "){
                num1=stof(value);
            }else{
                num2=stof(value);

            }
            if(value[0]=='-'){
                value="("+value+")";
            }

        }
        input+=value;
        x++;

   }
}

void BasicMathMenu(History *HistoryList){

    while(true){
        string Path="MAIN MENU/BASIC MATH/";
        system("cls");
        SubHeader("BASIC MATH",4,25,5);
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
               "1.SUMMATION",
               "2.SUBSTRUCTION",
               "3.MULTIPLICATION",
               "4.DIVISION",
               "5.CALCULATOR MODE",
               "6.BACK TO MAIN MENU");
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        int choice;
        float num1,num2;

        cout<<"\n\t\tInput option: ";cin>>choice;
        if(choice==1){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="SUMMATION";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            while(true){
                system("cls");
                SubHeader("SUMMATION",4,25,5);
                cout<<"\n\t\tInput number 1:";cin>>num1;
                cout<<"\t\tInput number 2:";cin>>num2;
                cout<<"\t\t"<<num1<<"+"<<num2<<"="<<num1+num2;
                cout<<"\nPress any key to continue|Esc back to Menu:";

                if(_getch()==27){

                    break;
                }
            }
        }else if(choice==2){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));

            Path+="SUBSTRACTION";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            while(true){
                system("cls");
                SubHeader("SUBSTRACTION",4,28,5);
                cout<<"\n\t\tInput number 1:";cin>>num1;
                cout<<"\t\tInput number 2:";cin>>num2;
                cout<<"\t\t"<<num1<<"-"<<num2<<"="<<num1-num2;
                cout<<"\nPress any key to continue|Esc back to Menu:";

                if(_getch()==27){
                    break;
                }
            }
        }else if(choice==3){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="MULTIPLICATION";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            while(true){
                system("cls");
                SubHeader("MULTIPLICATION",4,30,5);
                cout<<"\n\t\tInput number 1:";cin>>num1;
                cout<<"\t\tInput number 2:";cin>>num2;
                cout<<"\t\t"<<num1<<"*"<<num2<<"="<<num1*num2;
                cout<<"\nPress any key to continue|Esc back to Menu:";

                if(_getch()==27){
                    break;
                }
            }
        }else if(choice==4){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="DIVISION";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            while(true){
                system("cls");
                SubHeader("DIVISION",4,24,5);
                cout<<"\n\t\tInput number 1:";cin>>num1;
                cout<<"\t\tInput number 2:";cin>>num2;
                cout<<"\t\t"<<num1<<"/"<<num2<<"="<<num1/num2;
                cout<<"\nPress any key to continue|Esc back to Menu:";

                if(_getch()==27){
                    break;
                }
            }
        }else if(choice==5){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="CALCULATOR MODE";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            Calculator();
        }else{
            break;
        }

    }


}


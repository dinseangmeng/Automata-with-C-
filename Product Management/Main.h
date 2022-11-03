#include <iostream>
#include <conio.h>

#include "DataStructure.h"
using namespace std;
Product PList;

string Path_p="Product Management/Save/File.txt";

bool isValid(date Date){
    if(Date.year>0){
        if(Date.month>0 && Date.month <=12){
            if((Date.month==1 || Date.month==3 ||Date.month==5||
                Date.month==7 ||Date.month==8||Date.month==10||Date.month==12) && (Date.day>0 && Date.day<=31)){
                return true;
            }
            else if((Date.month==4|| Date.month==6||Date.month==9 ||Date.month==11)&& (Date.day>0 && Date.day<=30)){
                return true;
            }else if(Date.month==2 &&(Date.day>0&& Date.day<=28)){
                return true;
            }else {
                return false;
            }
        }else {
            return false;
        };
    }else {
        return false;
    };

}



void UpdateMenu();
void ProductMenu(History *HistoryList){
    PList.LoadFrom(Path_p);
    string id;
    while(true){
    string Path="MAIN MENU/PRODUCT MANAMENT/";
    system("cls");
    SubHeader("PRODUCT MANAGEMENT",4,35,5);
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
               "\t\t||\t%-60s||\n",
               "1.Input Product",
               "2.Display All Product",
               "3.Display Product By ID",
               "4.Update Product",
               "5.Delete Product",
               "6.Search Product",
               "7.BACK TO MAIN MENU");
        printf("\t\t");
        for(int i=0;i<70;i++){
            printf("=");
        }
        int choice;
        cout<<"\n\t\tInput Option: ";
        cin>>choice;
        if(choice==1){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="INPUT PRODUCT";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            Path="MAIN MENU/PRODUCT MANAMENT/";
            string id,name;
            float price;
            date importDate,expireDate;
            int quantity;
            while(true){
                Path="MENU/";
                system("cls");
                SubHeader("INPUT PRODUCT",3,30,4);
                cout<<"\t\tInput New ID: ";cin>>id;
                while(PList.isExist(id)){
                    cout<<"\t\tID Invalid!!\n";
                    cout<<"\t\tTry Again: ";cin>>id;
                }
                cin.ignore();
                cout<<"\t\tInput New NAME: ";getline(cin,name);
                cout<<"\t\tInput New PRICE: ";cin>>price;
                cout<<"\t\tInput New Import Date: ";scanf("%d\\%d\\%d",&importDate.day
                                                         ,&importDate.month,&importDate.year);
                while(!isValid(importDate)){
                    cout<<"\t\tInput invalid\n";
                    cout<<"\t\tTry again:";scanf("%d\\%d\\%d",&importDate.day
                                                         ,&importDate.month,&importDate.year);
                }
                cout<<"\t\tInput New Expire Date: ";scanf("%d\\%d\\%d",&expireDate.day
                                                         ,&expireDate.month,&expireDate.year);
                while(!isValid(expireDate)){
                    cout<<"\t\tInput invalid\n";
                    cout<<"\t\tInput New Expire Date: ";scanf("%d\\%d\\%d",&expireDate.day
                                                         ,&expireDate.month,&expireDate.year);
                }
                cout<<"\t\tInput Quantity: ";cin>>quantity;
                PList.Insert(id,name,price,importDate,expireDate,quantity);
                cout<<"Press any key to continue|Esc back to Menu:";
                PList.SaveTO(Path_p);
                if(_getch()==27){
                    break;
                }
            }

        }else if(choice==2){
            system("cls");
            SubHeader("DISPLAY PRODUCT("+to_string(PList.Size())+")",6,30,7);
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="DISPLAY PRODUCT";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            PList.display();
            system("pause");

        }else if(choice==3){
            system("cls");
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="DISPLAY PRODUCT BY ID";
            SubHeader("DISPLAY PRODUCT BY ID",5,37,6);
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            if(!PList.isEmpty()){
                cout<<"\t\tInput ID: ";cin>>id;
                PList.displayByID(id);
            }else{
                system("cls");
                SubHeader("DISPLAY PRODUCT BY ID("+to_string(PList.Search_Quantity(id))+")",5,37,6);
                PList.display();
            }
            system("pause");


        }else if(choice==4)
        {
            system("cls");

            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="UPDATE PRODUCT";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            SubHeader("UPDATE PRODUCT BY ID",5,37,6);
            PList.display();
            if(!PList.isEmpty()){
                cout<<"\n\t\tInput ID: ";cin>>id;

                while(!PList.isExist(id)){
                    cout<<("\t\tThere no data match!!\n");
                    cout<<"\t\tTry again:";cin>>id;
                }


                while(true){
                    system("cls");
                    SubHeader("UPDATE PRODUCT BY ID",4,37,5);
                    UpdateMenu();
                    cout<<"\n\t\tInput you Option: ";cin>>choice;
                    while(choice<1 || choice>8){
                        cout<<("\t\tInput Invalid!!\n");
                        cout<<"\t\tTry again: ";cin>>choice;
                    }
                    if(choice==8){
                        break;
                    }
                    PList.updateByID(&id,choice);
                    PList.displayByID(id);
                    cout<<"Press any key to continue|Esc back to Menu:";
                    PList.SaveTO(Path_p);
                    if(_getch()==27){

                        break;
                    }
                }
            }else system("pause");


        }else if(choice==5){
            system("cls");
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="DELETE PRODUCT";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            SubHeader("DELETE PRODUCT",6,30,7);
            PList.display();
            if(!PList.isEmpty()){
                cout<<"\t\tInput ID: ";cin>>id;
                while(!PList.isExist(id)){
                    cout<<("\t\tThere no data match!!\n");
                    cout<<"\t\tTry again:";cin>>id;
                }
                system("cls");
                SubHeader("DELETE PRODUCT("+to_string(PList.Search_Quantity(id))+")",6,30,7);
                PList.displayByID(id);
                string ch;
                cout<<"\t\tAre you Sure?yes|no: ";cin>>ch;
                if(ch[0]=='y'|| ch[0]=='Y'){
                    PList.deleteByID(id);
                    PList.SaveTO(Path_p);
                }

            }
            system("pause");

        }else if(choice==6){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="SEARCH PRODUCT";

            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");
            if(!PList.isEmpty()){
                int x=0;
                while(true){
                    system("cls");
                    SubHeader("SEARCH PRODUCT",6,30,7);
                    PList.display();
                    string keyWord;
                    if(x==0){
                        cin.ignore();
                        x++;
                    }
                    cout<<"\n\t\tInput KeyWord: ";getline(cin,keyWord);
                    system("cls");
                    SubHeader("SEARCH PRODUCT("+to_string(PList.Search_Quantity(keyWord))+")",6,30,7);
                    cout<<"\n\t\tSearch\""<<keyWord<<"\""<<endl;
                    PList.Search(keyWord);
                    cout<<"Press any key to continue|Esc back to Menu:";
                    if(_getch()==27){
                        break;
                    }
                }


            }else{
                PList.display();
            }
        }else{
            break;
        }
    }
    PList.Clear();
}
void UpdateMenu(){
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
           "1.Edit ID",
           "2.Edit NAME",
           "3.Edit PRICE",
           "4.Edit IMPORT DATE",
           "5.Edit EXPIRE DATE",
           "6.Edit QUANTITY",
           "7.Edit ALL",
           "8.CANCEL");
    printf("\t\t");
    for(int i=0;i<70;i++){
        printf("=");
    }
}


#include<iostream>
#include"DataStructure.h"
using namespace std;
Book BList;
string Path_B="Book Management/Save/File.txt";
bool is_valid(Date date){
    if(date.year>0){
        if(date.month>=0 && date.month <=12){
            if((date.month==1 || date.month==3 ||date.month==5||
                date.month==7 ||date.month==8||date.month==10||date.month==12) && (date.day>=0 && date.day<=31)){
                return true;
            }
            else if((date.month==4|| date.month==6||date.month==9 ||date.month==11)&& (date.day>=0 && date.day<=30)){
                return true;
            }else if(date.month==2 &&(date.day>=0&& date.day<=28)){
                return true;
            }else if(date.day==0){
                return true;
            }else if(date.month==0){
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
void UpdateMenu_B();
void BookMenu(History *HistoryList){
    BList.Clear();
    BList.LoadFrom(Path_B);
    string id;
    while(true){
    string Path="MAIN MENU/BOOK MANAGEMENT/";
    system("cls");
    SubHeader("BOOK MANAGEMENT",4,32,5);
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
               "1.Input Book",
               "2.Display All Book",
               "3.Display Book By ID",
               "4.Update Book ID",
               "5.Delete Book ID",
               "6.Search Book",
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
            Path+="INPUT BOOK";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");

            while(true){

                string id,ISBN,author,title;
                Date date;
                float Price;
                system("cls");
                SubHeader("INPUT BOOKS",5,24,6);
                BList.display();
                cout<<"\t\tInput New ID:";cin>>id;
                while(BList.isExist_ID(id)){
                    cout<<"\t\tInput Invalid!!\n";
                    cout<<"\t\tAgain: ";cin>>id;
                }

                cout<<"\t\tInput New ISBN:";cin>>ISBN;
                while(BList.isExist_ISBN(ISBN)){
                    cout<<"\t\tInput Invalid!!\n";
                    cout<<"\t\tAgain: ";cin>>ISBN;
                }

                cin.ignore();
                cout<<"\t\tInput New Title:";getline(cin,title);
                cout<<"\t\tInput New Author(Separate by |):";getline(cin,author);


                cout<<"\t\tInput New Release Date: ";
                scanf("%d\\%d\\%d",&date.day,&date.month,&date.year);

                while(!is_valid(date)){
                    cout<<"\t\tInput invalid\n";
                    cout<<"\t\tInput New Release Date: ";
                    scanf("%d\\%d\\%d",&date.day,&date.month,&date.year);
                }

                cout<<"\t\tInput New Price:";cin>>Price;
                BList.Insert(id,ISBN,title,author,date,Price);
                cout<<"Press any key to continue|Esc back to Menu:";

                BList.SaveTO(Path_B);
                if(_getch()==27){
                    break;
                }
            }

        }else if(choice==2){
                system("cls");
                SubHeader("DISPLAY BOOK("+to_string(BList.Size())+")",6,28,7);
                time_t result = time(nullptr);
                string time= asctime(localtime(&result));
                Path+="DISPLAY BOOK";
                HistoryList->Insert(time,Path);
                HistoryList->SaveTo("History/Save/file.txt");

            BList.display();
            system("pause");

        }else if(choice==3){
            system("cls");
            SubHeader("DISPLAY BOOK BY ID",5,34,6);
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="DISPLAY BOOK BY ID";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");

            if(!BList.isEmpty()){
                SubHeader("DISPLAY BOOK BY ID("+to_string(BList.Search_Quantity(id))+")",5,34,6);
                cout<<"\t\tInput ID: ";cin>>id;
                BList.displayByID(id);
            }else{

                BList.display();
            }
            system("pause");


        }else if(choice==4){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="UPDATE BOOK BY ID";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");


            system("cls");
            SubHeader("UPDATE BOOK BY ID",4,34,5);
            BList.display();
            if(!BList.isEmpty()){

                cout<<"\t\tInput ID: ";cin>>id;

                while(!BList.isExist_ID(id)){
                    cout<<("\t\tThere no data match!!\n");
                    cout<<"\t\tTry again:";cin>>id;
                }


                while(true){
                    system("cls");
                    SubHeader("UPDATE BOOK BY ID",4,34,5);
                    UpdateMenu_B();
                    cout<<"\n\t\tInput you Option: ";cin>>choice;
                    while(choice<1 || choice>8){
                        cout<<("\t\tInput Invalid!!\n");
                        cout<<"\t\tTry again: ";cin>>choice;
                    }
                    if(choice==8){
                        break;
                    }
                    BList.updateByID(&id,choice);
                    BList.displayByID(id);
                    cout<<"Press any key to continue|Esc back to Menu:";
                    BList.SaveTO(Path_B);
                    if(_getch()==27){
                        break;
                    }


                }
            }else system("pause");

        }else if(choice==5){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="DELETE BOOK BY";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");

            system("cls");
            SubHeader("DELETE BOOK",6,28,7);
            BList.display();
            if(!BList.isEmpty()){
                cout<<"\t\tInput ID: ";cin>>id;
                while(!BList.isExist_ID(id)){
                    cout<<("\t\tThere no data match!!\n");
                    cout<<"\t\tTry again:";cin>>id;
                }
                system("cls");
                SubHeader("DELETE BOOK("+to_string(BList.Search_Quantity(id))+")",6,28,7);
                BList.displayByID(id);
                string ch;
                cout<<"\t\tAre you Sure?yes|no: ";cin>>ch;
                if(ch[0]=='y'|| ch[0]=='Y'){
                    BList.deleteByID(id);
                    BList.SaveTO(Path_B);
                }

            }
            system("pause");

        }else if(choice==6){
            time_t result = time(nullptr);
            string time= asctime(localtime(&result));
            Path+="SEARCH BOOK";
            HistoryList->Insert(time,Path);
            HistoryList->SaveTo("History/Save/file.txt");

            if(!BList.isEmpty()){
                    int x=0;
                while(true){
                    system("cls");
                    SubHeader("SEARCH BOOK",6,28,7);
                    BList.display();
                    string keyWord;
                    if(x==0){
                    cin.ignore();

                    }
                    cout<<"\n\t\tInput KeyWord: ";getline(cin,keyWord);
                    system("cls");
                    SubHeader("SEARCH BOOK("+to_string(BList.Search_Quantity(keyWord))+")",6,28,7);
                    cout<<"\n\t\tSearch\""<<keyWord<<"\""<<endl;
                    BList.Search(keyWord);
                    x++;
                    cout<<"Press any key to continue|Esc back to Menu:";
                    if(_getch()==27){
                        break;
                    }
                }


            }
        }else{
            break;
        }
    }
}

void UpdateMenu_B(){
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
           "2.Edit ISBN",
           "3.Edit TITLE",
           "4.Edit RELEASE DATE",
           "5.Edit AUTHOR",
           "6.Edit PRICE",
           "7.Edit ALL",
           "8.CANCEL");
    printf("\t\t");
    for(int i=0;i<70;i++){
        printf("=");
    }
}





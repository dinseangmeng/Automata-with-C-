#include<iostream>
#include"DataStructure.h"
#include <tabulate/table.hpp>
#include <string>
#include<fstream>
using namespace std;
using namespace tabulate;
string intToMonth(int n){
    switch(n){
    case 1:
        return "JAN";
        break;
    case 2:
        return "FEB";
        break;
    case 3:
        return "MAR";
        break;
    case 4:
        return "APR";
        break;
    case 5:
        return "MAY";
        break;
    case 6:
        return "JUN";
        break;
    case 7:
        return "JUL";
        break;
    case 8:
        return "AUG";
        break;
    case 9:
        return "SEPT";
        break;
    case 10:
        return "OCT";
        break;
    case 11:
        return "NOV";
        break;
    case 12:
        return "DEC";
        break;
    }
}
Date StringToDate(string text){
    string t="";
    int k=0;
    Date date;
    string arr[3];
    for(int i=0;i<text.size();i++){
        if(text[i]=='\\'){
            arr[k]=t;
            k++;
            t="";
            continue;
        }
        if(i==(text.size()-1)){
            t+=text[i];
            arr[k]=t;
            k++;
            t="";
            continue;
        }
        t+=text[i];
    }
    date.day=stoi(arr[0]);
    date.month=stoi(arr[1]);
    date.year=stoi(arr[2]);

    return date;
}
string dateToString(Date date,bool display=false){
    string text="";
    if(display){
        if(date.day>0 &&date.month>0&&date.year>0){
            text+=to_string(date.day)+"\\"
                +intToMonth(date.month)+"\\"
                +to_string(date.year);
        }else if(date.day==0 &&date.month>0 &&date.year){
            text+=intToMonth(date.month)+"\\"
                +to_string(date.year);
        }else if(date.day==0 && date.month==0 &&date.year>0){
            text+=to_string(date.year);
        }

    }else{
        text+=to_string(date.day)+"\\"
            +to_string(date.month)+"\\"
            +to_string(date.year);
    }
    return text;
}
string ToUpperCase(string text){
    int i=0;
    while(text[i]!='\0'){
        if(text[i]>=97 && text[i]<=122){
            text[i]=text[i]-32;
        }
        i++;
    }
    return text;
}
Author::Author(){
    this->n=0;
    this->head=NULL;
    this->tail=NULL;
}
void Author::Insert(string Name){
    Element *tmp=new Element;
    tmp->Name=Name;
    tmp->next=NULL;
    if(n==0){
        this->head=tmp;
        this->tail=tmp;
    }else{
        this->tail->next=tmp;
        this->tail=tmp;
    }
    n++;
}
string Author::getName(int pos){
    Element *tmp=head;
    if(pos<n){
        for(int i=0;i<pos;i++){
            tmp=tmp->next;
        }
        return tmp->Name;
    }else{
        return tmp->Name;
    }
}
string Author::getAllName(char separator){
    Element *tmp=head;
    string text="";
    for(int i=0;tmp!=NULL;i++){
        if(i==n-1){
            text+=ToUpperCase(tmp->Name);
        }else{text+=ToUpperCase(tmp->Name)+separator;}
        tmp=tmp->next;
    }
    return text;
}
string EncryptSpace(string text){

    string tmp="";
    for(int i=0;i<text.size();i++){
        if(text[i]==' '){
            tmp+=':';
        }else{
            tmp+=text[i];
        }
    }
    return tmp;
}
string DecryptSpace(string text){
    char ch=172;
    string tmp="";
    for(int i=0;i<text.size();i++){
        if(text[i]==':'){
            tmp+=" ";
        }else{
            tmp+=text[i];
        }
    }
    return tmp;
}

void Author::DeleteFront(){
    if(n!=0){
        Element *tmp=head;
        head=head->next;
        delete tmp;
        n--;
    }
}

Book::Book(){
    this->n=0;
    this->head=NULL;
    this->tail=NULL;
}
char separator='|';

bool is_Valid(Date date){
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
void stringToAuthor(Author *Au,string autor){
    string text="";
    for(int i=0;i<autor.size();i++){
        if(autor[i]==separator){
            Au->Insert(text);

            text="";
            continue;
        }
        if(i==autor.size()-1){
            text+=autor[i];
            Au->Insert(text);

            text="";
        }
        text+=autor[i];
    }
}
void Book::Insert(string id,string ISBN,string title,
                string autor,Date release,float price)
{
    Element *tmp=new Element;
    string text="";
    stringToAuthor(&tmp->author,autor);

    tmp->id=id;
    tmp->ISBN=ISBN;
    tmp->Price=price;
    tmp->title=title;
    tmp->Release=release;
    tmp->next=NULL;
    if(n==0){
        head=tmp;
        tail=tmp;
    }else{
        tail->next=tmp;
        tail=tmp;
    }
    n++;
}
int width=120;
bool Book::isExist_ID(string ID){
    Element *tmp=head;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->id)==ToUpperCase(ID)){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}
bool Book::isExist_ISBN(string ISBN){
    Element *tmp=head;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->ISBN)==ToUpperCase(ISBN)){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}
bool Book::isEmpty(){
    if(n==0){
        return true;
    }
    return false;
}
void Book::deleteByID(string Keyword){
    Element *tmp1,*tmp=head;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->id)==ToUpperCase(Keyword)){
            break;
        }else{
            tmp1=tmp;
            tmp=tmp->next;
        }
    }
    if(tmp!=NULL){
        if(tmp==head){
            head=head->next;
        }else{
            tmp1->next=tmp->next;
        }

        delete(tmp);
        n--;
        cout<<("\t\tDelete Successful!!\n");
    }else{cout<<("\n\t\tThere No data Match\n");}
}
char Separator='\n';
void Book::display(){
    Table table,MainTable;

    if(n!=0){
        Element *tmp=head;
        table.add_row({"ID","ISBN","TITLE","AUTHOR","RELEASE\n(DD\\MM\\YYYY)","PRICE\n$"});

        while(tmp!=NULL){
            table.add_row({
                            tmp->id,
                            tmp->ISBN,
                            ToUpperCase(tmp->title),
                            tmp->author.getAllName(Separator),
                            dateToString(tmp->Release,true),
                            to_string(tmp->Price)+"$"
                          });
            tmp=tmp->next;
        }
        table[0].format().font_align(FontAlign::center).font_style({FontStyle::bold});
        MainTable.add_row({table});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(width);
        MainTable.format().hide_border();

    }else{
        table.add_row({"ID","ISBN","TITLE","AUTHOR","RELEASE\n(DD\\MM\\YYYY)","PRICE\n$"});
        Table ms,tb;

        ms.add_row({"THERE NO DATA IN HERE"});
        table[0].format().font_align(FontAlign::center);
        ms.format().hide_border();
        tb.add_row({table});
        tb.add_row({ms});
        tb.format().font_align(FontAlign::center);
        MainTable.add_row({tb});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(90);
        MainTable.format().hide_border();
    }
    cout<<MainTable<<endl;
}
void Book::DeleteFront(){
    if(n!=0){
        Element *tmp=head;
        head=head->next;
        delete(tmp);
        n--;
    }

}
void Book::displayByID(string Keyword){
    Element *tmp=head;
    Table table,MainTable;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->id)==ToUpperCase(Keyword)){
            break;
        }
        tmp=tmp->next;
    }
    if(tmp!=NULL){
        table.add_row({"ID","ISBN","TITLE","AUTHOR","RELEASE\n(DD\\MM\\YYYY)","PRICE\n$"});
        table.add_row({
                tmp->id,
                tmp->ISBN,
                ToUpperCase(tmp->title),
                tmp->author.getAllName(Separator),
                dateToString(tmp->Release,true),
                to_string(tmp->Price)+"$"
                  });
        table[0].format().font_align(FontAlign::center).font_style({FontStyle::bold});
        MainTable.add_row({table});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(width);
        MainTable.format().hide_border();
        cout<<MainTable;
    }else{
        cout<<("\t\tThere no data match\n");
    }
}

void Book::Clear(){
    int k=this->n;
    for(int i=0;i<k;i++){
        this->DeleteFront();
    }
}
int Book::Size(){
    return this->n;
};
void Book::updateByID(string *Keyword,int option){
    Element *tmp=head;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->id)==ToUpperCase(*Keyword)){
            break;
        }
        tmp=tmp->next;
    }
    if(tmp!=NULL){
        string id,ISBN,author;
        Date date;
        if(option==1){
            cout<<"\t\tInput New ID: ";cin>>id;
            while(Book::isExist_ID(id)){
                cout<<"\t\tInput Invalid!!\n";
                cout<<"\t\tAgain: ";cin>>id;
            }
            if(ToUpperCase(tmp->id)==ToUpperCase(*Keyword)){
                *Keyword=id;
            }
            tmp->id=id;
        }else if(option==2){

            cout<<"\t\tInput New ISBN: ";cin>>ISBN;
            while(Book::isExist_ISBN(ISBN)){
                cout<<"\t\tInput Invalid!!\n";
                cout<<"\t\tAgain: ";cin>>ISBN;
            }

            tmp->ISBN=ISBN;
        }else if(option==3){
            cin.ignore();
            cout<<"Input New Title: ";getline(cin,tmp->title);
        }else if(option==4){
            for(int i=0;i<tmp->author.Size();i++){
                tmp->author.DeleteFront();
            }
            cout<<"Input New Author(Separate by |): ";cin>>author;
            stringToAuthor(&tmp->author,author);
        }else if(option==5){

            cout<<"Input New Release Date: ";
            scanf("%d\\%d\\%d",&date.day,&date.month,&date.year);
            while(!is_Valid(date)){
                cout<<"\t\tInput invalid\n";
                cout<<"\t\tInput New Release Date: ";
                scanf("%d\\%d\\%d",&date.day,&date.month,&date.year);
            }
            tmp->Release=date;
        }else if(option==6){
            cout<<"\t\tInput New Price: ";cin>>tmp->Price;
        }else if(option==7){
            cout<<"\t\tInput New ID:";cin>>id;
            while(Book::isExist_ID(id)){
                cout<<"\t\tInput Invalid!!\n";
                cout<<"\t\tAgain: ";cin>>id;
            }
            if(ToUpperCase(tmp->id)==ToUpperCase(*Keyword)){
                *Keyword=id;

            }
            tmp->id=id;
            cout<<"\t\tInput New ISBN:";cin>>ISBN;
            while(Book::isExist_ISBN(ISBN)){
                cout<<"\t\tInput Invalid!!\n";
                cout<<"\t\tAgain: ";cin>>ISBN;
            }

            tmp->ISBN=ISBN;
            cin.ignore();
            cout<<"\t\tInput New Title:";getline(cin,tmp->title);
            cout<<"\t\tInput New Author(Separate by |):";getline(cin,author);
            for(int i=0;i<tmp->author.Size();i++){
                tmp->author.DeleteFront();
            }
            stringToAuthor(&tmp->author,author);
            cout<<"\t\tInput New Release Date: ";
            scanf("%d\\%d\\%d",&date.day,&date.month,&date.year);
            while(!is_Valid(date)){
                cout<<"\t\tInput invalid\n";
                cout<<"\t\tInput New Release Date: ";
                scanf("%d\\%d\\%d",&date.day,&date.month,&date.year);
            }
            tmp->Release=date;
            cout<<"\t\tInput New Price:";cin>>tmp->Price;

            if(ToUpperCase(tmp->id)==ToUpperCase(*Keyword)){
                *Keyword=tmp->id;

            }
        }

    }
}
int Book::Search_Quantity(string KeyWord){
    Element *tmp=head;

    int k=0;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->id).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(tmp->title).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(tmp->author.getAllName()).find(ToUpperCase(KeyWord))!=string::npos||
           dateToString(tmp->Release).find(ToUpperCase(KeyWord))!=string::npos||
           dateToString(tmp->Release,true).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(tmp->ISBN).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(to_string(tmp->Price)+"$").find(ToUpperCase(KeyWord))!=string::npos
           ){

          k++;
        };
        tmp=tmp->next;

    }
    return k;
};
void Book::Search(string KeyWord){
    Element *tmp=head;
    Table table,MainTable;
        table.add_row({"ID","ISBN","TITLE","AUTHOR","RELEASE\n(DD\\MM\\YYYY)","PRICE\n$"});
    int k=0;
    while(tmp!=NULL){
        if(ToUpperCase(tmp->id).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(tmp->title).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(tmp->author.getAllName()).find(ToUpperCase(KeyWord))!=string::npos||
           dateToString(tmp->Release).find(ToUpperCase(KeyWord))!=string::npos||
           dateToString(tmp->Release,true).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(tmp->ISBN).find(ToUpperCase(KeyWord))!=string::npos||
           ToUpperCase(to_string(tmp->Price)+"$").find(ToUpperCase(KeyWord))!=string::npos
           ){
            table.add_row({
                            tmp->id,
                            tmp->ISBN,
                            ToUpperCase(tmp->title),
                            tmp->author.getAllName(Separator),
                            dateToString(tmp->Release,true),
                            to_string(tmp->Price)+"$"
                          });
          k++;
        };
        tmp=tmp->next;

    }
    if(k==0){
        Table ms,tb;

        ms.add_row({"THERE NO DATA IN HERE"});
        table[0].format().font_align(FontAlign::center);
        ms.format().hide_border();
        tb.add_row({table});
        tb.add_row({ms});
        tb.format().font_align(FontAlign::center);
        MainTable.add_row({tb});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(90);
        MainTable.format().hide_border();
    }else{
        table[0].format().font_align(FontAlign::center).font_style({FontStyle::bold});
            MainTable.add_row({table});
            MainTable.format().font_align(FontAlign::center);
            MainTable.format().width(width);
            MainTable.format().hide_border();
    }
    cout<<MainTable<<endl;
}
void Book::SaveTO(string Path){
    Element *tmp=head;
    fstream file;
    file.open(Path.c_str(),ios::out);
    while(tmp!=NULL){
        file<<"\n"<<tmp->id<<" "<<tmp->ISBN<<" "<<tmp->Price<<" "<<EncryptSpace(tmp->author.getAllName())
            <<" "<<dateToString(tmp->Release)<<" "<<EncryptSpace(tmp->title);
        tmp=tmp->next;
    }
    file.close();
}
void Book::LoadFrom(string Path){

    string id,ISBN,date,author,title;
    float Price;
    fstream file;
    file.open(Path.c_str(),ios::in);
    while(!file.eof()){
        file>>id>>ISBN>>Price>>author>>date>>title;

        this->Insert(id,ISBN,DecryptSpace(title),DecryptSpace(author),StringToDate(date),Price);

    }

}

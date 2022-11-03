#include <iostream>
#include <fstream>
#include<color.hpp>
#include <tabulate/table.hpp>
#include "DataStructure.h"

using namespace tabulate;

using namespace std;

string IntToMonth(int n){
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
date stringToDate(string text){
    string t="";
    int k=0;
    date Date;
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
    Date.day=stoi(arr[0]);
    Date.month=stoi(arr[1]);
    Date.year=stoi(arr[2]);

    return Date;
}
int Width=120;
string ToupperCase(string text){
    int i=0;
    while(text[i]!='\0'){
        if(text[i]>=97 && text[i]<=122){
            text[i]=text[i]-32;
        }
        i++;
    }
    return text;
}
string DateToString(date Date,bool display=false){
    string text="";
    if(display){
        if(Date.day>0 &&Date.month>0&&Date.year>0){
            text+=to_string(Date.day)+"\\"
                +IntToMonth(Date.month)+"\\"
                +to_string(Date.year);
        }else if(Date.day==0 &&Date.month>0 &&Date.year){
            text+=IntToMonth(Date.month)+"\\"
                +to_string(Date.year);
        }else if(Date.day==0 && Date.month==0 &&Date.year>0){
            text+=to_string(Date.year);
        }

    }else{
        text+=to_string(Date.day)+"\\"
            +to_string(Date.month)+"\\"
            +to_string(Date.year);
    }
    return text;
}
bool is_Valid(date Date){
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
Product::Product(){
    this->n=0;
    this->head=NULL;
    this->tail=NULL;
}
void Product::Insert(string id,string name,float price,
                date importDate,date expireDate,int quantity){
    Element * tmp=new Element;
    tmp->next=NULL;
    tmp->id=id;tmp->name=name;tmp->price=price;
    tmp->importDate=importDate;
    tmp->expireDate=expireDate;
    tmp->quantity=quantity;
    if(n==0){
        head=tmp;
        tail=tmp;
    }else{
        tail->next=tmp;
        tail=tmp;
    }
    n++;
}

void Product::DeleteFront(){
if(n!=0){
        Element *tmp=this->head;
        head=head->next;
        delete(tmp);
        n--;

}
};

int Product::Search_Quantity(string KeyWord){
    Element *tmp=head;

    int k=0;
    while(tmp!=NULL){
        if(ToupperCase(tmp->id).find(ToupperCase(KeyWord))!=string::npos||
           ToupperCase(tmp->name).find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->expireDate).find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->expireDate,true).find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->importDate).find(ToupperCase(KeyWord))!=string::npos||
           ToupperCase(to_string(tmp->price)+"$").find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->importDate,true).find(ToupperCase(KeyWord))!=string::npos){

          k++;
        };
        tmp=tmp->next;

    }
    return k;
};
int Product::Size(){
    return this->n;
};
void Product::deleteByID(string ID){
    Element *tmp1,*tmp=head;
    while(tmp!=NULL){
        if(ToupperCase(tmp->id)==ToupperCase(ID)){
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
        cout<<dye::green("\t\tDelete Successful!!\n");
    }else{cout<<dye::red("\n\t\tThere No data Match\n");}
}
void Product::display(){

    Table table,MainTable;
    if(n!=0){

        Element *tmp=head;

        table.add_row({"ID","NAME",
                      "PRICE\n($)","EXPORT\n(DD\\MM\\YYYY)"
                      ,"EXPIRE\n(DD\\MM\\YYYY)","Quantity"});

        while(tmp!=NULL){
            table.add_row({
                          tmp->id,
                          ToupperCase(tmp->name),
                          to_string(tmp->price)+"$",
                          DateToString(tmp->importDate,true),
                          DateToString(tmp->expireDate,true),
                          to_string(tmp->quantity)
            });
            tmp=tmp->next;
        }


        table[0].format().font_align(FontAlign::center).font_style({FontStyle::bold});
        MainTable.add_row({table});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(Width);
        MainTable.format().hide_border();
    }else{
        table.add_row({"ID","NAME","PRICE\n($)","EXPORT\n(DD\\MM\\YYYY)","EXPIRE\n(DD\\MM\\YYYY)"});
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
void Product::updateByID(string *ID,int option){
    Element *tmp=head;
    while(tmp!=NULL){
        if(ToupperCase(tmp->id)==ToupperCase(*ID)){
            break;
        }
        tmp=tmp->next;
    }
    if(tmp!=NULL){
        if(option==1){
            string kk;
            cout<<"\t\tInput New ID: ";cin>>kk;
            while(Product::isExist(kk)){
                cout<<"\t\tID Invalid!!\n";
                cout<<"\t\tTry Again: ";cin>>kk;
            }
            tmp->id=kk;
            *ID=tmp->id;
        }else if(option==2){
            cin.ignore();
            cout<<"\t\tInput New NAME: ";getline(cin,tmp->name);
        }else if(option==3){
            cout<<"\t\tInput New Price: ";cin>>tmp->price;
        }else if(option==4){
            date importDate;
            cout<<"\t\tInput New Import Date: ";scanf("%d\\%d\\%d"
                                                     ,&importDate.day
                                                     ,&importDate.month
                                                     ,&importDate.year);
            while(!is_Valid(importDate)){
                cout<<"\t\tInput invalid\n";
                cout<<"\t\tTry again:";scanf("%d\\%d\\%d"
                                                     ,&importDate.day
                                                     ,&importDate.month
                                                     ,&importDate.year);
            }
            tmp->importDate=importDate;
        }else if(option==5){
            date expireDate;
            cout<<"\t\tInput New Expire Date: ";scanf("%d\\%d\\%d"
                                                     ,&expireDate.day
                                                     ,&expireDate.month
                                                     ,&expireDate.year);
            while(!is_Valid(expireDate)){
                cout<<"\t\tInput invalid\n";
                cout<<"\t\tInput New Expire Date: ";scanf("%d\\%d\\%d"
                                                     ,&expireDate.day
                                                     ,&expireDate.month
                                                     ,&expireDate.year);
            }
            tmp->expireDate=expireDate;
        }else if(option==6){
            cout<<"\t\tInput New Quantity: ";cin>>tmp->quantity;
        }else if(option==7){
            string id;
            cout<<"\t\tInput New ID: ";cin>>id;
            while(Product::isExist(id)){
                cout<<"\t\tID Invalid!!\n";
                cout<<"\t\tTry Again: ";cin>>id;
            }
            tmp->id=id;
            *ID=tmp->id;
            date importDate,expireDate;
            cin.ignore();
            cout<<"\t\tInput New NAME: ";getline(cin,tmp->name);
            cout<<"\t\tInput New PRICE: ";cin>>tmp->price;
            cout<<"\t\tInput New Import Date: ";scanf("%d\\%d\\%d"
                                                     ,&importDate.day
                                                     ,&importDate.month
                                                     ,&importDate.year);
            while(!is_Valid(importDate)){
                cout<<"\t\tInput invalid\n";
                cout<<"\t\tTry again:";scanf("%d\\%d\\%d"
                                                     ,&importDate.day
                                                     ,&importDate.month
                                                     ,&importDate.year);
            }
            tmp->importDate=importDate;
            cout<<"\t\tInput New Expire Date: ";scanf("%d\\%d\\%d"
                                                     ,&expireDate.day
                                                     ,&expireDate.month
                                                     ,&expireDate.year);
            while(!is_Valid(expireDate)){
                cout<<"\t\tInput invalid\n";
                cout<<"\t\tInput New Expire Date: ";scanf("%d\\%d\\%d"
                                                     ,&expireDate.day
                                                     ,&expireDate.month
                                                     ,&expireDate.year);
            }
            tmp->expireDate=expireDate;
             cout<<"\t\tInput New Quantity: ";cin>>tmp->quantity;
        }
        cout<<dye::green("\t\tUpdate Successful\n");
    };
}
bool Product::isExist(string ID){
    Element *tmp=head;
    while(tmp!=NULL){
        if(ToupperCase(tmp->id)==ToupperCase(ID)){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}
void Product::Clear(){
    int k=this->n;
    for(int i=0;i<k;i++){
        this->DeleteFront();
    }

};
void Product::Search(string KeyWord){
    Element *tmp=head;
    Table table,MainTable;
    table.add_row({"ID","NAME",
              "PRICE\n($)","EXPORT\n(DD\\MM\\YYYY)"
              ,"EXPIRE\n(DD\\MM\\YYYY)","Quantity"});
    int k=0;
    while(tmp!=NULL){
        if(ToupperCase(tmp->id).find(ToupperCase(KeyWord))!=string::npos||
           ToupperCase(tmp->name).find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->expireDate).find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->expireDate,true).find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->importDate).find(ToupperCase(KeyWord))!=string::npos||
           ToupperCase(to_string(tmp->price)+"$").find(ToupperCase(KeyWord))!=string::npos||
           DateToString(tmp->importDate,true).find(ToupperCase(KeyWord))!=string::npos){
            table.add_row({
                          tmp->id,
                          tmp->name,
                          to_string(tmp->price)+"$",
                          DateToString(tmp->importDate,true),
                          DateToString(tmp->expireDate,true),
                          to_string(tmp->quantity)});
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
            MainTable.format().width(Width);
            MainTable.format().hide_border();
    }
    cout<<MainTable<<endl;
}
void Product::displayByID(string ID){
    Element*tmp=head;
    while(tmp!=NULL){
        if(ToupperCase(tmp->id)==ToupperCase(ID)){
            break;
        }
        tmp=tmp->next;
    }
    if(tmp!=NULL){
        Table table,MainTable;
        table.add_row({"ID","NAME",
              "PRICE\n($)","EXPORT\n(DD\\MM\\YYYY)"
              ,"EXPIRE\n(DD\\MM\\YYYY)","Quantity"});
        table.add_row({
                      tmp->id,
                      ToupperCase(tmp->name),
                      to_string(tmp->price)+"$",
                      DateToString(tmp->importDate,true),
                      DateToString(tmp->expireDate,true),
                      to_string(tmp->quantity)
        });
        table[0].format().font_align(FontAlign::center).font_style({FontStyle::bold});
        MainTable.add_row({table});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(Width);
        MainTable.format().hide_border();
        cout<<MainTable<<endl;
    }else{
        cout<<dye::red("\t\tThere no data match\n");
    }
}
bool Product::isEmpty(){
    if(n==0){
        return true;
    }else return false;
}
void Product::SaveTO(string Path){
    Element *tmp=head;
    fstream file;
    file.open(Path.c_str(),ios::out);
    while(tmp!=NULL){
        file<<"\n"<<tmp->id<<" "<<tmp->price
            <<" "<<DateToString(tmp->importDate)<<" "<<DateToString(tmp->expireDate)
            <<" "<<tmp->quantity<<" "<<tmp->name;
        tmp=tmp->next;
    }
    file.close();
}
void Product::LoadFrom(string Path){
    fstream file;
    string id,name,im,ex,tmp;float price;date import,expire;int quantity;
    file.open(Path.c_str(),ios::in);
    while(!file.eof()){
        file>>id>>price>>im>>ex>>quantity;
        getline(file,name);
        this->Insert(id,name,price,stringToDate(im),stringToDate(ex),quantity);

    }
}

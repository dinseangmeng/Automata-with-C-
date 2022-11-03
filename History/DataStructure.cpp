#include <iostream>
#include "DataStructure.h"
#include <tabulate/table.hpp>
#include <fstream>
using namespace tabulate;
using namespace std;
string To_upperCase(string text){
    int i=0;
    while(text[i]!='\0'){
        if(text[i]>=97 && text[i]<=122){
            text[i]=text[i]-32;
        }
        i++;
    }
    return text;
}
History::History(){
    this->n=0;
    this->head=NULL;
    this->tail=NULL;

};

void History::Insert(string time,string path){
    Element *tmp=new Element;
    tmp->path=path;
    tmp->time=time;
    tmp->next=NULL;
    if(n==0){
        head=tmp;
        tail=tmp;
    }else{
        tail->next=tmp;
        tail=tmp;
    }
    n++;
};
void History::Display(){
    Table table,MainTable;

    if(n!=0){
        Element *tmp=head;
        table.add_row({"PATH","TIME"});

        while(tmp!=NULL){
            table.add_row({
                            tmp->path,
                            tmp->time
                          });
            tmp=tmp->next;
        }
        table[0].format().font_align(FontAlign::center).font_style({FontStyle::bold});
        MainTable.add_row({table});
        MainTable.format().font_align(FontAlign::center);
        MainTable.format().width(100);
        MainTable.format().hide_border();

    }else{
        table.add_row({"PATH","TIME"});
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
};
void History::Search(string Keyword){
    Element *tmp=head;
    Table table,MainTable;
    table.add_row({"PATH","TIME"});
    int k=0;
    while(tmp!=NULL){
        if(To_upperCase(tmp->time).find(To_upperCase(Keyword))!=string::npos||
           To_upperCase(tmp->path).find(To_upperCase(Keyword))!=string::npos){
            table.add_row({
                            tmp->path,
                            tmp->time
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
            MainTable.format().width(100);
            MainTable.format().hide_border();
    }
    cout<<MainTable<<endl;
};
int History::Search_Quantity(string Keyword){
    Element *tmp=head;

    int k=0;
    while(tmp!=NULL){
        if(To_upperCase(tmp->time).find(To_upperCase(Keyword))!=string::npos||
           To_upperCase(tmp->path).find(To_upperCase(Keyword))!=string::npos){

          k++;
        };
        tmp=tmp->next;

    }
    return k;

};
void History::Delete(){
    if(n!=0){
        Element *tmp=head;
        head=head->next;
        delete(tmp);
        n--;
    }
}
int History::Size(){
    return n;
}
void History::Clear(){
    int k=n;
    for(int i=0;i<k;i++){
        this->Delete();
    }
}

string encryptSpace(string text){

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
string decryptSpace(string text){
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
void History::LoadFrom(string Path){
    fstream file;
    string time,path;
    file.open(Path.c_str(),ios::in);
    while(!file.eof()){
        file>>path;
        getline(file,time);
        if(time!="" && time!=" " && path!="" && path!=" "){
            this->Insert(time,decryptSpace(path));
        }
    }
    file.close();

};

void History::SaveTo(string Path){
    fstream file;
    Element *tmp=head;
    file.open(Path.c_str(),ios::out);
    while(tmp!=NULL){
        file<<"\n"<<encryptSpace(tmp->path)<<" "<<tmp->time;
        tmp=tmp->next;
    }
    file.close();
};


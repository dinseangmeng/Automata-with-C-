#include<iostream>
using namespace std;


class Author{
private:
    struct Element{
        string Name;
        Element *next;
    };
    int n;
    Element *head,*tail;

public:
    Author();
    void Insert(string Name);
    string getName(int pos);
    string getAllName(char separator=',');
    void DeleteFront();
    int Size(){
        return this->n;
    };

};
struct Date{
    int day,month,year;
};
class Book{
private:
    struct Element{
        string id,ISBN,title;
        Author author;
        Date Release;
        float Price;
        Element *next;
    };
    int n;
    Element *head,*tail;
    void DeleteFront();
public:
    Book();
    void Insert(string id,string ISBN,string title,
                string autor,Date release,float price);
    void deleteByID(string Keyword);
    void updateByID(string *Keyword,int option);

    void display();
    void displayByID(string Keyword);
    void Search(string KeyWord);
    int Search_Quantity(string KeyWord);
    bool isEmpty();
    void SaveTO(string Path);
    void LoadFrom(string Path);
    bool isExist_ID(string ID);
    bool isExist_ISBN(string ISBN);
    int Size();
    void Clear();


};

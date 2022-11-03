#include <iostream>

using namespace std;
struct date{
    int day,month,year;
};


class Product{
private:

    struct Element{
        string id,name;
        float price;
        date importDate,expireDate;
        int quantity;
        Element *next;
    };
    int n;
    Element *head,*tail;
    void DeleteFront();
public:
    Product();
    void Insert(string id,
                string name,
                float price,
                date importDate,
                date expireDate,
                int quantity);
    void deleteByID(string ID);
    void updateByID(string *ID,int option);
    bool isExist(string ID);
    void display();
    void displayByID(string ID);
    void Search(string KeyWord);
    int Search_Quantity(string KeyWord);
    bool isEmpty();
    void SaveTO(string Path);
    void LoadFrom(string Path);
    int Size();
    void Clear();
};

#include <iostream>
using namespace std;

class History{

private:
    struct Element{
        string time,path;
        Element *next;
    };
    int n;
    Element *head,*tail;
    void Delete();
public:
    History();
    void Insert(string time,string path);
    void Display();
    void Search(string Keyword);
    int Search_Quantity(string Keyword);
    void Clear();
    int Size();
    void LoadFrom(string Path);
    void SaveTo(string Path);

};

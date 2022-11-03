#include <iostream>
using namespace std;

class Number{
private:
    int n;
public:
    Number(){};
    Number(int num){
        this->n=num;
    }
    void setValue(int num){
        this->n=num;
    }
    bool isPrime(){
        if ((n % 2 == 0 && n > 2)) {
            return false;
        }
        if(n==1){
            return true;
        }
        for(int i=2;i<n/2;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    };
    bool isPerfect(){
        if(n==0 || n==1){
            return true;
        }
        int sum=0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                sum+=i;
            }
        }
        if(sum==n){
            return true;
        }
        return false;
    };
    int getValue(){
        return this->n;
    }
    bool isPalindrome(){
        int num=n;
        int sum=0,mul=1;
        while(num!=0){
            sum=sum*mul+num%10;
            num=num/10;
            mul=10;
        }

        if(sum==n){
            return true;
        }
        return false;
    };
};

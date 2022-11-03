#include<iostream>
#include<string>
using namespace std;

class MathSuit{
private:
    int num;
public:
    MathSuit(){};
    MathSuit(int num){
        this->num=num;
    };
    void setValue(int num){
        this->num=num;
    }
    int getValue(){
        return this->num;
    }
    string Sum_disp(){
        string text="";
        for(int i=1;i<=num;i++){
            if(i==1){
                text+=to_string(i);
            }else{
                text+="+"+to_string(i);
            }
        }
        return text;
    }
    int Sum(){
        int sum=0;
        for(int i=1;i<=num;i++){
            sum+=i;
        }
        return sum;
    }
    string SumOdd_disp(){
        string text="";
        int k=0;
        for(int i=1;i<=num;i++){
            if(i%2!=0){
                if(k==0){
                    text+=to_string(i);
                }else{
                    text+="+"+to_string(i);
                }
                k++;
            }
        }
        return text;
    }
    int SumOdd(){
        int sum=0;
        for(int i=1;i<=num;i++){
            if(i%2!=0){
                sum+=i;
            }
        }
        return sum;
    }
    string SumPower_disp(int pow=2){
        string text="";
        for(int i=1;i<=num;i++){
            if(i==1){
                text+=to_string(i)+"^"+to_string(pow);
            }else{
                text+="+"+to_string(i)+"^"+to_string(pow);
            }
        }
        return text;
    }
    int SumPower(int pow=2){
        int sum=0,power=1;
        for(int i=1;i<=num;i++){
            power=1;
            for(int j=0;j<pow;j++){
                power*=i;
            }
            sum+=power;
        }
        return sum;
    }
    string SumPrime_disp(){
        string text="";
        int k=0;
        Number N;
        for(int i=1;i<=num;i++){
            N.setValue(i);
            if(N.isPrime()){
                if(k==0){
                    text+=to_string(i);
                }else{
                    text+="+"+to_string(i);
                }
                k++;
            }
        }
        return text;
    }
    int SumPrime(){
        int sum=0;
        Number N;
        for(int i=1;i<=num;i++){
            N.setValue(i);
            if(N.isPrime()){
                sum+=i;
            }
        }
        return sum;
    }

};

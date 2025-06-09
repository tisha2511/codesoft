//simple calculator for +,-,/,*
#include<iostream>
using namespace std;
int main(){
int choice;
float op1,op2,res;
cout<<"***WELCOME TO SIMPLE CALCULATOR***"<<endl;
cout<<"enter 1 for addition"<<endl<<"enter 2 for subtraction"<<endl<<"enter 3 for multiplication"<<endl<<"enter 4 for division"<<endl;
cin>>choice;
cout<<"enter first operand"<<endl;
cin>>op1;
cout<<"enter second operand"<<endl;
cin>>op2;
switch(choice){
    case 1:
      res=op1+op2;
      break;  
      case 2:
      res=op1-op2;
      break;  
      case 3:
      res=op1*op2;
      break;  
      case 4:
      res=op1/op2;
      break;  
}
cout<<"RESULT:"<<res;
return 0;
}

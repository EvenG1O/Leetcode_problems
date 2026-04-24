#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>


using  namespace  std;


class MinStack{
    public:

    stack<int> sta,minSta;




    MinStack(){
        
    }


    void push(int val){
        sta.push(val);

        if(minSta.empty() || minSta.top() >= val){
            minSta.push(val);
        }else {
            minSta.push(minSta.top());

        }



    }

    void pop(){
        sta.pop();
        minSta.pop();
    }

    int top()
    {
        return sta.top();
    }

    int getMin(){

        return minSta.top();
    }




};


int main()
{

MinStack minStack;
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
cout<<minStack.getMin()<<endl; // return -3
minStack.pop();
cout<<minStack.top()<<endl;    // return 0
cout<<minStack.getMin()<<endl; // return -2







    return 0;
}
//
//  main.cpp
//  PG2
//
//  Created by 劉俊朋 on 2016/3/9.
//  Copyright © 2016年 劉俊朋. All rights reserved.
//

#include<iostream>
#include<stdexcept>
#include"s1234567_myVec.h"
using namespace std;

class myCompX
{
public:
    myCompX():a(0),b(0){}
    myCompX(int iA, int iB):a(iA),b(iB){}
    int a;	// represent a complex number: a + bi
    int b;
    friend ostream& operator<<(ostream& os, const myCompX& obj)
    {
        os << "(" << obj.a << "+" << obj.b << "i)";
        return os;
    }
};

int main(){
    cout << "TA's Version: s1234567" << endl; //replace this by your studnet ID
    myVec<myCompX> vec1;
    vec1.push_back(myCompX(1,3)); //0
    vec1.push_back(myCompX(2,1)); //1
    vec1.push_back(myCompX(4,6)); //2
    vec1.push_back(myCompX(7,5)); //3
    vec1.push_back(myCompX(3,3)); //4
    vec1.push_back(myCompX(8,8)); //5
    for(size_t i = 0; i < vec1.getSize(); i++)
        cout << vec1[i] << ", ";
    cout << endl;
    //output: (1+3i), (2+1i), (4+6i), (7+5i), (3+3i), (8+8i),
    
    vec1.pop_back();
    cout << "pop_back: ";
    for(size_t i = 0; i < vec1.getSize(); i++)
        cout << vec1[i] << ", ";
    cout << endl;
    //output: pop_back: (1+3i), (2+1i), (4+6i), (7+5i), (3+3i),
    
    vec1.erase(1);
    vec1.erase(2);
    cout << "erase: ";
    for(size_t i = 0; i < vec1.getSize(); i++)
        cout << vec1[i] << ", ";
    cout << endl;
    ////output: erase: (1+3i), (4+6i), (3+3i),
    
    vec1.insert(1, myCompX(0,0));
    vec1.insert(3, myCompX(0,3));
    cout << "insert: ";
    for(size_t i = 0; i< vec1.getSize(); i++)
        cout << vec1[i] << ", ";
    cout << endl;
    //output: insert: (1+3i), (0+0i), (4+6i), (0+3i), (3+3i),
    
    vec1.clear();
    cout << "clear: ";
    for(size_t i = 0; i < vec1.getSize(); i++)
        cout << vec1[i] << ", ";
    cout << endl;
    //output: clear:
    
    myStr test("xxxx"), test2("yyyy");
    cout << "test: " << test << endl;
    cout << "test2[...]: " ;
    for(unsigned int i = 0; i < test2.getSize(); i++)
        cout << test2[i] << ", ";
    cout << endl;
    cout << "test+test2: " << test.append(test2) << endl;
    //output:
    //test: xxxx
    //test2[...]: y, y, y, y,
    //test+test2: xxxxyyyy
    
    try
    {
        cout << "Value 99: " << vec1[99] << endl; // index value is out-of-range
    }
    catch (const out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << endl;
    }
    //output:
    //Out of Range error: incorrect index in operator[]
    
    int n;
    cin >> n; 
    
    return 0;
}
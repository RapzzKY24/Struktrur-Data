#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack* s = new Stack;  
    createStack(s);

    /*
    *
    * push biasa untuk nomor 1
    * 
    */
    push(s,3);
    push(s,4);
    push(s,8);
    pop(s);
    push(s,2);
    push(s,3);
    pop(s);
    push(s,9);
    printInfo(*s);
    cout << "Balik stack: " << endl;
    balikStack(s);
    printInfo(*s);
   /*
   *
   * push ascending untuk nomor 2
   * 
   */
    pushAscending(s, 3);
    pushAscending(s, 4);
    pushAscending(s, 8);
    pushAscending(s, 2);
    pushAscending(s, 3);
    pushAscending(s, 9);
    printInfo(*s);
    cout << "Balik stack: " << endl;
    balikStack(s);
    printInfo(*s);

    /*
    *
    * input dengan fungsi getinput(3)
    *
    */
    getInputStream(s);
    printInfo(*s);
    cout << "Balik stack: " << endl;
    balikStack(s);
    printInfo(*s);
    
    delete s;  
    return 0;
}
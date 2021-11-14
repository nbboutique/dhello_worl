#include <iostream>
#include <cassert>
#include <stack>
#include <cppunit/XmlOtputter.h>
#include <ostream>

template <typename T>
class New_Stack{
private:

    const uint16_t max_amount;

    uint16_t stack_size;

    T* stack_array;
public:
    explicit New_Stack(const uint16_t max_amount) : max_amount(max_amount) {
        stack_array = new T[max_amount];
        stack_size = 0;
    }

    ~New_Stack(){
        delete[] stack_array;
    }

//    New_Stack(const New_Stack&);
//    New_Stack& operator=(const New_Stack&);

    bool push(const T _push){
        if (full()) {
            return false;
        }
        stack_array[stack_size++] = _push;
        return true;
    }

    T top() const {
        return stack_array[stack_size-1];
    }

    uint16_t size() const {
        return stack_size;
    }

    bool empty() const {
        return stack_size == 0;
    }

    bool full() const {
        return stack_size == max_amount;
    }

    T pop(){
        if (empty()) {
            return {};
        }
        std::cout<<"Element for deleting is: ";
        T del_elem = stack_array[stack_size--];
        std::cout<< del_elem;
        std::cout<<"\n";
        return del_elem;
    }

    void stack_all(int size) {
        for(int i = 0; i<size; i++){
            std::cout<<stack_array[i];
            std::cout<<" ";
        }
    }

};

void TestOneElement(){
    New_Stack<std::string> new_stack(1);
    new_stack.push("one");
    assert(new_stack.size() == 1);
    std::cout<<"TEST1--------------OK\n";
    ofstream xmlFileOut("cpptestresults.xml");
    XmlOutputter xmlOut(&result, xmlFileOut);
    xmlOut.write();
}

void TestEmptyStack(){
    New_Stack<std::string> new_stack(1);
    new_stack.pop();
    assert(new_stack.size()== 0);
    std::cout<<"Test2-------OK\n";
    ofstream xmlFileOut("cpptestresults.xml");
    XmlOutputter xmlOut(&result, xmlFileOut);
    xmlOut.write();
}
void TestTopElement(){
    New_Stack<std::string> new_stack (5);
    assert(new_stack.size()==0);
    new_stack.push("one");
    assert(new_stack.size()==1);
    new_stack.push("two");
    assert(new_stack.size()==2);
    new_stack.push("three");
    assert( new_stack.top()== "three");
    std::cout<<"Test3-------OK\n";
    ofstream xmlFileOut("cpptestresults.xml");
    XmlOutputter xmlOut(&result, xmlFileOut);
    xmlOut.write();
}
void TestSize(){

    New_Stack<std::string> new_stack (5);
    assert(new_stack.size()==0);
    new_stack.push("one");
    assert(new_stack.size()==1);
    new_stack.push("two");
    assert(new_stack.size()==2);
    new_stack.push("three");
    assert(new_stack.size()==3);
    new_stack.pop();
    assert(new_stack.size()==2);
    std::cout<<"Test4-------OK\n";
    ofstream xmlFileOut("cpptestresults.xml");
    XmlOutputter xmlOut(&result, xmlFileOut);
    xmlOut.write();
}


int main() {
    TestOneElement();
    TestEmptyStack();
    TestTopElement();
    TestSize();


//    std::cout<<"Enter max size of your stack: "<<std::endl;
//    uint16_t enter;
//    bool menu = true;
//    std::cin>>enter;
//    New_Stack<std::string> new_stack = enter;
//    int command;
//    std::cout <<"========Welcome to the menu========\n";
//    std::cout << "Press 1 to write a new record to a stack (Push)\n"
//                 "Press 2 to delete a record from a stack (Pop)\n"
//                 "Press 3 to find a size of stack (Size)\n"
//                 "Press 4 to find first(last) element of stack (Top)\n"
//                 "Press 5 to output your stack (All)\n"
//                 "Press 6 to quit\n\n";
//    while(menu){
//        std::cin>>command;
//        std::string var;
//        size_t new_size = new_stack.size();
//        switch (command)
//        {
//            case 1:
//                if(new_size == enter){
//                    std::cout<<"The stack is full\n";
//                    std::cout <<"---------------------------\n";
//                    std::cout<<"Enter your next command"<<std::endl;
//                }
//                else{
//                    std::cout<<"Enter a string ";
//                    std::cin>>var;
//                    new_stack.push(var, enter);
//                    std::cout<<"Your string is added"<<std::endl;
//                    std::cout <<"---------------------------\n";
//                    std::cout<<"Enter your next command"<<std::endl;
//                }
//
//                break;
//            case 2:
//                new_stack.pop();
//                std::cout<<"Your last element is deleted"<<std::endl;
//                std::cout <<"---------------------------\n";
//                std::cout<<"Enter your next command"<<std::endl;
//                break;
//            case 3:
//                std::cout<<"The size of stack is: ";
//                std::cout<<new_stack.size();
//                std::cout <<"\n---------------------------\n";
//                std::cout<<"Enter your next command"<<std::endl;
//                break;
//            case 4:
//                std::cout<<"Your last element is: "<<std::endl;
//                std::cout<<new_stack.top();
//                std::cout <<"\n---------------------------\n";
//                std::cout<<"Enter your next command"<<std::endl;
//                break;
//            case 5:
//                 std::cout<<"Your stack is: "<<std::endl;
//                 new_stack.size();
//                 new_stack.stack_all(new_size);
//                 std::cout <<"\n---------------------------\n";
//                 std::cout<<"Enter your next command"<<std::endl;
//                 break;
//            case 6:
//                menu = false;
//                break;
//            default:
//                std::cout<< "That is not the command.\n";
//                menu = false;
//
//        }
//    }
//

    return 0;
}

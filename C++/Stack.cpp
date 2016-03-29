#include<iostream>
#include<stdlib.h>
struct data{
struct data *pre;
int index;
int number;
};

int tmp;
struct data *tmp1;

class my_stack{
public:
    my_stack();
    void push(int);
    int pop(void);
    int size(void);
    int peek(void);
    bool empty(void);
private:
    struct data *current;
};
my_stack::my_stack(){
static struct data start;
*current=start;
start.index=0;
start.pre=NULL;
}
inline int my_stack::peek(void){
return current->number;
}
inline int my_stack::size(void){
return current->index;
}
inline bool my_stack::empty(void){
return !(current->index);
}
void my_stack::push(int a){
static struct data c;
c.pre=current;
c.number=a;
c.index=current->index+1;
}
int my_stack::pop(void){
if(!empty()){
tmp=current->number;
tmp1=current;
free(current);
current=tmp1;
return tmp;
}
std::cout << "Error!!The Stack is already empty!" << std::endl;
}


int main(){
using namespace std;
my_stack gw;
gw.pop;







}

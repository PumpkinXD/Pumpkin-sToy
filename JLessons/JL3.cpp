//JL3==exceptions in java
#include <exception>
#include <stdexcept>
#include <iostream>
#include <csignal>//for signal
#include <csetjmp>//for longjmp


class MyE : public std::exception
{
private:
    /* data */
public:

    const char* what()const throw()  override{return "wdnmd\n";}
    MyE()=default;


};
std::jmp_buf jmpenv;
void FPE_Handler(int signal)
{
    std::cerr<<"caught SIGFPE\("<<signal<<"\)\n";
    std::longjmp(jmpenv,signal);
    //throw MyE();
     //siginterrupt(SIGFPE, 1);//https://www.mkssoftware.com/docs/man3/siginterrupt.3.asp  https://stackoverflow.com/a/14906044
}




int main(int argc, char const *argv[])
{
    try{

        throw MyE();
    }
    catch(std::exception& e){

        std::cerr<<e.what();
    }
 double c=0;
 double d=0;
 c=c/d;
 std::cerr<<"c="<<c<<'\n';
std::signal(SIGFPE,FPE_Handler); 
 //std::signal(SIGFPE,SIG_IGN);

 int a=0;
 int b=0;
if(!setjmp(jmpenv))
a=a/b;


 

 //std::raise(SIGFPE);
 std::cout<<"all exception tests done\n";


    return 0;
}

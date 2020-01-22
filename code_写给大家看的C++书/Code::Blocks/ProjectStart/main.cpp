#include "person.h"

int main()
{

    CPerson p;
    p.setName("鲁门主");
    p.setAge(28);
    p.setIndex(511);
    p.setSalary(12000);
    p.show();
    //system("gedit");
    /*
    int a[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};
    int *p;
    p=a[0];
    //cout<<"add:"<<p<<endl;
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        cout<<"address:";
        cout<<a[i];
        cout<<" is ";
        cout<<*p++<<endl;
    }

    cout << "Done!" << endl;
    return 0;
    */
}

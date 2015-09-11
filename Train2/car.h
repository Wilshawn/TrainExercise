#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

class car
{
public:
       car(){next=NULL;}
       car(int d, int i){des=d, id=i, next=NULL;}

       void setid(int d){des=d;}
       int getdes(){return des;}
       int getid() {return id;}

       void setnext(car * n){next = n;}
       car * getnext(){return next;}
       void display(){cout << "Car " << getid() <<
                           " destination is " << getdes()
                           << " units" << endl;}

private:
        int des;
        int id;
        car * next;


};



#endif // CAR_H_INCLUDED

#include <cmath>
#include <iostream>
using std::ostream;
using namespace std;
#ifndef COVIDCASE_H
#define COVIDCASE_H


// TODO: your code  goes here
class CovidCase{

    private:
        float latitude; 
        float longitude;
        string name;
        int age;
        int positiveT;


    public:
    
    friend ostream& operator<<(ostream& os, const CovidCase& patient);

    CovidCase(float lat , float lon, string n, int a, int p) 
            {
                latitude = lat;
                longitude = lon;
                name = n ;
                age = a;
                positiveT = p ;
            }


    float distanceTo(const CovidCase& patient)
    {
    float pi = 4*atan(1);
    float dlon = pi*(longitude -patient.longitude)/180;
    float dlat = pi*(latitude - patient.latitude)/180;
    float a = pow((sin(dlat/2)), 2) +cos(latitude*pi/180)*cos(patient.latitude*pi/180)*pow((sin(dlon/2)),2);
    float c = 2*atan2(sqrt(a), sqrt(1-a));
    float distance = 3960*c;
    return distance;
    } 

};

ostream& operator<<(ostream&os, const CovidCase& patient)
{
os<<"{"<<patient.latitude<<", "<<patient.longitude<<", \""<<patient.name<<"\", "<<patient.age<<", "<<patient.positiveT<<"}";
return os;
}



// don't write any code below this line

#endif

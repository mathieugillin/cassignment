#include <string>
using namespace std;
#include <cmath>
#include <iostream>
using std::ostream;
#include <sstream>
#include <bits/stdc++.h>

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
     bool operator==(const CovidCase& covid) const;
        CovidCase(string input){
            input.erase(input.begin(),input.end());
            vector<string> v;
 
            stringstream ss(input);
 
            while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
            }
            
            string sLatitude = v[0];
            string sLongitude= v[1];
            string sName = v[2];
            string Sage= v[3];
            string sPositiveT= v[4];

            latitude = std::stof(sLatitude); 
            longitude = std::stof(sLongitude); 
            name = sName;
            age = stoi(Sage); 
            positiveT= stoi(sPositiveT); 
        }
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
        float getLatitude(){
        return latitude;
        }
        float getLongitude(){
        return longitude;
        }
        string getName(){
        return name;
        }
        int getAge(){
        return age ;
        }
        int getTime(){
        return positiveT ;
        }

};

ostream& operator<<(ostream&os, const CovidCase& patient)
{
os<<"{"<<patient.latitude<<", "<<patient.longitude<<", \""<<patient.name<<"\", "<<patient.age<<", "<<patient.positiveT<<"}";
return os;
}

// overload operator == that returns true if the objects are equal i.e values for corresponding fields for both the objects are equal else return false
bool CovidCase::operator==(const CovidCase& covid) const
{
return(longitude == covid.longitude && latitude == covid.latitude &&
name == covid.name && age == covid.age && positiveT == covid.positiveT);
}

// don't write any code below this line

#endif



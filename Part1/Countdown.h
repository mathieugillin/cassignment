#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:
int toss = 0;
#define MAX_STACK 100
float _stack[MAX_STACK];

float Pop(){
	float t = _stack[toss];
	toss--;
	return t;
}

bool Full(){
	return toss >= MAX_STACK - 1;
}

void Push(float val){
	if (Full()){
		return;
	}
	_stack[toss] = val;
	toss++;
	
}

bool Empty(){
	return toss == 0;
}

bool IsOp(char ch){
	switch (ch){
		case '*':
		case '+':
		case '/':
		case '-':
			return true;
		default:
			return false;
	}
}

double evaluateCountdown(string expres){
	int i = 0;
	float v1, v2, ret;
	v1 = ret = v2 = 0.0;

	string to = "";

	while ((unsigned)i < expres.length()){
		while (isspace(expres[i])){
			i++;
		}
		if (isdigit(expres[i]) || expres[i] == '.'){
			while (isdigit(expres[i]) || expres[i] == '.'){
				to += expres[i];
				i++;
			}
			Push(atof(to.c_str()));
			to = "";
		}
		else if (IsOp(expres[i])){
			if (expres[i]=='+'){
				v1 = Pop();
				v2 = Pop();
				ret = v1 + v2;
			}
			if (expres[i]=='/'){
				v1 = Pop();
				v2 = Pop();
				ret = v2 / v1;
			}
			if (expres[i]=='-'){
				v1 = Pop();
				v2 = Pop();
				ret = v2 - v1;
			}
			if (expres[i]=='*'){
				v1 = Pop();
				v2 = Pop();
				ret = v1 * v2;
			}
			i++;
			Push(ret);
		}
		else{
			break;
		}
	}
	return Pop();
}


// Do not edit below this line


#endif

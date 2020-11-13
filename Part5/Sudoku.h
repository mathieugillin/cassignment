

#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
using std::sqrt;
#include <vector>
using std::vector;
#include <set>
using std::set;
using namespace std;



// TODO: Your Sudoku class goes here:
class Sudoku : public Searchable {

private:
	int size;
	vector< vector< set<int> > > board;
	vector< vector<bool> > sVisi;
	vector< vector<bool> > dVisi;
	vector< vector<bool> > tallied;
	int singles;

	bool clearRow(const size_t & rowIn, const size_t & colIn, const int & value) {
		for (size_t col = 0; col < (unsigned)size; ++col) {
			if (col != colIn) {
				board[rowIn][col].erase(value);
				if (board[rowIn][col].size() == 0) 
					return false;
				if (board[rowIn][col].size() == 1 && tallied[rowIn][col] == false) {
					tallied[rowIn][col] = true;
					++singles;
				}
			}
		}
		return true;
	}

	bool clearCol(const size_t & rowIn, const size_t & colIn, const int & value) {
		for (size_t row = 0; row < (unsigned)size; ++row) {
			if (row != rowIn) {
				board[row][colIn].erase(value);
				if (board[row][colIn].size() == 0) 
					return false;
				if (board[row][colIn].size() == 1 && tallied[row][colIn] == false) {
					tallied[row][colIn] = true;
					++singles;
				}
			}
		}
		return true;
	}	

	bool clearBox(const size_t & rowIn, const size_t & colIn, const int & value) {
    	int y = sqrt(size) * floor(rowIn/sqrt(size));
    	int x = sqrt(size) * floor(colIn/sqrt(size)); 

		for (size_t i = y; i < y + sqrt(size); ++i) {
			for (size_t j = x; j < x + sqrt(size); ++j) {
				
				if (i == rowIn && j == colIn) { continue; }
				else { 
					board[i][j].erase(value); 
					if (board[i][j].size() == 0)
						return false;
					if (board[i][j].size() == 1 && tallied[i][j] == false) {
						tallied[i][j] = true;
						++singles;
					}	
				}
			}
		}
		return true;
	}

public:
	virtual vector< unique_ptr<Searchable> > successors() const override {
		vector< unique_ptr<Searchable> > success;

		for (size_t x = 0; x < size; ++x) {
		for (size_t y = 0; y < size; ++y) {
		//		
		if (board[x][y].size() > 1) {
			//
		for (const auto & val : board[x][y]) {
		bool isSuccess = sudCopy->setSquare(x, y, val);
		Sudoku * sudCopy = new Sudoku(*this);
		if (isSuccess) {
		success.push_back(unique_ptr<Searchable>(sudCopy));
		} else {
		delete sudCopy;
		}
		//
		}
		if ((success.size() == 1) && !(success[0]->isSolution())) {
		return success[0]->successors();
		}
		return success;
		}
		//
		}
		//	
		}
		//
		return success;
	}	

	int getSquare(const int & x, const int & y) const {
		//
		if (board[x][y].size() == 1) {
			return *board[x][y].begin();
		}
		//
		return -1;
	}

	virtual bool isSolution() const override {
		size_t count = 0;
		for (size_t x = 0; x < (unsigned)size; ++x) {
for (size_t y = 0; y < (unsigned)size; ++y) {
if (board[x][y].size() == 1) {
//
++count;
}
}	
}
return count == (size*size);
}

///
	virtual void write(ostream & o) const override {
		for (size_t x = 0; x < (unsigned)size; ++x) {
		for (size_t y = 0; y < (unsigned)size; ++y) {
		//		
		for (const int & val : board[x][y]) {
		cout<< o << val << " ";
		}
		cout<< o << endl;
		}	
		cout<< o << endl;
		}
	}

	virtual int heuristicValue() const override {
		return (size*size) - singles;
	}

	Sudoku(const int & sizeIn) 
	: size (sizeIn) {
		dVisi.resize(size);
		board.resize(size);
		sVisi.resize(size);
		tallied.resize(size);
//
		for (size_t x = 0; x < (unsigned)size; ++x) {
        	dVisi[x] = vector<bool>(size);
			board[x] = vector< set<int> >(size);
			sVisi[x] = vector<bool>(size);
        	tallied[x] = vector<bool>(size);
    	}

    	set<int> initSet;
		//
    	for (size_t j = 1; j < (unsigned)size+1; ++j) {
    		initSet.insert(j);
    	}

    	for (size_t row = 0; row < (unsigned)size; ++row) {
        	for (size_t col = 0; col < (unsigned)size; ++col) {
            	sVisi[row][col] = false;
            	dVisi[row][col] = false;
				board[row][col] = initSet;
            	tallied[row][col] = false;
        	}
    	}	
	}

	bool setSquare(const int & row, const int & col, const int & value) {
		board[row][col] = {value};
		size_t prev = 0;
    	size_t current = 0;
		tallied[row][col] = true;
		++singles;
    

		while (true) {
for (size_t x = 0; x < (unsigned)size; ++x) {
for (size_t y = 0; y < (unsigned)size; ++y) {
//
if (board[x][y].size()==0) { return false; }
//
if (board[x][y].size()==1) {
if (sVisi[x][y]==true) {
continue;
}
++current;
sVisi[x][y]=true;
						if(!clearCol(x, y, *board[x][y].begin())){ return false ;}
						if(!clearBox(x, y, *board[x][y].begin())){ return false ;}
						if(!clearRow(x, y, *board[x][y].begin())){ return false ;}
					}

					if (board[x][y].size()==2) {
						if (dVisi[x][y]==true) {
							continue;
						}
						++current;

for (size_t b = 0; b < (unsigned)size; ++b) {
if ((y != b) && (board[x][y] == board[x][z])) {
dVisi[x][y]=true;
auto itr = board[x][y].begin();
								dVisi[x][b] = true;
								size_t first = *itr;
								++itr;
								size_t second = *itr;
								for (size_t col = 0; col < (unsigned)size; ++col) {
									if ((col != y) && (col != z)) {
										board[x][col].erase(first);
										if (board[x][col].size() == 0)
											{return false;}
										board[x][col].erase(second);
										if (board[x][col].size() == 1 && tallied[x][col] == false) {
											tallied[x][col] = true;
											++singles;
										if (board[x][col].size() == 0)
											{return false;}
										}	
									}
								}
								break;
							}
						}

						for (size_t z = 0; z < (unsigned)size; ++z) {
							if ((x != z) && (board[x][y] == board[z][y])) {
								dVisi[x][y] = true;
								dVisi[z][y] = true;
								auto itr = board[x][y].begin();
								size_t first = *itr;
								++itr;
								size_t second = *itr;
								for (size_t r = 0; r < (unsigned)size; ++r) {
									if ((r != x) && (r != z)) {
										board[r][y].erase(first);
										if (board[r][y].size() == 0)
											{return false;}
										board[r][y].erase(second);
										if (board[r][y].size() == 1 && tallied[r][y] == false) {
											tallied[r][y] = true;
											++singles;
										if (board[r][y].size() == 0)
											{return false;}
										}	
									}
								}
								break;
							}
						}
						int foundX = -1;
    					int foundY = -1;
						size_t rowStart = sqrt(size) * floor(x/sqrt(size));
    					size_t colStart = sqrt(size) * floor(y/sqrt(size)); 
/////
						for (size_t i=rowStart; i < (rowStart + sqrt(size)); ++i) {
							for (size_t j=colStart; j < (colStart + sqrt(size)); ++j) {
								if ( (i != x) && (j != y) && (board[x][y] == board[i][j]) ) {
									foundY = j;
									foundX = i;
									break;
								}
							}
						}
////
						dVisi[x][y]=true;
						if (foundX>-1) {dVisi[foundX][foundY]=true;}

						auto boxItr=board[x][y].begin();
						size_t second=*boxItr;
						size_t first=*boxItr;
						++boxItr;
						///
						///
						for (size_t i = rowStart; i < (rowStart + sqrt(size)); ++i) {
							for (size_t j = colStart; j < (colStart + sqrt(size)); ++j) {
								if ( ((unsigned)foundX > (unsigned)-1) && ((unsigned)i != (unsigned)x) && ((unsigned)i != (unsigned)foundX) && ((unsigned)j != (unsigned)y) && ((unsigned)j != (unsigned)foundY) ) {
									board[i][j].erase(second);
									board[i][j].erase(first);
									if (board[i][j].size() == 1 && tallied[i][j] == false) {
											++singles;
											tallied[i][j] = true;
											
}	
}
}
}
}
}
}
			
			if (prev == current) { break; }
      		prev = current;
      		current = 0;
		}
		
		return true;
	}

};

#endif

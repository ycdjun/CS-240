#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include <cstring>

class Stack {
	private:
	int stk[16];
	int stkInd =0;
	
	public:
		void push(int in){
			if(stkInd == 16){
				std::cout<< "Cannot add to stack. Stack is full" << std::endl;
				std::exit(1);
			}
			else{
				stk[stkInd] = in;
				stkInd++;
			}
		}
		
		int pop(){
			if(stkInd > 0){
				stkInd--;
				return stk[stkInd];
			}
			std::cout<< "Cannot pop. Stack is empty" << std::endl;
			std::exit(1);
		}
		
		int size() {
			return stkInd;
		}	
};

struct DelimMap {
	int delim;
	int encoding;
};

int getDelim(int c){
	DelimMap delimEncodings[] {
    {'(', 1},
	{')', -1},
	{'[', 2},
	{']', -2},
	{'<', 3},
	{'>', -3},
	{'{', 4},
	{'}', -4}
    };
    
    
    for(auto i = 0; i < 8; i++){
    	if(c == delimEncodings[i].delim){
    		return delimEncodings[i].encoding;
    	}
    }
    return -5;
}


int main(int argc, const char * argv[]){
	Stack s;
	if(argc < 3){
		std::cerr << "Invalid Number of Args" << std::endl;
		std::exit(1);
	}
	for(int i = 1; i < argc; i++){
		if(strlen(argv[i]) != 1){
			std::cout << "Input delimiter " << argv[i] << " not of length 1 " << std::endl;
			std::exit(1);
		}
		int delim = getDelim(argv[i][0]);
		
		if(delim == -5){
			std::cout << "Invalid delimeter " << argv[i][0] << " at argument " << i << std::endl;
			std::exit(1);
		}
		
		if(delim > 0){
			s.push(argv[i][0]);
		}
		else{
			int closing = s.pop();
			int checkClose = getDelim(closing);
			if(checkClose != -1 * delim){
				std::cout << "Unbalanced delimiter at argument " << i << std::endl;
				std::exit(1);
			}
		}
		
	}
	if(s.size() != 0){
		std::cout << "Unbalanced final stack of delimiters" << std::endl;
		std::exit(1);
	}
	return 0;
	

}










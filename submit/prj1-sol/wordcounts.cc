#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

typedef unsigned Count;
typedef std::pair<std::string, Count> WordCount;

bool wordCountCompare(WordCount w1, WordCount w2){
	if (w1.second == w2.second){
		if(w1.first.length() > w2.first.length()){
			for(int i = 0; i < w2.first.length(); i++){
				if(w1.first.at(i) != w2.first.at(i)){
					return w1.first.at(i) < w2.first.at(i);
				}
			}
		}
		else{
			for(int i = 0; i < w1.first.length(); i++){
				if(w1.first.at(i) != w2.first.at(i)){
					return w1.first.at(i) < w2.first.at(i);
				}
			}
		}
	}
	return w1.second > w2.second;
}

std::string getFixedString(std::string str){
	std::string word = str;
	for(int i = 0; i < word.length(); i++){
		if(word.at(i) > 64 && word.at(i) < 91){
			word = word.substr(0,i) + (char)(word.at(i) + 32) + word.substr(i + 1, word.length() - i - 1); //uppercase to lowercase
		}
		else if(word.at(i) < 97 || word.at(i) > 122){ //remove extra characters
			word = word.substr(0,i) + word.substr(i + 1, word.length() - i - 1);
			i--;
		}
	}
	
	return word;
}


int checkInput(std::string args){
	int check = std::stoi(args);
	if(std::to_string(check).length() != args.length()) throw std::invalid_argument("");
	return check;
}

int main(int argc, char * argv[]){
	auto args = std::vector<std::string>(&argv[0], &argv[argc]);
	
	if(argc <4){
		std::cout << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << std::endl;
		return 1;
	}
	
	
	for(int i = 1; i < argc -1; i++){
		int input = 0;
		try{
			input = checkInput(args[i]);
		}
		catch(std::invalid_argument& e){
			if(i == 1){
				std::cout << "bad integer value \"" << args[i] << "\" for MAX_N_OUT" << std::endl;
			}
			else if(i == 2){
				std::cout << "bad integer value \"" << args[i] << "\" for MIN_WORD_LEN" << std::endl;
			}
			else{
				std::cout << "bad integer value \"" << args[i] << "\" for MAX_WORD_LEN" << std::endl;
			}
			return 1;
		}
	}
	if(args[2] > args[3]){
		std::cout << "MIN_WORD_LEN " << args[2] << " is greater than MAX_WORD_LEN " << args[3] << std::endl;
		return 1;
	}
	
	int MAX_N_OUT = std::stoi(args[1]);
	int MIN_WORD_LEN = std::stoi(args[2]);
	int MAX_WORD_LEN = std::stoi(args[3]);
	std::string file = args[4];
	
	
	std::unordered_map<std::string, Count> map;
	
	
	std::ifstream in(file);
	
	if(in.good()){
		while(in.good()){
			std::string w;
			in >> w;
			
			std::string transformedWord = getFixedString(w);
			
			Count& count = map[transformedWord];
			count += 1;
			
		}
	}
	else{
		std::cout << "cannot read " << file << std::endl;
		return 1;
	}
	
	auto wordCounts = std::vector<WordCount>(map.begin(), map.end());
	std::sort(wordCounts.begin(), wordCounts.end(),wordCountCompare);
	
	int total = 0;
	for(auto w : wordCounts){
		if (MAX_N_OUT > total) {
			if(w.first.length() >= MIN_WORD_LEN && w.first.length() <= MAX_WORD_LEN){
				std::cout << w.first << ": " << w.second << std::endl;
				total++;
			}
		}
	}
	
	return 0;
	 
}

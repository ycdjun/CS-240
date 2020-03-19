#include "arrayseq.hh"
#include "command.hh"
#include "dlinkseq.hh"
#include "seq.hh"

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>


using TestType = int;

void readInts(std::string fileName, Seq<TestType>* seq){
	std::ifstream in(fileName);
	while(in.good()){
		std::string i;
		in >> i;
		if(i != ""){
			seq->push(std::stoi(i));
    	}
  	}
}

void outputData(Seq<TestType>* seq){
	ConstIterPtr<TestType> startPoint = seq->cbegin();
	ConstIterPtr<TestType> endPoint = seq->cend();
	ConstIter<TestType>& end = *endPoint;
	
	for(ConstIter<TestType>& start = *startPoint; start; ++start){
		std::cout << *start << std::endl << *end << std::endl;
		--end;
	}
	
}

int main(int argc, char* argv[]){
	std::string fileName;
	SeqPtr<TestType> seqPtr1;
	
	if(argc < 2) {
		std::cerr << "usage: " << argv[0] << " [-a] INTS_FILE_PATH" << std::endl;
		std::exit(1);
	}
	else if(argc == 3){
		if(strcmp(argv[1], "-a") != 0){
			std::cerr << "usage: " << argv[0] << " [-a] INTS_FILE_PATH" << std::endl;
			std::exit(1);
		}
		else{
			fileName = argv[2];
			seqPtr1 = ArraySeq<TestType>::make();
		}
	}
	else{
		fileName = argv[1];
		seqPtr1 = DLinkSeq<TestType>::make();
	}
	
	Seq<TestType>* rawP = seqPtr1.get();
	readInts(fileName, rawP);
	outputData(rawP);
} 



	
	

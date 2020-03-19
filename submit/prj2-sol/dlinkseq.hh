#ifndef DLINK_SEQ_HH_
#define DLINK_SEQ_HH_

#include "seq.hh"

#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

template <typename E> class DLinkSeqConstIter;

template<typename E> 

struct Dlink 
{
	struct Dlink *prev;
	struct Dlink *next;
	E value;
};

template <typename E>
class DLinkSeq : public Seq<E> {
private:

	Dlink<E>* head;
	Dlink<E>* tail;
	int currSize;
  
	friend class DLinkSeqConstIter<E>;

	enum class Private { TAG, DEFAULT_SIZE = 8 };

public:

	DLinkSeq(Private tag){
		currSize = 0;
		head = new Dlink<E>;
		head->prev = nullptr;
		head->next = nullptr;
		head->value = 0;
		tail = head;
		
	}

	static SeqPtr<E> make() {
		return std::make_unique<DLinkSeq<E>>(Private::TAG);
	}
	
	~DLinkSeq(){
		clear();
		delete head;
	}
	
	void clear(){
		while(currSize != 0){
			shift();
		}
	}
	
	void unshift(const E& item){
		if(currSize > 0){
			head->prev = new Dlink<E>;
			head->prev->prev = nullptr;
			head->prev->next = head;
			head = head->prev;
		}
		head->value = item;
		currSize++;
	}

	
	void push(const E& item){
		if(currSize > 0){
			tail->next = new Dlink<E>;
			tail->next->prev = tail;
			tail->next->next = nullptr;
			tail = tail->next;
		}
		tail->value = item;
		currSize++;
	}
	
	E shift() {
		if(currSize == 0){
			std::cerr << "Error: No node to shift" << std::endl;
			exit(0);
		}
		else if(head->next == nullptr && head->prev == nullptr){
			E retVal = head->value;
			currSize = 0;
			return retVal;
		}
		Dlink<E>* temp = head;
		head = head->next;
		head->prev = nullptr;
		E retVal = temp->value;
		
		delete temp;
		
		currSize--;
		
		return retVal;
	}
	
	E pop() {
		if(currSize == 0){
			std::cerr << "Error: No node to pop" << std::endl;
			exit(0);
		}
		else if(tail->next == nullptr && tail->prev == nullptr){
			E retVal = tail->value;
			currSize = 0;
			return retVal;
		}
		Dlink<E>* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		E retVal = temp->value;
		
		delete temp;
		
		currSize--;
		
		return retVal;
	}
	
	int size() const{
		return currSize;
	}
	
	ConstIterPtr<E> cbegin() const {
    	const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
    	return std::make_unique<DLinkSeqConstIter<E>>(constThis);
  	}
  	
	virtual ConstIterPtr<E> cend() const {
		const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
		return std::make_unique<DLinkSeqConstIter<E>>(constThis,false);
	}
};

template <typename E>
class DLinkSeqConstIter : public ConstIter<E>{

private:

	const DLinkSeq<E>* const seq;
	Dlink<E>* currNode;
	
public:

	DLinkSeqConstIter(const DLinkSeq<E>* const seq, bool isHead=true)
	:seq(seq)
	{
		currNode = seq->head;
		if(!isHead){
			while(currNode->next != nullptr){
				currNode = currNode->next;
			}
		}
	}
		
	DLinkSeqConstIter& operator++(){
		currNode = currNode->next;
		return *this;
	}
	
	DLinkSeqConstIter& operator--(){
		currNode = currNode->prev;
		return *this;
	}
	
	virtual operator bool(){
		return (currNode != nullptr && seq->currSize > 0); 
	}
	
	const E& operator*(){
		return currNode->value;
	}
	
	const E* operator->(){
		return &currNode->value;
	}

	
};
	
#endif 



	
	

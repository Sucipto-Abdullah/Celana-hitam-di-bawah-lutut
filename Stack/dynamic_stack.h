#ifndef stack_H
#define stack_H

#include <iostream>

typedef char infotype;
typedef struct Element_Stack *address;

struct Element_Stack{
	infotype info;
	int index;
	address next;
};

address alokasi(infotype info){
	address s;
	s = new Element_Stack;
	s->info = info;
	s->next = NULL;
	s->index = 0;
	return s;
}

struct stack{
	address top;

	void create(){
		top = NULL;

	}
	void push(infotype nilai){
		address nilai_baru = alokasi(nilai);
		if(top == NULL){
			top = nilai_baru;
			nilai_baru->index = 1;
		}
		else{
			nilai_baru->next = top;
			top = nilai_baru;
			nilai_baru->index = nilai_baru->next->index + 1;
		}
	}
	void pop(){
		if(top != NULL){
			address target = top;
			top = top->next;
			target->next = NULL;
			delete target;
		}

	}
	address get_address(infotype nilai){
		address index = top;
		while(index->info != nilai && index != NULL){
			index = index->next;
		}
		return index;
	}
	
	void read(){
		address index = top;
		while(index != NULL){
			if(index->next != NULL){
				std::cout << index->info << ", ";
			}else{
				std::cout << index->info << " ";
			}
			index = index->next;
		}
		std::cout << "\n";
	}
};

#endif

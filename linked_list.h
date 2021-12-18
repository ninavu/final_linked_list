#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <cstddef>
#include <iostream>

using namespace std;

template <typename T> 
struct Node{
	T data;
	Node *prev;
	Node *next;
};

template <typename T> 
class LinkedList {

	public:
		LinkedList() {
			head = nullptr;
			tail = nullptr;
			numItems = 0;
		}
		~LinkedList(){
			for (unsigned int i = 0; i < numItems; i++){
				
			}
		}
		
		void push_back(T item){
			Node<T> *n = new Node<T>;
			n->data = item;
			numItems++;
			

			if(head == nullptr){
				head = n;
				tail = n;
				return;
			}

			tail->next = n;
			n->prev = tail;
			tail = n;	
		}


		void push_front(T item){
			Node<T> *n = new Node<T>;
			n->data = item;
			numItems++;

			if(head == nullptr){
				head = n;
				tail = n;
				return;
			}

			head->prev = n;
			n->next = head;
			head = n;
		}
		
		
		T at(size_t idx){
			if(idx >= numItems){
				throw std::invalid_argument("List index out of range: " + std::to_string(idx));
			}

			Node<T> *n = get_node(idx);
			return n->data;
		}

		void insert(size_t pos, T item){
			if(pos >= numItems){
				throw std::invalid_argument("List index out of range: " + std::to_string(pos));
			}	
			
			Node<T> *n = new Node<T>;
			Node<T> *cur = head;   
			Node<T> *pre;

			if(head == nullptr){ 
				head = n; 
				
			} else if (head != nullptr && pos == 0){
				n->next = head;
				head = n;
				
			} else {
			
				for (int i = 0; i < pos; i++){
					pre = cur;   		//set up the pre node as the cur node
					cur = cur->next;
				}
				numItems++;
				n->next = cur;  			//new node item is between cur and pre
				pre->next = n;
			}
			
		}

		size_t size() { return numItems; };


	private:
		Node<T> *head;
		Node<T> *tail;
		size_t numItems;

		Node<T> *get_node(size_t idx){

			size_t i = 0;
			Node<T> *cur = head;
			while(i < idx){
				cur = cur->next;
				i++;
			}

			return cur;
		}
}; 


// below line allows for program to compile.
// apparently the linker has trouble dealing with the template-ed stuff
// https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
//#include "linked_list_tests.cpp"


#endif

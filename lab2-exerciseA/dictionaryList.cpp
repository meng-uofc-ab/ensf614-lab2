/*
* File Name: dictionaryList.cpp
* Assignment: Lab 2 Exercise A
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Sept 25, 2024
*/

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

// function to overload insertion operator for Dictionarylist
ostream& operator<<(ostream& os, DictionaryList& dl){
    Node* originalCursor = dl.cursorM;
    dl.go_to_first();
    while (dl.cursor_ok()) {
        os << dl.cursor_key() << ' ' << dl.cursor_datum() << endl;
        dl.step_fwd();
    }
    dl.cursorM = originalCursor;
    return os;
}

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
    cursorM = 0;
    // if key is found in the list, update cursor
    for (Node * ptr = headM; ptr !=0; ptr = ptr->nextM){
        if(keyA == ptr->keyM){
            cursorM = ptr;
            return;
        }
    }
}


void DictionaryList::destroy()
{
    Node* current = headM;
    while (current != 0) {
        Node* next = current -> nextM;
        delete current;
        current = next;
    }
}


void DictionaryList::copy(const DictionaryList& source)
{
    if (source.headM == 0){
        sizeM = 0;
        headM = 0;
        cursorM = 0;
    } else{
        headM = new Node(source.headM ->keyM, source.headM ->datumM, 0);
        cursorM = 0;
        sizeM = 1;
        
        Node* current = headM;
        Node* next = source.headM -> nextM;
        
        while (next != 0) {
            sizeM++;
            current->nextM = new Node(next->keyM, next->datumM, 0);
            // If the source list's cursor is at this node, update the cursor
            if(next == source.cursorM){
                cursorM = current -> nextM;
            }
            current = current->nextM;
            next = next->nextM;
        }
    }
}

Mystring& DictionaryList::operator[](int index) const {
    if (index < 0 || index >= sizeM) {
        throw out_of_range("Index out of bounds");
    }
    Node* current = headM;
    for (int i=0; i < index; i++){
        current = current -> nextM;
    }
    return current -> datumM;
}

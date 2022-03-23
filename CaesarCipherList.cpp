//
// Created by Chien-Cheng Wang on 2/25/21.
//

#include "CaesarCipherList.h"

CaesarCipherList::CaesarCipherList(int cap) {
    list = new CaesarCipher[cap];
    capacity = cap;
    numElements = 0;
}

CaesarCipherList::~CaesarCipherList() {
    delete [] list;
}

CaesarCipherList::CaesarCipherList(const CaesarCipherList &obj) {
    // assign numElements and capacity (from obj)
    capacity = obj.capacity;
    numElements = obj.numElements;

    // allocate memory based on new capacity
    list = new CaesarCipher[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

CaesarCipherList &CaesarCipherList::operator=(const CaesarCipherList &obj) {
    if (this != &obj) {
        // deallocate memory
        delete [] list;

        // assign numElements and capacity (from obj)
        capacity = obj.capacity;
        numElements = obj.numElements;

        // allocate memory based on new capacity
        list = new CaesarCipher[capacity];

        // copy over elements (from obj)
        for (int i = 0; i < numElements; i++)
            list[i] = obj.list[i];
    }
    return *this;
}

void CaesarCipherList::addElement(CaesarCipher el) {
    if (numElements >= capacity)
        resize();

    list[numElements] = el;

    numElements++;
}

CaesarCipher CaesarCipherList::getElement(int pos) const {
    CaesarCipher newCaesarCipher;
    for (int i = 0; i < numElements; i++) {
        if (i == pos){
            newCaesarCipher = (list[i]);
            return newCaesarCipher;
        }

    }
    return newCaesarCipher;
}

int CaesarCipherList::size() const {
    return numElements;
}

void CaesarCipherList::resize() {
    // update capacity
    capacity *= 2;

    // create new array based on updated capacity
    CaesarCipher * tempArr = new CaesarCipher[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = list[i];

    // delete old array
    delete [] list;

    // reassign old array to new array
    list = tempArr;
}

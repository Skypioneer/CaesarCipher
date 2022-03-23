//
// Created by Chien-Cheng Wang on 2/25/21.
//

#include "CaesarCipher.h"
#ifndef HW6EC_CAESARCIPHERLIST_H
#define HW6EC_CAESARCIPHERLIST_H

class CaesarCipherList {
public:
    // Constructor
    CaesarCipherList(int);

    // Destructor
    ~CaesarCipherList();

    // Copy constructor
    CaesarCipherList(const CaesarCipherList &);

    // Overloaded assignment operator
    CaesarCipherList& operator=(const CaesarCipherList &);

    // Add an element to the list
    void addElement(CaesarCipher);

    // Get element in the list at the provided index
    CaesarCipher getElement(int) const;

    // Get list size;
    int size() const;

private:
    CaesarCipher *list;
    int capacity;	// Capacity of array
    int numElements;	// Number of elements in array
    void resize(); 	// Called to resize array when full
};



#endif //HW6EC_CAESARCIPHERLIST_H

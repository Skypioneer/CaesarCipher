//
// Created by Chien-Cheng Wang on 2/25/21.
//

#ifndef HW6EC_CAESARCIPHER_H
#define HW6EC_CAESARCIPHER_H


#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;


class CaesarCipher {
public:
    CaesarCipher();
    // Constructor
    // Precondition: none
    // Postcondition: initialize shift

    CaesarCipher(const CaesarCipher &);
    // Copy Constructor
    // Precondition: none
    // Postcondition: copy shift

    string encrypt(string);
    // Encrypt input
    // Precondition: none
    // Postcondition: initialize name to null, and priorityCode and
    //                arrivalOrder to zero

    string decrypt(string);
    // Decrypt input
    // Precondition: none
    // Postcondition: decrypt input

    CaesarCipher& operator = (const CaesarCipher &);
    // Assign this shift to input shift
    // Precondition: none
    // Postcondition: assign this shift to input shift

    CaesarCipher operator + (const CaesarCipher &) const;
    // Add input shift to this shift
    // Precondition: none
    // Postcondition: add input shift to this shift

    bool operator == (const CaesarCipher &) const;
    // Check if two shifts are same
    // Precondition: none
    // Postcondition: check if two shifts are same

    bool operator < (const CaesarCipher &) const;
    // Check this shift is smaller than input shift
    // Precondition: none
    // Postcondition: check this shift is smaller than input shift

    bool operator > (const CaesarCipher &) const;
    // Check this shift is greater than input shift
    // Precondition: none
    // Postcondition: Check this shift is greater than input shift

    CaesarCipher& operator ++ ();
    // Post-add shift
    // Precondition: none
    // Postcondition: post-add shift

    CaesarCipher operator ++ (int);
    // Pre-add shift
    // Precondition: none
    // Postcondition: Pre-add shift

private:
    int shift;
    static bool isSeeded;
    const int OFFSET_MIN = 32;
    const int OFFSET_MAX = 126;
    int getShift() const;
    string encryptDecrypt(string, bool);    // Encrypt or decrypt input
    bool isPositionInRange(int) const;

};


#endif //HW6EC_CAESARCIPHER_H

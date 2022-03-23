//
// Created by Chien-Cheng Wang on 2/25/21.
//

#include "CaesarCipher.h"
#include <iostream>
#include <utility>

bool CaesarCipher::isSeeded = false;

CaesarCipher::CaesarCipher() {
    shift = getShift();
}

CaesarCipher::CaesarCipher(const CaesarCipher &obj) {
    this->shift = obj.shift;
}

string CaesarCipher::encrypt(string s) {
    return encryptDecrypt(std::move(s), true);
}

string CaesarCipher::decrypt(string s) {
    return encryptDecrypt(std::move(s), false);
}

CaesarCipher& CaesarCipher::operator=(const CaesarCipher &obj) {
    this->shift = obj.shift;

    return *this;
}

CaesarCipher CaesarCipher::operator+(const CaesarCipher &obj) const {
    CaesarCipher newCaesarCipher;

    newCaesarCipher.shift = (this->shift + obj.shift) % 94;

    return newCaesarCipher;
}

bool CaesarCipher::operator==(const CaesarCipher &obj) const {
    return this->shift == obj.shift;
}

bool CaesarCipher::operator<(const CaesarCipher &obj) const {
    return this->shift < obj.shift;
}

bool CaesarCipher::operator>(const CaesarCipher &obj) const {
    return this->shift > obj.shift;
}

CaesarCipher& CaesarCipher::operator++() {
    shift++;
    return *this;
}

CaesarCipher CaesarCipher::operator++(int) {
    CaesarCipher tmp = *this;
    ++*this;

    return tmp;
}

int CaesarCipher::getShift() const {
    int low = 1;
    int high = OFFSET_MAX - OFFSET_MIN;     // 94

    if (!isSeeded) {
        srand((time(nullptr)));
        isSeeded = true;
    }

    return rand() % (high - low)  + low;    // 1 - 94
}

string CaesarCipher::encryptDecrypt(string s, bool encrypt) {
    string sb;
    unsigned size = s.size();

    // Convert String to char
    for (int i = 0; i < size; i++) {
        int indx = (unsigned char)s[i], cpos;
        string temp(1, s[i]);

        if (!isPositionInRange(indx))
            throw invalid_argument
                    ("String to be encrypted has unrecognized character " +
                    temp);

        if (encrypt) {
            cpos = indx + shift;
            if (cpos > OFFSET_MAX)
                cpos = OFFSET_MIN + (cpos - OFFSET_MAX);
        } else {
            cpos = indx - shift;
            if (cpos < OFFSET_MIN)
                cpos = OFFSET_MAX - (OFFSET_MIN - cpos);
        }
        //sb.append((char)cpos);
        sb += (char)cpos;
    }
    return sb;
}

bool CaesarCipher::isPositionInRange(int indx) const {
    return indx >= OFFSET_MIN && indx <= OFFSET_MAX;
}

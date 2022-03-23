// This program demonstrates the CaesarCipher class'
// Big 4 operations and overloaded operators

#include "CaesarCipher.h"
#include "CaesarCipherList.h"
#include <string>
#include <iostream>
using namespace std;

void testConstruct(string&, string&, int);
void testCopyAndOverloaded(string&, string&);
void printCcCc2Cc3(CaesarCipher &, CaesarCipher &, CaesarCipher &);
void testComparators(CaesarCipher &, CaesarCipher &);
void testAdd(CaesarCipher &);
void testIncrement(CaesarCipher &, CaesarCipher &, CaesarCipher &,
                   CaesarCipher &);
void testList(CaesarCipher &, CaesarCipher &, CaesarCipher &);

int main() {
    const int RUNTIME = 2;
    int count = 1;

    while(count <= RUNTIME) {
        CaesarCipher cc;
        string encryptedWord = cc.encrypt("Hello, world!");
        string decryptedWord = cc.decrypt(encryptedWord);

        CaesarCipher cc2;
        string encryptedWord2 = cc2.encrypt("Hello, world!");
        string decryptedWord2 = cc2.decrypt(encryptedWord2);

        if (count == 2)
            cout << endl << endl;

        printf("***** RUN %d: *****\n\n", count);
        testConstruct(encryptedWord, decryptedWord, 0);
        testConstruct(encryptedWord2, decryptedWord2, 2);

        cout << "*** testing copy constructor and overloaded assignment "
                """***\n\n";
        cout << "test copy constructor : cc3(cc2)\n";
        CaesarCipher cc3(cc2);
        string encryptedWord3 = cc3.encrypt("Hello, world!");
        string decryptedWord3 = cc3.decrypt(encryptedWord3);
        testCopyAndOverloaded(encryptedWord3, decryptedWord3);
        cout << "test overloaded assignment operator : cc2 = cc\n";
        cc2 = cc;
        encryptedWord2 = cc2.encrypt("Hello, world!");
        decryptedWord2 = cc2.decrypt(encryptedWord2);
        testCopyAndOverloaded(encryptedWord2, decryptedWord2);

        cout << "*** printing cc, cc2, and cc3 ***\n\n";
        printCcCc2Cc3(cc, cc2, cc3);

        cout << "*** testing comparators ***\n\n";
        cout << "test comparators\n";
        testComparators(cc, cc3);

        cout << "*** testing add ***\n\n";
        cout << "test add : cc2 = cc + cc3\n";
        cc2 = cc + cc3;
        testAdd(cc2);

        cout << "*** testing increment ***\n\n";
        CaesarCipher cc4;
        testIncrement(cc, cc2, cc3, cc4);

        cout << "test list : add cc, cc2, cc3\n\n";
        testList(cc, cc2, cc3);

        count++;
    }

    return 0;
}

void testConstruct(string &encryptedWord, string &decryptedWord, int index){
    if (index != 0)
        printf("test constructor : cc%d\n", index);
    else
        cout << "test constructor : cc\n";
    cout << "Encrypted: " << encryptedWord << endl;
    cout << "Decrypted: " << decryptedWord << endl << endl;
}

void testCopyAndOverloaded(string &encryptedWord, string &decryptedWord){
    cout << "Encrypted: " << encryptedWord << endl;
    cout << "Decrypted: " << decryptedWord << endl << endl;
}

void printCcCc2Cc3(CaesarCipher &cc, CaesarCipher &cc2, CaesarCipher &cc3){
    string encryptedWord = cc.encrypt("Hello, world!");
    string decryptedWord = cc.decrypt(encryptedWord);

    string encryptedWord2 = cc2.encrypt("Hello, world!");
    string decryptedWord2 = cc2.decrypt(encryptedWord2);

    string encryptedWord3 = cc3.encrypt("Hello, world!");
    string decryptedWord3 = cc3.decrypt(encryptedWord3);

    cout << "test constructor : cc\n";
    cout << "Encrypted: " << encryptedWord << endl;
    cout << "Decrypted: " << decryptedWord << endl << endl;

    cout << "test constructor : cc2\n";
    cout << "Encrypted: " << encryptedWord2 << endl;
    cout << "Decrypted: " << decryptedWord2 << endl << endl;

    cout << "test constructor : cc3\n";
    cout << "Encrypted: " << encryptedWord3 << endl;
    cout << "Decrypted: " << decryptedWord3 << endl << endl;
}

void testComparators(CaesarCipher &cc, CaesarCipher &cc3){
    cout << "cc == c3 is ";
    if (cc==cc3)
        cout << "true\n";
    else cout << "false\n";

    cout << "cc < c3 is ";
    if (cc < cc3)
        cout << "true\n";
    else cout << "false\n";

    cout << "cc > c3 is ";
    if (cc > cc3)
        cout << "true\n";
    else cout << "false\n\n";
}

void testAdd(CaesarCipher &cc){
    string encryptedWord = cc.encrypt("Hello, world!");
    cout << "Encrypted: " << encryptedWord << endl;

    string decryptedWord = cc.decrypt(encryptedWord);


    cout << "Decrypted: " << decryptedWord << endl << endl;
}

void testIncrement(CaesarCipher &cc, CaesarCipher &cc2, CaesarCipher &cc3,
                   CaesarCipher &cc4){

    cc4 = cc++;

    string encryptedWord = cc.encrypt("Hello, world!");
    string decryptedWord = cc.decrypt(encryptedWord);

    string encryptedWord4 = cc4.encrypt("Hello, world!");
    string decryptedWord4 = cc4.decrypt(encryptedWord4);

    cout << "test increment (postfix) : cc4 = cc++\n";
    cout << "Encrypted: " << encryptedWord << endl;
    cout << "Decrypted: " << decryptedWord << endl << endl;

    cout << "result of cc4 after postfix :\n";
    cout << "Encrypted: " << encryptedWord4 << endl;
    cout << "Decrypted: " << decryptedWord4 << endl << endl;

    cc4 = ++cc;

    encryptedWord = cc.encrypt("Hello, world!");
    decryptedWord = cc.decrypt(encryptedWord);

    encryptedWord4 = cc4.encrypt("Hello, world!");
    decryptedWord4 = cc4.decrypt(encryptedWord4);

    cout << "test increment (prefix) : cc4 = ++cc\n";
    cout << "Encrypted: " << encryptedWord << endl;
    cout << "Decrypted: " << decryptedWord << endl << endl;

    cout << "result of cc4 after prefix :\n";
    cout << "Encrypted: " << encryptedWord4 << endl;
    cout << "Decrypted: " << decryptedWord4 << endl << endl;

    cc4 = cc2++;

    string encryptedWord2 = cc2.encrypt("Hello, world!");
    string decryptedWord2 = cc2.decrypt(encryptedWord2);

    encryptedWord4 = cc4.encrypt("Hello, world!");
    decryptedWord4 = cc4.decrypt(encryptedWord4);

    cout << "test increment (postfix) : cc4 = cc2++\n";
    cout << "Encrypted: " << encryptedWord2 << endl;
    cout << "Decrypted: " << decryptedWord2 << endl << endl;

    cout << "result of cc4 after postfix :\n";
    cout << "Encrypted: " << encryptedWord4 << endl;
    cout << "Decrypted: " << decryptedWord4 << endl << endl;

    cc4 = ++cc2;

    encryptedWord2 = cc2.encrypt("Hello, world!");
    decryptedWord2 = cc2.decrypt(encryptedWord2);

    encryptedWord4 = cc4.encrypt("Hello, world!");
    decryptedWord4 = cc4.decrypt(encryptedWord4);

    cout << "test increment (prefix) : cc4 = ++cc2\n";
    cout << "Encrypted: " << encryptedWord2 << endl;
    cout << "Decrypted: " << decryptedWord2 << endl << endl;

    cout << "result of cc4 after postfix :\n";
    cout << "Encrypted: " << encryptedWord4 << endl;
    cout << "Decrypted: " << decryptedWord4 << endl << endl;

    cc4 = cc3++;

    string encryptedWord3 = cc3.encrypt("Hello, world!");
    string decryptedWord3 = cc3.decrypt(encryptedWord3);

    encryptedWord4 = cc4.encrypt("Hello, world!");
    decryptedWord4 = cc4.decrypt(encryptedWord4);

    cout << "test increment (postfix) : cc4 = cc3++\n";
    cout << "Encrypted: " << encryptedWord3 << endl;
    cout << "Decrypted: " << decryptedWord3 << endl << endl;

    cout << "result of cc4 after postfix :\n";
    cout << "Encrypted: " << encryptedWord4 << endl;
    cout << "Decrypted: " << decryptedWord4 << endl << endl;

    cc4 = ++cc3;

    encryptedWord3 = cc3.encrypt("Hello, world!");
    decryptedWord3 = cc3.decrypt(encryptedWord3);

    encryptedWord4 = cc4.encrypt("Hello, world!");
    decryptedWord4 = cc4.decrypt(encryptedWord4);

    cout << "test increment (prefix) : cc4 = ++cc3\n";
    cout << "Encrypted: " << encryptedWord3 << endl;
    cout << "Decrypted: " << decryptedWord3 << endl << endl;

    cout << "result of cc4 after postfix :\n";
    cout << "Encrypted: " << encryptedWord4 << endl;
    cout << "Decrypted: " << decryptedWord4 << endl << endl;

    cout << "----------------------------\n\n";
}

void testList(CaesarCipher &cc, CaesarCipher &cc2, CaesarCipher &cc3){
    const int SIZE = 3;
    CaesarCipherList * caesarCipherList = new CaesarCipherList(SIZE);

    caesarCipherList->addElement(cc);
    caesarCipherList->addElement(cc2);
    caesarCipherList->addElement(cc3);

    string encryptedWord = caesarCipherList->getElement(0).
            encrypt("Hello, world!");
    string decryptedWord = caesarCipherList->getElement(0).
            decrypt(encryptedWord);

    string encryptedWord2 = caesarCipherList->getElement(1).
            encrypt("Hello, world!");
    string decryptedWord2 = caesarCipherList->getElement(1).
            decrypt(encryptedWord2);

    string encryptedWord3 = caesarCipherList->getElement(2).
            encrypt("Hello, world!");
    string decryptedWord3 = caesarCipherList->getElement(2).
            decrypt(encryptedWord3);

    cout << "test print list[0] :\n";
    cout << "Encrypted: " << encryptedWord << endl;
    cout << "Decrypted: " << decryptedWord << endl << endl;

    cout << "test print list[1] :\n";
    cout << "Encrypted: " << encryptedWord2 << endl;
    cout << "Decrypted: " << decryptedWord2 << endl << endl;

    cout << "test print list[2] :\n";
    cout << "Encrypted: " << encryptedWord3 << endl;
    cout << "Decrypted: " << decryptedWord3 << endl;
}
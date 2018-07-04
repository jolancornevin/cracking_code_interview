#include <bits/stdc++.h>

using namespace std;

/**
 * Problem: Given two strings,  and , that may or may not be of the same length, determine the minimum number 
 * of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.
 *
 * Solution: Construct an hashmap of the ASCII table. Then loop through the first string and increment each character
 * count each time we inconter one, and loop through the second string to decrement character.
 * At the end, all numbers in the hashmap correspond to a difference of character in the string and thus a number of character
 * to delete. 
*/

int main()
{
    // Small trick to init our array to zeros.
    // The 128 size correspond to the small ASCII encoding table.
    // OPTIMISATION: As the possible character are between a and z, the size of the table could also be reduced.
    int charStruct[128]= {};
    
    string a;
    string b;
    
    int charDiff = 0;
    int asciiNum = 0;
    
    getline(cin, a);
    getline(cin, b);
    
    // OPTIMISATION: This could be improved further by iterating over both strings at once. And having a complementary loop if 
    // both strings are not of the same size.
    for (int iterA = 0; iterA < a.size(); ++iterA) {
        asciiNum = ((int) a[iterA]);
        charStruct[asciiNum]++;
    }
    
    for (int iterB = 0; iterB < b.size(); ++iterB) {
        asciiNum = ((int) b[iterB]);
        charStruct[asciiNum]--;
    }
    
    for (int iterChar = 0; iterChar < 128; ++iterChar) {
        if (charStruct[iterChar] != 0) {
            // a charStruct not equal to zero means a that a character appeared once or more in one string and not the other.
            charDiff += (charStruct[iterChar] < 0)? charStruct[iterChar] * -1: charStruct[iterChar];   
        }
    }
    
    cout << charDiff;

    return 0;
}

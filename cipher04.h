/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include <string>
#include <math.h>
#include <algorithm>
#include <ctype.h>

using namespace std;

static char MATRIX_1[25] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z'};
static char MATRIX_2[25] = {'z','y','x','w','v','u','t','s','r','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
static char MATRIX_3[25] = {'z','y','x','w','v','u','t','s','r','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
static char MATRIX_4[25] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z'};
/********************************************************************
 * CLASS Cipher: FOUR BY FOUR Cipher
 *******************************************************************/
class Cipher04 : public Cipher
{
private:
   char *matrix1;
   char *matrix2;
   char *matrix3;
   char *matrix4;

public:
   virtual std::string getPseudoAuth()  { return "Chad Smith"; }
   virtual std::string getCipherName()  { return "Foursquare Cipher"; }
   virtual std::string getEncryptAuth() { return "Charles Rich"; }
   virtual std::string getDecryptAuth() { return "Doug Barlow"; }

   Cipher04() {
      matrix1 = MATRIX_1;
      matrix2 = new char[25];
      matrix3 = new char[25];
      matrix4 = MATRIX_4;
   }
   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("L. Rombert, “Four Square Cipher,” Privacy Canada, 16-Mar-2021. [Online]. Available: https://privacycanada.net/classical-encryption/four-square-cipher/. [Accessed: 02-Apr-2021]. ");
   }


   /**********************************************************
   * GETINDEX
   **********************************************************/
   virtual int getIndex(char character, char *matrix)
      {
         int index;
         for(int x = 0; x < 25; x++){
           if (matrix[x] == character) {
               index = x;
               break;
           }
         }
         return index;
      }

   /**********************************************************
   * GETXCOORDINATE
   **********************************************************/
   virtual int getXCoordinate(int index) {
         return index % 5;
      }

   /**********************************************************
   * GETYCOORDINATE
   **********************************************************/
   virtual int getYCoordinate(int index) {
         return floor((index / 5));
      }

   /**********************************************************
   * GETENCRYPTEDLETTER
   **********************************************************/
   virtual int getEncryptedLetter(int x, int y, char *matrix) {
        int index = x + y;
        return matrix[index];
    }

   /**********************************************************
   * POPULATEMATRIX
   **********************************************************/
   virtual void populateMatrix(std::string password) {
        std::string key1 = password;
        std::string key2 = password;
        int splitIndex = password.find(' ');
        if (splitIndex != -1){
            key1 = password.substr(0,splitIndex);
            key2 = password.substr(splitIndex,(password.length() - splitIndex));
        }

        //Remove non alpha characters from keys.
        key1.erase(remove_if(key1.begin(), key1.end(), [](char c) { return !isalpha(c); } ), key1.end());
        key2.erase(remove_if(key2.begin(), key2.end(), [](char c) { return !isalpha(c); } ), key2.end());

        std::string usedChars1 = "";
        std::string usedChars2 = "";

        int iteratorM1 = 0;
        int iteratorM2 = 0;

        for (int i = 0; i < 25; i++){
            //Add characters from key 1 into matrix 2.
            if (iteratorM1 < key1.length()){
                //Skip characters already in matrix
                while (iteratorM1 < key1.length() && usedChars1.find(key1.at(iteratorM1)) != std::string::npos) {
                    iteratorM1++;
                }
                if (iteratorM1 < key1.length()){
                    this->matrix2[i] = key1.at(iteratorM1);
                    usedChars1 += key1.at(iteratorM1);
                }
            }
            //fill out remaining spaces in matrix from MATRIX_2
            if (iteratorM1 >= key1.length()){
                //Skip characters already in matrix
                while (usedChars1.find(MATRIX_2[iteratorM1 - key1.length()]) != std::string::npos) {
                    iteratorM1++;
                }
                this->matrix2[i] = MATRIX_2[iteratorM1 - key1.length()];
                usedChars1 += MATRIX_2[iteratorM1 - key1.length()];
            }
            iteratorM1++;

            //Add characters from key 2 into matrix3.
            if (iteratorM2 < key2.length()){
                //Skip characters already in matrix
                while (iteratorM2 < key2.length() && usedChars2.find(key2.at(iteratorM2)) != std::string::npos) {
                    iteratorM2++;
                }
                if (iteratorM2 < key2.length()){
                    this->matrix3[i] = key2.at(iteratorM2);
                    usedChars2 += key2.at(iteratorM2);
                }
            }
            //fill out remaining spaces in matrix from MATRIX_3
            if (iteratorM2 >= key2.length()) {
                //Skip characters already in matrix
                while (usedChars2.find(MATRIX_3[iteratorM2 - key2.length()])!= std::string::npos) {
                    iteratorM2++;
                }
                this->matrix3[i] = MATRIX_3[iteratorM2 - key2.length()];
                usedChars2 += MATRIX_3[iteratorM2 - key2.length()];
            }
            iteratorM2++;
        }

        return ;
    }
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      // The encryptCase pseudocode
       str =  "\n";
       str += "function fourByFourEncrypt(password) =>\n";
       str += "string cipherText \n";
       str += "\n";
       str += "// replace spaces \n";
       str += "password.split(' ', '') \n";
       str += "\n";
       str += "// add z if the password length is odd \n";
       str += "if password % 2 !== 0 \n";
       str += "   password += 'z' \n";
       str += "\n";
       str += "// encrypt plain text \n";
       str += "for i=0; i < password.length; i+=2 -> \n";
       str += "    // get index for letters in matrix1 and matrix4 \n";
       str += "    index1 = getIndex(password[i], matrix1) \n";
       str += "    index2 = getIndex(password[i + 1], matrix4) \n";
       str += "    // get x and y coordinates of indexes for their matrixes \n";
       str += "    x1 = getXCoordinate(index1) \n";
       str += "    y1 = getYCoordinate(index1) \n";
       str += "    x2 = getXCoordinate(index2) \n";
       str += "    y2 = getYCoordinate(index2) \n";
       str += "    cipherText += matrix2[x2 + (y1 * 5)] \n";
       str += "    cipherText += matrix3[x1 + (y2 * 5)] \n";
       str += "RETURN cipherText; \n";
       str += "\n";

       // Helper function
       str += "// Gets the index of the character in the matrix \n";
       str += "INT getIndex(character, matrix) { \n";
       str += "    int index; \n";
       str += "    FOR each character in Matrix\n";
       str += "            if matrix[x] IS EQUAL TO character \n";
       str += "                index<-matrix\n";
       str += "                BREAK;\n";
       str += "    return index \n";
       str += "} \n";
       str += "\n";

       // Helper Function
       str += " // get y-coordinate of the index in a 5 x 5 matrix \n";
       str += "INT getXCoordinate(index) => { \n";
       str += "    RETURN index % 5; \n";
       str += "} \n";
       str += "\n";

       // Helper Function
       str += "// gets the y-coordinate of the index in 5 x 5 matrix \n";
       str += "INT getYCoordinate(index) { \n";
       str += "    return floor((index / 5)) \n";
       str += "} \n";
       str += "\n";

       str += "// Returns the index for the encryption table \\n";
       str += "function getEncryptedLetter(x, y, matrix) => { \n";
       str += "    int index = y + x; \n";
       str += "    return matrix[index] \n";
       str += "} \n";

       str += "The Decrypt psuedocode \n";
       str += "function decryptFourByFour(encryptedPassword) => {\n";
       str += "decryptedText; \n";
       str += "// decrypt encrypted text \n";
       str += "for i=0; i < password.length; i+=2 => \n";
       str += "    // get index for letters in matrix1 and matrix4 \n";
       str += "    index1 = getIndex(password[i], matrix2) \n";
       str += "    index2 = getIndex(password[i + 1], matrix3) \n";
       str += "    // get x and y coordinates of indexes for their matrixes \n";
       str += "    x1 = getXCoordinate(index2) \n";
       str += "    y1 = getYcoordinate(index1) \n";
       str += "    x2 = getXCoordinate(index1) \n";
       str += "    y2 = getYCoordinate(index2) \n";
       str +=  "    decryptedText += matrix1[(x1 + (y1* 5)) \n";
       str += "    decryptedText += matrix4[(x2 + (y2 * 5)]  \n";
       str += "    return decryptedText; \n";
       str += "}\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Uses the four by four method to encrypt the plaintext
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
  {
      populateMatrix(password);

      std::string cipherText = plainText;
      std::transform(cipherText.begin(), cipherText.end(), cipherText.begin(),
            [](unsigned char c){ return std::tolower(c); });

      // Filters out spaces in the string
      cipherText.erase(remove_if(cipherText.begin(), cipherText.end(),
                    [](char c) { return !isalpha(c); } ), cipherText.end());

      // The text must be even for the encryption to work. if odd add Z at the end
      if (cipherText.length() % 2 != 0)
         cipherText += 'z';

      string encrypted = "";
      for(int i = 0; i < cipherText.length(); i += 2) {
         int index1 = getIndex(cipherText[i], this->matrix1);
         int index2 = getIndex(cipherText[i + 1], this->matrix4);
         int x1 = getXCoordinate(index1);
         int y1 = getYCoordinate(index1);
         int x2 = getXCoordinate(index2);
         int y2 = getYCoordinate(index2);

         encrypted += this->matrix2[x2+(y1 * 5)];
         encrypted += this->matrix3[x1+(y2 * 5)];
         }

      return encrypted;
  }


   /**********************************************************
    * DECRYPT
    * TODO: Uses the password to populate the cipher matrix
    *       and decrypt the text.
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
        populateMatrix(password);

        std::string plainText = "";

        for (int i = 0; i < cipherText.length(); i+=2){

            int index1 = getIndex(cipherText[i], this->matrix2);
            int index2 = getIndex(cipherText[i + 1], this->matrix3);
            int x1 = getXCoordinate(index2);
            int y1 = getYCoordinate(index1);
            int x2 = getXCoordinate(index1);
            int y2 = getYCoordinate(index2);
            plainText += getEncryptedLetter(x1, (y1 * 5), this->matrix1);
            plainText += getEncryptedLetter(x2, (y2 * 5), this->matrix4);
        }
        return plainText;
   }
};



#endif // CIPHER04_H

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
static char MATRIX_2[25] = {'t','h','e','q','u','i','k','b','r','o','n','f','o','x','j','u','m','p','s','o','v','e','r','t','h'};
static char MATRIX_3[25] = {'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','i','h','g','f','e','d','c','b','a'};
static char MATRIX_4[25] = {'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
/********************************************************************
 * CLASS
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
   virtual std::string getCipherName()  { return "Foursquare"; }
   virtual std::string getEncryptAuth() { return "Charles Rich"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }
   
   Cipher04() {
      matrix1 = MATRIX_1;
      matrix2 = MATRIX_2;
      matrix3 = MATRIX_3;
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
       str += "    cipherText += matrix2[x2 + y1] \n";
       str += "    cipherText += matrix3[x1 + y2] \n";
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
       str += "// Returns the index for the encryption table \n";
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
       str +=  "    decryptedText += getEncryptedLetter(x1, y1, matrix1) \n";
       str += "    decryptedText += getEncryptedLetter(x2, y2, matrix4) \n";
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
      std::string cipherText = plainText;
      
      // Filters out spaces in the string 
      std::string::iterator end_pos = std::remove(cipherText.begin(), cipherText.end(), ' ');
      cipherText.erase(end_pos, cipherText.end());
      
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

         encrypted += this->matrix2[x2+y1];
         encrypted += this->matrix3[x1+y2];
         }

      return encrypted;
  }


   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};



#endif // CIPHER04_H

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

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Chad Smith"; }
   virtual std::string getCipherName()  { return "Foursquare"; }
   virtual std::string getEncryptAuth() { return "Charles Rich"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("citation");
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

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "insert the encryption pseudocode\n";

//   str =  "\n"
//     "function fourByFourEncrypt(password) =>\n"
//        "array matrix1 // matrix without 'Q' \n"
//        "array matrix2 // key matrix \n"
//        "array martrix3 // matrix without 'J' \n"
//        "array matrix4 // key matrix \n"
//        "array cipherText \n"
//        "\n"
//        "// replace spaces \n"
//        "password.split(' ', '') \n"
//        "\n"
//        "// add z if the password length is odd \n"
//        "if password % 2 !== 0 \n"
//        "password += 'z' \n"
//        "\n"


//        "// encrypt plain text \n"
//        "for i=0; i < password.length; i+=2 -> \n"
//        "    // get index for letters in matrix1 and matrix4 \n"
//        "    index1 = getIndex(password[i], matrix1) \n"
//        "    index2 = getIndex(password[i + 1], matrix4) \n"
//        "    // get x and y coordinates of indexes for their matrixes \n"
//        "    x1 = getXCoordinate(index1) \n"
//        "    y1 = getYCoordinate(index1) \n"
//        "    x2 = getXCoordinate(index2) \n"
//        "    y2 = getYCoordinate(index2) \n"
//        "    cipherText += getEncryptedLetter(x2, y1, matrix2) \n"
//        "    cipherText += getEncryptedLetter(x1, y2, matrix3) \n"
//        "return cipherText; \n"
//        "\n"
//        "// Gets the index of the character in the matrix \n"
//        "function getIndex(character, matrix) => { \n"
//        "    int index; \n"
//        "    for x=0; x < matrix; x++ -> \n"
//        "            if matrix[x] == character \n"
//        "                index = matrix \n"
//        "                break \n"
//        "    return index \n"
//        "} \n"
//        "\n"
//        " // get y-coordinate of the index in a 5 x 5 matrix \n"
//        "function getXCoordinate(index) => { \n"
//        "    return index % 5; \n"
//        "} \n"
//        "\n"
//        "// gets the y-coordinate of the index in 5 x 5 matrix \n"
//        "function getYCoordinate(index) => { \n"
//        "     // divide by 5 and round down \n"
//        "    return Math.floor((index / 5)) \n"
//        "} \n"
//        "\n"
//        "// Returns the index for the encryption table \n"
//        "function getEncryptedLetter(x, y, matrix) => { \n"
//        "    int index = y + x; \n"
//        "    return matrix[index] \n"
//        "} \n";


      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      return str;
   }



   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
  {
      std::string cipherText = plainText;
      // TODO - Add your code here
      char matrix1[25] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                          'm','n','o','p','r','s','t','u','v','w','x','y','z'};
      char matrix2[25] = {'t','h','e','q','u','i','k','b','r','o','n',
                          'f','o','x','j','u','m','p','s','o','v','e','r','t','h'};
      char matrix3[25] = {'z','y','x','w','v','u','t','s','r','q','p','o','n',
                          'm','l','k','i','h','g','f','e','d','c','b','a'};
      char matrix4[25] = {'a','b','c','d','e','f','g','h','i','k','l',
                          'm','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
       

      // Traverse the given string. If current character
      // is not space, it is filtered out

      std::string::iterator end_pos = std::remove(cipherText.begin(), cipherText.end(), ' ');
      cipherText.erase(end_pos, cipherText.end());
      if (cipherText.length() % 2 != 0) {
         cipherText += 'z';
         }
      
      int index1 = 0;
      int index2 = 0;
      int x1 = 0;
      int y1 = 0;
      int x2 = 0;
      int y2 = 0;

      string encrypted = "";

      for(int i = 0; i < cipherText.length(); i += 2) {
         index1 = getIndex(cipherText[i], matrix1);
         index2 = getIndex(cipherText[i + 1], matrix4);
         x1 = getXCoordinate(index1);
         y1 = getYCoordinate(index1);
         x2 = getXCoordinate(index2);
         y2 = getYCoordinate(index2);


         encrypted += matrix2[x2+y1];
         encrypted += matrix3[x1+y2];       
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

/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ryan Budd"; }
   virtual std::string getCipherName()  { return "Transposition Cipher"; }
   virtual std::string getEncryptAuth() { return "Doug Barlow"; }
   virtual std::string getDecryptAuth() { return "Chad Smith"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "privacycanada.net (2020), \"Transposition Ciphers\",\n";
      s += "[Online]Available: https://privacycanada.net/classical-encryption/transposition-ciphers/";
      return s;
   }
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "  row <- password.length()\n";
      str += "  col <- ceil((plainText.length()+row)/row)\n";
      str += "  array[row][col]\n";
      str += "  FOR r is all values of row, t is all values of plainText\n";
      str += "    FOR c is all values of col\n";
      str += "      IF t is equal to NULL\n";
      str += "          array <- .\n";
      str += "      ELSE\n";
      str += "        IF t is equal to space\n";
      str += "          array <- ^\n";
      str += "        ELSE array <- t\n";
      str += "          increment t\n";
      str += "  FOR c is all values of col\n";
      str += "    FOR r is all values of row\n";
      str += "      cypherText += array\n";
      str += "  RETURN cypherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cypherText, password)\n";
      str += "  temp <- cypherText\n";
      str += "  row <- password.length()\n";
      str += "  col <- ceil(temp/row)\n";
      str += "  originalLength <- temp - row\n";
      str += "  IF originalLength < 0\n";
      str += "    originalLength <- -(originalLength)\n";
      str += "  IF originalLength is equal to 0\n";
      str += "    originalLength <- row\n";
      str += "  array[row][col]\n";
      str += "  FOR c is all values of col and t is all values of cypherText\n";
      str += "    FOR r is all values of row\n";
      str += "      array <- t\n";
      str += "      increment t\n";
      str += "  WHILE w < originalLength\n";
      str += "    FOR c is all values of col and rw is all values of row\n";
      str += "      IF array is equal to ^\n";
      str += "        plainText <- space\n";
      str += "      ELSE plainText <- array\n";
      str += "      increment w\n";
      str += "      IF w is equal to originalLength\n";
      str += "        BREAK\n";
      str += "    increment rw\n";
      str += "  plainText.erase(remove(plainText.begin(), plainText.end(), \'.\'), plainText.end())\n";
      str += "  RETURN plainText\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
        std::string cipherText = "";

        int row = password.length();
        int col = std::ceil((plainText.length() + row)/row);
        char myArray[row][col];
        int t = 0;
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (t >= plainText.length()){
                    myArray[r][c] = '.';
                } else {
                    if (plainText.at(t) == ' '){
                        myArray[r][c] = '^';
                    } else {
                        myArray[r][c] = plainText.at(t);
                    }
                    t++;
                }
            }
        }
        std::cout << "\nDataGrid\n";
        for (int c = 0; c < col; c++){
            for (int r = 0; r < row; r++){
                cipherText += myArray[r][c];
            }
        }
        for (int c = 0; c < row; c++){
            for (int r = 0; r < col; r++){
                std::cout << myArray[c][r] << " ";
            }
            std::cout << "\n";
        }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
    virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string tempCipher = cipherText;
      float row = password.length();
      int col = ceil(float(cipherText.length())/row);
      int text_length = tempCipher.length();// - row;
      if (text_length < 0) {
        text_length = -text_length;
      } else if (text_length == 0) {
        text_length = row;
      }
      char array[int(row)][col];
      for (int c=0, t=0; c < col; c++) {
        for (int r=0; r < row; r++) {
            array[r][c] = tempCipher[t];
            t++;
        }
      }
      std::string plainText;
      int rw = 0, w = 0;
      while (w < text_length) {
        for (int c = 0; c < col; c++) {
            if (array[rw][c] == '^') {
                plainText += ' ';
            } else {
                plainText += array[rw][c];
            }
            w++;
            if (w == text_length) {
                break;
            }
        }
        rw++;
      }
      plainText.erase(std::remove(plainText.begin(), plainText.end(), '.'), plainText.end());
      return plainText;
   }
};

#endif // CIPHER01_H

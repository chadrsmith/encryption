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
   virtual std::string getCipherName()  { return "Transport Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

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
      str += "  FOR r is all values of row, t is all values of plainText, and p is all values of password\n";
      str += "    FOR c is all values of col\n";
      str += "      IF t is equal to NULL\n";
      str += "        IF p is equal to NULL\n";
      str += "          array <- .\n";
      str += "        ELSE array <- p\n";
      str += "          increment p\n";
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
      str += "  temp.erase(remove(temp.begin(), temp.end(), \'.\'), temp.end())\n";
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
      std::string cipherText = plainText;
      // TODO - Add your code here

      return cipherText;
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

#endif // CIPHER01_H

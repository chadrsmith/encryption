/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H
#include "cipher.h"
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Kwaku Appau-Nkansah"; }
   virtual std::string getCipherName()  { return "Vigenère Cipher"; }
   virtual std::string getEncryptAuth() { return "Ryan Budd"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("1. Rembert, L. (2020, January 29). Vigenère Cipher. Privacy Canada.\n"
                         "Available: https:;//privacycanada.net/classical-encryption/vigenere-cipher/\n"
                         "2. Soofi, A. A., Riaz, I., & Rasheed, U. (2016). \"An enhanced vigenere cipher for data security.\"\n"
                         "Int. J. Sci. Technol. Res, 5(3), 141-145.\n");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str = "ENCRYPT PSUEDOCODE:\n"
       "encrypt(plainText,password)\n"
       "  FOR i <- each token in plainText\n"
       "      p <- totalAlphabet.find(plainText[i])\n"
       "      k <- totalAlphabet.find(password[i % length of password])\n"
       "      cypherText <- cypherText + totalAlphabet[(p + k) % length of alphabet]\n"
       "  RETURN cypherText\n\n";

      // The decrypt pseudocode
      str += "DECRYPT PSUEDOCODE:\n"
       "decrypt(cypherText,password)\n"
       "   FOR i <- each token in cypherText\n"
       "      p <- totalAlphabet.find(cypherText[i])\n"
       "      k <- totalAlphabet.find(password[i % length of password])\n"
       "      IF p is greater than k \n"
       "            p <- p + length of totalAlphabet\n"
       "      plainText <- plainText + totalAlphabet[(p - k) % length of alphabet]\n"
       "  RETURN plainText\n\n";

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
      std::string totalAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";

      for (int i = 0, p = 0, k = 0; i < plainText.length(); i++) {
            p = totalAlphabet.find(plainText[i]);
            k = totalAlphabet.find(password[i % password.length()]);
            cipherText += totalAlphabet[(p + k) % totalAlphabet.length()];
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
      std::string plainText = "";
       std::string totalAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";

       for (int i = 0, p = 0, k = 0; i < cipherText.length(); i++) {
             p = totalAlphabet.find(cipherText[i]);
             k = totalAlphabet.find(password[i % password.length()]);
           if(p > k)
           {
               p += totalAlphabet.length();
           }
           plainText += totalAlphabet[(p - k) % totalAlphabet.length()];
       }
      return plainText;
   }
};

#endif // CIPHER03_H

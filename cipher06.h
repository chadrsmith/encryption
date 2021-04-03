/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H
#include <cstring>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Charles Rich"; }
   virtual std::string getCipherName()  { return "Polybius Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
       return std::string("Jan Carlo T. Arroyo, Cristina E. Dumdumaya, \n"
           "Allemar Jhone P. Delima\n"
           "Polybius Square in Cryptography: A Brief \n"
           "Review of Literature;\n"
           "International Journal of Advanced Trends in \n"
           "Computer Science and Engineering, Volume 9, \n"
           "No.3, May - June 2020 [Online] Available: \n"
           "http://www.warse.org/IJATCSE/static/pdf/file\n"
           "/ijatcse198932020.pdf\n");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
       std::string str;

       // The encrypt pseudocode
       str = "encrypt:\n";
       str += "encrypt(plainText, password):\n";
       str += "  set key = abcdefghijklmnopqrstuvwxyz,.!?0123456789\n";
       str += "  key += password\n";
       str += "  set text = plainText\n";
       str += "  set cipherText\n\n";
       str += "  plainText = toLower(plainText)";
       str += "  for char1 is a char in text\n";
       str += "    set first = 0\n";
       str += "    set second = 0\n";
       str += "    for char2 is a char in key and i counts from 1:\n";
       str += "      if char1 equals char2\n";
       str += "        first = i / 6\n";
       str += "        second = i % 6\n";
       str += "    add first and second to cipherText AS character\n";
       str += "  return cipherText\n";

       // The decrypt pseudocode
       str += "decrypt: \n";
       str += "decrypt(cipherText, password):\n";
       str += "  set key = abcdefghijklmnopqrstuvwxyz,.!?0123456789\n";
       str += "  key += password\n";
       str += "  set plainText\n";
       str += "  for c in cipherText:\n";
       str += "    set index = (integer) c * 6\n";
       str += "    increment c\n";
       str += "    add (integer) c to index\n";
       str += "    index = index % length of key\n";
       str += "    add key[index] to plainText\n";
       str += "  return plainText\n";

       return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string key = "abcdefghijklmnopqrstuvwxyz,.!?0123456789";
      key += password;
      std::string text = plainText;
      std::string cipherText;

      for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
      }

      for (int i = 0; i < text.length(); i++) {
            int first = 0;
            int second = 0;
            for (int j = 1; j < key.length(); j++) {
                if (text[i] == key[j]) {
                    first = i / 6;
                    second = i % 6;
                }
            }
            cipherText += (char)first + (char)second;
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
       std::string plainText = cipherText;
       std::string key = "abcdefghijklmnopqrstuvwxyz,.!?0123456789";
       key += password;
       for (int c = 0; c < cipherText.length(); c++)
       {
           int index = (int) c * 6;
           c++;
           (int)c + index;
           index = index % key.length();
           plainText + key[index];
       }
      return plainText;
   }
};

#endif // CIPHER06_H

/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
private:
   char valueMinimum;
   char valueMaximum;
   int sizeAlphabet;
public:

   Cipher02()
   {
      this->valueMinimum = ' ';
      this->valueMaximum = '~';
      this->sizeAlphabet = valueMaximum - valueMinimum;
   }
   
   virtual std::string getPseudoAuth() { return "Doug Barlow"; }
   virtual std::string getCipherName() { return "AutoKey Cipher"; }
   virtual std::string getEncryptAuth() { return "Chad Smith"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("ìAutokey Cipher,î Crypto Corner. [Online]. Available: https://crypto.interactive-maths.com/autokey-cipher.html.\n [Accessed: 01-Apr-2021].\n");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encryptCase pseudocode
      str = "encrypt(plainText, password)\n";
      str += "   key <- password + plainText";
      str += "   iterator <- 0";
      str += "   FOR p is all values of plainText\n";
      str += "      offset <- indexFromCharacter(key[iterator])\n";
      str += "      index <- (indexFromCharacter(*p) + offset) % size\n";
      str += "      cipherText += characterFromIndex(index)\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   key <- password";
      str += "   iterator <- 0";
      str += "   FOR p is all values of cipherText\n";
      str += "      offset <- indexFromCharacter(key[iterator])\n";
      str += "      index <- (indexFromCharacter(*p) - offset) % size\n";
      str += "      plainChar <- characterFromIndex(index)\n";
      str += "      plainText += plainChar\n";
      str += "      key += plainChar\n";
      str += "   RETURN plainText\n\n";

      // helper routine
      str += "indexFromCharacter(letter)\n";
      str += "  IF letter < maxVal AND letter > minVal \n";
      str += "      index <- letter - minVal\n;";
      str += "      RETURN index\n";
      str += "  ELSE \n";
      str += "      RETURN 0\n";

      // helper routine
      str += "characterFromIndex(index)\n";
      str += "  IF index < alphaSize AND index > 0 \n";
      str += "      character <- index + minVal\n;";
      str += "      RETURN character\n";
      str += "  ELSE \n";
      str += "      RETURN ' ' ";

      return str;
   }
   
   /**********************************************************
    * INDEXFROMCHARACTER
    ***********************************************************/
   virtual int indexFromCharacter(char letter) {
      if (letter < this->valueMinimum && letter > this->valueMaximum) {
         int index = letter - this->valueMinimum;
         return index;
      } else {
         return 0;
      }
   }
   
   /**********************************************************
    * CHARACTERFROMINDEX
    ***********************************************************/
   virtual char characterFromIndex(int index) {
      if (index < this->sizeAlphabet && index > 0) {
         char character = index + this->valueMinimum;
         return character;
      } else {
         return ' ';
      }
   }

   /**********************************************************
    * ENCRYPT
    * 
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
      const std::string & password)
   {
      std::string cipherText = plainText;
      int iterator = 0;
      
      for (int i = 0; i < cipherText.length(); i++) {
         int offset = this->indexFromCharacter(cipherText[iterator]);
         int index = (indexFromCharacter(password[i]) + offset) % cipherText.length();
         cipherText += this->characterFromIndex(index);
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
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER02_H



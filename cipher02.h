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
public:
   Cipher02()
   {
      valueMinimum = ' ';
      valueMaximum = '~';
      sizeAlphabet = valueMaximum - valueMinimum;
   }
   virtual std::string getPseudoAuth()  { return "Doug Barlow"; }
   virtual std::string getCipherName()  { return "AutoKey Cipher"; }
   virtual std::string getEncryptAuth() { return "Chad Smith"; }
   virtual std::string getDecryptAuth() { return "Charles Rich"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("“Autokey Cipher,” Crypto Corner. [Online]. Available: https://crypto.interactive-maths.com/autokey-cipher.html.\n [Accessed: 01-Apr-2021].\n");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encryptCase pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   key <- password + plainText";
      str += "   iterator <- 0";
      str += "   FOR p is all values of plainText\n";
      str += "      offset <- indexFromCharacter(key[iterator])\n";
      str += "      index <- (alphabetSize)\n";
      str += "      index += (indexFromCharacter(*p) + offset) \n";
      str += "      cipherText += characterFromIndex(index % alphabetSize)\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   key <- password";
      str += "   iterator <- 0";
      str += "   FOR p is all values of cipherText\n";
      str += "      offset <- indexFromCharacter(key[iterator++])\n";
      str += "      index <- (alphabetSize)\n";
      str += "      index <- (indexFromCharacter(*p) - offset)\n";
      str += "      plainChar <- characterFromIndex(index % alphabetSize)\n";
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
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
      const std::string & password)
   {

      std::string key = password + plainText;
      std::string cipherText = "";

      for (int i = 0; i < plainText.length(); i++) {
         int offset = this->indexFromCharacter(key[i]);
         int index = this->sizeAlphabet;
         index += (indexFromCharacter(plainText[i]) + offset);
         cipherText += this->characterFromIndex(index % this->sizeAlphabet);
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
        std::string plainChar = "";
        std::string plainText = "";
        std::string key = password;
        for( int i = 0; i < cipherText.length(); i++){
            int offset = indexFromCharacter(key[i]);
            int index = this->sizeAlphabet;
            index += (indexFromCharacter(cipherText[i]) - offset);
            plainChar = characterFromIndex(index % this->sizeAlphabet);
            plainText += plainChar;
            key += plainChar;
        }
        return plainText;
   }

private:
   /**************************************************
    * INDEX FROM CHARACTER
    * Get an index value from a given letter.
    *************************************************/
   int indexFromCharacter(char letter)
   {
      // return the value
      if (letter > valueMaximum || letter < valueMinimum)
         return 0;
      else
         return (int)(letter - valueMinimum);
   }

   /**************************************************
    * CHARACTER FROM INDEX
    * Get the characer value from a given index.
    *************************************************/
   char characterFromIndex(int index)
   {
      if (index >= 0 && index < sizeAlphabet)
         return (char)(index + valueMinimum);
      else
         return ' ';
   }

   // minimum "printable" character
   char valueMinimum;
   // maximum "printable" character
   char valueMaximum;
   int sizeAlphabet;
};

#endif // CIPHER02_H

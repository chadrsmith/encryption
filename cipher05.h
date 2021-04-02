/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jacob Muhlestein"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Kwaku Appau-Nkansah"; }
   virtual std::string getDecryptAuth() { return "Ryan Budd"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s =  "dcode.fr (2021), \"Affine Cipher\",\n";
      s += "[Online]Available:https://www.dcode.fr/affine-cipher";

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
      str =  "encrypt(plainText, num1, num2)\n";
      str += "  FOR p is all values of plainText \n";
      str += "      IF p is not equal to BLANK \n";
      str += "          cipherText <- cipherText + (char) ((((num1 * (p - 'A') ) + num2) % 26) + 'A')\n";
      str += "      ELSE cipherText <- p\n";
      str += "  RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, num1, num2)\n";
      str += "  FOR a is all letters in the alphabet\n";
      str += "      flag <- (num1 * a) % 26\n";
      str += "      IF flag is equal to 1\n";
      str += "          num1_inverse <- a\n";
      str += "  FOR c is all the values of cipherText\n";
      str += "      IF c is not equal to BLANK\n";
      str += "          plainText <- plainText + (char) (((num1_inverse * ((c + 'A' - num2)) % 26)) + 'A')\n";
      str += "      ELSE  plainText <- plainText + c\n";
      str += "  RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, const std::string & password)
   {
      std::string cipherText = "";
      std::string number1;
      std::string number2;
      int count = 0;

      for (int i = 0; i < password.length(); i++) {
        if (password[i] != ' ') {
            number1 += password[i];
            count++;
        } else {
            count++;
            break;
        }
      }
      for (int i = count; i < password.length(); i++) {
        number2 += password[i];
      }

      int num1 = std::stoi(number1);
      int num2 = std::stoi(number2);

       for (int i = 0; i < plainText.length(); i++)
       {
           if(&plainText[i] != " ")
           {
               cipherText = cipherText + (char) ((((num1 * (plainText[i]-'A') ) + num2) % 26) + 'A');
           }
           else
           {
               cipherText += plainText[i];
           }
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
      std::string plainText;
      std::string number1;
      std::string number2;
      int count = 0;

      for (int i = 0; i < password.length(); i++) {
        if (password[i] != ' ') {
            number1 += password[i];
            count++;
        } else {
            count++;
            break;
        }
      }
      for (int i = count; i < password.length(); i++) {
        number2 += password[i];
      }

      int num1 = std::stoi(number1);
      int num2 = std::stoi(number2);
      int num1_inverse = 0;
      int flag = 0;

      for (int a = 0; a < 26; a++) {
        flag = (num1 * a) % 26;
        if (flag == 1) {
            num1_inverse = a;
        }
      }
      for (int c = 0; c < (cipherText.length()); c++) {
        if (cipherText[c] != ' ') {
            plainText = plainText + (char) (((num1_inverse * ((cipherText[c] + 'A' - num2)) % 26)) + 'A');
        } else {
            plainText = plainText + cipherText[c];
        }
      }
      return plainText;
   }
};

#endif // CIPHER05_H


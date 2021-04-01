/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "pseudocode author"; }
   virtual std::string getCipherName()  { return "cipher name"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
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
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "\n"
    "function fourByFourEncrypt(password) =>\n"
       "array matrix1 // matrix without 'Q' \n"
       "array matrix2 // key matrix \n"
       "array martrix3 // matrix without 'J' \n"
       "array matrix4 // key matrix \n"
       "array cipherText \n"
       "\n"
       "// replace spaces \n"
       "password.split(' ', '') \n"
       "\n"
       "// add z if the password length is odd \n"
       "if password % 2 !== 0 \n"
       "password += 'z' \n"
       "\n"
       "// encrypt plain text \n"
       "for i=0; i < password.length; i+=2 -> \n"
       "    // get index for letters in matrix1 and matrix4 \n"
       "    index1 = getIndex(password[i], matrix1) \n"
       "    index2 = getIndex(password[i + 1], matrix4) \n"
       "    // get x and y coordinates of indexes for their matrixes \n"
       "    x1 = getXCoordinate(index1) \n"
       "    y1 = getYCoordinate(index1) \n"
       "    x2 = getXCoordinate(index2) \n"
       "    y2 = getYCoordinate(index2) \n"
       "    cipherText += getEncryptedLetter(x2, y1, matrix2) \n"
       "    cipherText += getEncryptedLetter(x1, y2, matrix3) \n"
       "return cipherText; \n"
       "\n"
       "// Gets the index of the character in the matrix \n"
       "function getIndex(character, matrix) => { \n"
       "    int index; \n"
       "    for x=0; x < matrix; x++ -> \n"
       "            if matrix[x] == character \n"
       "                index = matrix \n"
       "                break \n"
       "    return index \n"
       "} \n"
       "\n"
       " // get y-coordinate of the index in a 5 x 5 matrix \n"
       "function getXCoordinate(index) => { \n"
       "    return index % 5; \n"
       "} \n"
       "\n"
       "// gets the y-coordinate of the index in 5 x 5 matrix \n"
       "function getYCoordinate(index) => { \n"
       "     // divide by 5 and round down \n"
       "    return Math.floor((index / 5)) \n"
       "} \n"
       "\n"
       "// Returns the index for the encryption table \n"
       "function getEncryptedLetter(x, y, matrix) => { \n"
       "    int index = y + x; \n"
       "    return matrix[index] \n"
       "} \n"
   
       // The decrypt pseudocode
   str += "The Decrypt psuedocode \n"
       "function decryptFourByFour(encryptedPassword) => {\n"
       "array matrix1 // matrix without 'Q' \n"
       "array matrix2 // key matrix \n"
       "array martrix3 // matrix without 'J' \n"
       "array matrix4 // key matrix \n"
       "decryptedText; \n"
       "\n"
       "// decrypt encrypted text \n"
       "for i=0; i < password.length; i+=2 => \n"
       "    // get index for letters in matrix1 and matrix4 \n"
       "    index1 = getIndex(password[i], matrix2) \n"
       "    index2 = getIndex(password[i + 1], matrix3) \n"
       " \n"
       "    // get x and y coordinates of indexes for their matrixes \n"
       "    x1 = getXCoordinate(index2) \n"
       "    y1 = getYcoordinate(index1) \n"
       "    x2 = getXCoordinate(index1) \n"
       "    y2 = getYCoordinate(index2) \n"
       " \n"
       "    decryptedText += getEncryptedLetter(x1, y1, matrix1) \n"
       "    decryptedText += getEncryptedLetter(x2, y2, matrix4) \n"
       "    return decryptedText; \n"
       "}\n";

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

#endif // CIPHER04_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**********************************************************************
 * DetermineAlphabet: checks to see if a specific character set it used
 * in the provided string. Returns the number of used characters (based
 * on character set).
 *********************************************************************/
int determineAlphabet(string password)
{
   bool hasDigit = false;
   bool hasUpperAlpha = false;
   bool hasLowerAlpha = false;
   bool hasSymbols = false;
   for (int i = 0; i < password.length(); i++)
   {
      if (isdigit(password[i]))
         hasDigit = true;
      else if (isalpha(password[i]) && isupper(password[i]))
         hasUpperAlpha = true;
      else if (isalpha(password[i]))
         hasLowerAlpha = true;
      else
         hasSymbols = true;
   }
   return (hasDigit ? 10 : 0) +
      (hasUpperAlpha ? 26 : 0) +
      (hasLowerAlpha ? 26 : 0) +
      (hasSymbols ? 32 : 0);
}

/**********************************************************************
 * Main: Gathers the password from user input, then calculates the
 * combinations and number of bits for the provided password.
 *********************************************************************/
int main()
{
   string password;
   cout << "Please enter the password: ";
   cin >> password;

   unsigned long long combinations = pow(determineAlphabet(password),
                                         password.length());
   unsigned long long numBits = floor(log2(combinations));
   cout << "There are " << combinations << " combinations\n";
   cout << "That is equivalent to a key of " << numBits << " bits\n";
}

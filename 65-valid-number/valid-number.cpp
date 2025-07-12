#include <string>
#include <cctype>
using namespace std;

class Solution {
 public:
  bool isNumber(string s) {
    int n = s.size(), i = 0;
    // skip leading spaces
    while (i < n && s[i] == ' ') i++;

    bool numSeen = false;   // have we seen a digit?
    bool dotSeen = false;   // have we seen a '.' before exponent?
    bool expSeen = false;   // have we seen 'e' or 'E'?

    for (; i < n; ++i) {
      char c = s[i];
      if (isdigit(c)) {
        numSeen = true;
      } 
      else if (c == '.') {
        // dot only allowed once and not after exponent
        if (dotSeen || expSeen) return false;
        dotSeen = true;
      } 
      else if (c == 'e' || c == 'E') {
        // exponent only once, and must follow at least one digit
        if (expSeen || !numSeen) return false;
        expSeen = true;
        numSeen = false;  // reset: we now need at least one digit after 'e'
      } 
      else if (c == '+' || c == '-') {
        // sign only allowed at start or immediately after exponent
        if (i > 0 && !(s[i-1] == 'e' || s[i-1] == 'E')) 
          return false;
      } 
      else if (c == ' ') {
        // once we hit a space, the rest must be all spaces
        break;
      } 
      else {
        return false;
      }
    }

    // skip trailing spaces
    while (i < n && s[i] == ' ') i++;
    // valid if we’ve seen at least one digit and consumed all characters
    return numSeen && i == n;
  }
};
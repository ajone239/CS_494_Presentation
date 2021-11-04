#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class DigitStringDiv1 {
  private:
    int X;                                          // The parameter X
    string S;                                       // The parameter S
    string XS;                                      // X as a string of digits
    int SD;                                         // Number of digits in S
    int XD;                                         // Number of digits in X
    long long Cache[50][15];                        // Memoization cache for neq_digits()

    // Return N-choose-K.
    long long comb(long n, long k) {
      long long rv = 1;

      for (long i = 1; i <= k; i++) {
        rv = rv * (n + 1 - i) / (i);
      }

      return rv;
    }

    // Counting strings whose sizes are > XD.
    long long ngtr_digits(int sindex) {
      long long rv = 0;

      for (int i = this->XD; i <= sindex; i++) {
        rv += this->comb(i, XD);
      }

      return rv;
    }

    // Counting strings whose sizes are == XD
    long long neq_digits(int sindex, int xindex);

  public:
    long long count(string s, int x) {
      this->X = x;
      this->S = s;
      this->XS = to_string(x);
      this->SD = s.size();
      this->XD = this->XS.size();

      long long rv = 0;

      for (int i = this->XD; i < this->SD; i++) {
        if (this->S[i] != 0)
          rv += ngtr_digits(i);
      }

      return rv;
    }

    long long count_dumb(string s, int x) {

      size_t x_len = 0;
      long long count = 0;
      string temp;

      // Calc the number of digits in
      for (size_t i = x; i > 0; i /= 10) x_len++;

      size_t power_set_size = pow(2,s.size());

      // Gen the superset
      for (size_t i = 0; i < power_set_size; i++) {

        temp.clear();
        bool found = false;

        // Build the element
        for (size_t j = 0; j < s.size(); j++){
          if (i & 1 << j) {
            // Ignore if it starts with '0'
            if (!found && s[j] == '0')
              break;
            else
              found = true;
            temp.push_back(s[j]);
          }
        }

        // Digit check
        if (temp.size() > x_len) {
          count++;
        } else if (temp.size() == x_len) {
          if (atoi(temp.c_str()) > x)
            count++;
        }
      }

      return count;
    }
};

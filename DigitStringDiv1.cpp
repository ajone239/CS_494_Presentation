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
    long long Cache[50][15] = {{-1}};               // Memoization cache for neq_digits()

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

      // only go to sindex because you want to gurantee it starts at sindex
      // also use XD because you are doing xd + 1 with using sindex
      for (int i = this->XD; i <= sindex; i++) {
          rv += this->comb(sindex, i);
      }

      return rv;
    }

    // Counting strings whose sizes are == XD
    long long neq_digits(int sindex, int xindex) {

      long long rv = 0;

      if (xindex >= this->XD) {
        return 0;
      }

      if (xindex == this->XD - 1) {
        if (this->XS[xindex] > this->S[sindex]) {
          return 1;
        } else {
          return 0;
        }
      }

      if (this->XS[xindex] >= this->S[sindex]) {
        for (int j = 0; j < this->XD; j++) {
          rv += neq_digits(sindex + j, xindex + 1);
        }
      }

      return rv;
    }

  public:
    long long count(string s, int x) {
      this->X = x;
      this->S = s;
      this->XS = to_string(x);
      this->SD = s.size();
      this->XD = this->XS.size();

      long long rv = 0;

      // Count Greater
      for (int i = this->XD; i < this->SD; i++)
        if (this->S[this->SD - i - 1] != '0')
          rv += ngtr_digits(i);

      // Count Equal
      for (int i = 0; i < this->SD - this->XD + 1; i++) {
        // Start at each index where an equal could start.
        neq_digits(i, 0);
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

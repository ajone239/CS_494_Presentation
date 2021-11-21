/*
 * Author: Austin Jones (ajone239)
 * File: DigitStringDiv1.cpp
 * Date: 11/08/2021
 *
 * Purpose: This file implements the DigitStringDiv1 class. This class carries
 *          the method that counts all substrings of a digit S which are
 *          larger than a digit X.
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DigitStringDiv1 {
  private:
    int X;                                          // The parameter X
    string S;                                       // The parameter S
    string XS;                                      // X as a string of digits
    int SD;                                         // Number of digits in S
    int XD;                                         // Number of digits in X
    long long Cache[50][15] = {{0}};               // Memoization cache for neq_digits()

    /*
     * Return N-choose-K.
     */
    long long comb(long n, long k) {
      long long rv = 1;

      for (long i = 1; i <= k; i++) {
        rv = rv * (n + 1 - i) / (i);
      }

      return rv;
    }

    /*
     * Prints out the whole cache for debugging
     */
    void print_cache(void) {
      for (int i = 0; i < this->SD; i++) {
        for (int j = 0; j < this->XD; j++) {
          // Only look at entries that are in the range and used
          if (this->Cache[i][j]) {
            printf("(%d, %d) = %lld\n", i, j, this->Cache[i][j]);
          }
        }
      }
    }

    /*
     * Counting strings whose sizes are > XD.
     */
    long long ngtr_digits(int sindex) {
      long long rv = 0;

      /*
       * Only go to sindex because you want to gurantee it starts at sindex
       * Also use XD because you are doing xd + 1 to have more digits
       */
      for (int i = this->XD; i <= sindex; i++) {
          rv += this->comb(sindex, i);
      }

      return rv;
    }

    /*
     * Counting strings whose sizes are == XD
     */
    long long neq_digits(int sindex, int xindex) {

      long long rv = 0;

      // Needs valid indexes
      if (xindex >= this->XD || sindex >= this->SD) {
        return 0;
      }

      // Cache Hit?
      if (this->Cache[sindex][xindex]) {
        this->hits++;
        return this->Cache[sindex][xindex];
      }

      if (this->S[sindex] > this->XS[xindex]) {
        /*
         * If the S digit is greater than X digit then we can skip the rest
         * of the checks and just count how many strings we can build.
         */
        rv = this->comb(this->SD - sindex - 1, this->XD - xindex - 1);
      } else if (this->S[sindex] == this->XS[xindex]) {
        // last char in string equal means it isn't greater
        if (xindex == this->XD - 1) {
          return 0;
        }
        // Recurse down for all substrings
        for (int j = 1; j < this->SD - sindex; j++) {
          rv += neq_digits(sindex + j, xindex + 1);
        }
      }

      // Fix cache
      this->Cache[sindex][xindex] = rv;

      return rv;
    }

  public:
    long long hits;

    long long count(string s, int x) {

      // Set up the object
      this->hits = 0;
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
      // try going backward
      for (int i = 0; i < this->SD - this->XD + 1; i++) {
        // Start at each index where an equal could start.
        rv += neq_digits(i, 0);
      }

      // Print if you desire
      // this->print_cache();
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

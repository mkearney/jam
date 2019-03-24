
#include <Rcpp.h>
#include <algorithm>
#include <map>

using namespace Rcpp;

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]




// [[Rcpp::export]]
IntegerVector uq_vec(IntegerVector x) {
  std::set<int> s;
  for (int i : x)
    s.insert(i);
  x.assign( s.begin(),  s.end() );
  return x;
}




// [[Rcpp::export]]
CharacterVector uq_chr(CharacterVector x) {
  int n = x.size();
  IntegerVector output = Rcpp::IntegerVector(n);
  for (int i=0; i < n; i++) {
    output[i] = 1;
    if (i > 0) {
      for (int j=i-1; j >= 0; --j) {
        if (x[i] == x[j]) {
          output[i] = 0;
          continue;
        }
      }
    }
  }
  return x[output == 1];
}




// [[Rcpp::export]]
bool f3(IntegerVector x) {
  int n = x.size();
  
  for(int i = 0; i < n; ++i) {
    if (x[i]) return true;
  }
  return false;
}

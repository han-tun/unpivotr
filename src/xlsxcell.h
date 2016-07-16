#ifndef XLSXCELL_
#define XLSXCELL_

#include <Rcpp.h>
#include "rapidxml.h"

class xlsxcell {

rapidxml::xml_node<>* c_; // Provided to constructor

/* celltype celltype;   // TODO: cell type enumeration */

// The remaining variables go to R.

std::string address_;   // Value of node r
int    row_;            // Parsed address_ (one-based)
int    col_;            // Parsed address_ (one-based)
Rcpp::String content_;  // Unparsed value of node v

Rcpp::List  value_;     // Parsed value wrapped in unnamed list
std::string type_;      // Type of the parsed value

// The following are NULL unless relevant to the cell type, but if NULL then
// they should never be sought, because celltype should flag which is relevant.
bool   logical_;        // Parsed value
double numeric_;        // Parsed value
double date_;           // Parsed value
std::string character_; // Parsed value
std::string error_;     // Parsed value

// The following are always used.
double height_;         // Provided to constructor
double width_;          // Provided to constructor

public:

  xlsxcell(rapidxml::xml_node<>* c); // constructor: c is the node of the cell
  std::string address();
  int row();
  int col();
  Rcpp::String content();

};

#endif


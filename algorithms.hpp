///////////////////////////////////////////////////////////////////////////////
// algorithms.hpp
//
// Definitions for three algorithms:
//
// find_dip
// longest_balanced_span
// telegraph_style
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <optional>
#include <string>
#include <vector>

namespace algorithms {

// A "dip" is a series of three elements in a row, where the first and third
// are equal to each other, and the middle element is less than the others.
// For example, the values 8, 5, 8 are considered a dip. This function returns
// an iterator indicating the location of the last dip in values, if any
// exists.
//
// When values contains one dip, returns an iterator pointing to the start of
// that dip (i.e. the first of the three elements in the dip).
//
// When values contains multiple dips, returns an iterator pointing to the
// start of the LAST dip (i.e. the dip at the highest index).
//
// When values does not contain any dip, returns a past-the-end iterator,
// i.e. values.end() .
//
// Note that when values has fewer than 3 elements, it cannot contain a dip, so
// the function always returns values.end() in this case.


std::vector<int>::const_iterator find_dip(const std::vector<int>& values) {
  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
    vector<int>::iterator it = values.begin();
    int FinalDip = -1;
    //For loop to iterate through values
    for(int i = 0; i < values.size() - 2; i++){
        //If statement to find dip
        if(values[i] == values[i+2] && values[i] > values[i+1]){
            //Initialize index of dip
            FinalDip = i;
        }
    }
    //If dip was unable to be found, then return values.end()
    if(FinalDip == -1){
        it = values.end();
    }
    //Locate the dips iterator
    while(FinalDip > 0){
        it++;
        FinalDip--;
    }
    return it;
}

// A span represents a non-empty range of indices inside of a vector of ints,
// stored in a begin iterator and end iterator. Just like in the rest of the C++
// standard library, the range includes all elements in [begin, end), or in
// other words the range includes begin, and all elements up to BUT NOT
// INCLUDING end itself.
class span {
private:
  std::vector<int>::const_iterator begin_, end_;

public:

  // Create a span from two iterators. Both iterators must refer to the same
  // vector. begin must come before end.
  span(std::vector<int>::const_iterator begin,
       std::vector<int>::const_iterator end)
  : begin_(begin), end_(end) {
      assert(begin < end);
  }

  // Equality tests, two spans are equal when each of their iterators are equal.
  bool operator== (const span& rhs) const {
    return (begin_ == rhs.begin_) && (end_ == rhs.end_);
  }

  // Accessors.
  const std::vector<int>::const_iterator& begin() const { return begin_; }
  const std::vector<int>::const_iterator& end  () const { return end_  ; }

  // Compute the number of elements in the span.
  size_t size() const { return end_ - begin_; }
};

// Find the longest "balanced" span in values.
//
// A span is balanced when its sum is zero. For example, the elements
// 5, -8, 2, 1 constitute a balanced span because 5+(-8)+2+1 == 0. Also, the
// elements 0, 0, 0 constitute a balanaced span because 0+0+0 == 0.
//
// When values contains only one balanced span, return that span.
//
// When values contains multiple balanced spans, return the span that is longest
// i.e. contains the most elements. In the even of a tie between two different
// spans of the same length, return whichever comes LAST, i.e. whichever starts
// at the higher index.
//
// When values contains no balanced span, return an empty optional object.
//
// Note that when values is empty, it cannot have any balanced span, so the
// function always returns an empty optional object in this case.
std::optional<span> longest_balanced_span(const std::vector<int>& values) {

  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
    //Initialize best
    vector<int> best;
    //Initialize min, max, sum
    int min = 0, max = 0, sum = 0;
    //For loop to iterate thorugh values
    for(int i = 0; i < values.size(); i++){
        //Initialize sum to equal value[i]
        sum = value[i];
        //For loop to iterate through values
        for(int j = i+1; i <= values.size(); j++){
            //Initialize sum
            sum += values[j];
            //If statement to compare
            if(sum == 0 && (j-i) > (max-min)){
                max = j;
                min = i;
            }
        }
    }
    best.push_back(min);
    best.push_back(max);
    return best;
}

// A "telegraph-style" string is suitable for transmission via
// telegram. This function takes a string s as input, and returns a
// version of the string converted to telegraph-style.
//
// This function makes the following changes:
// - All lower-case letters are converted to upper-case.
// - Punctuation characters !?; are converted to periods.
// - Only some characters are allowed. After the conversions
//   stated above, any character that does not match one of
//   the following allowed categories, is removed:
//   - upper-case letters
//   - digits
//   - space
//   - period
// - There can only ever be one space in a row. Multiple contiguous
//   spaces are replace dwith a single space.
// - The string must end in "STOP.". If s does not already end in
//   "STOP." then add "STOP." to the end.
std::string telegraph_style(const std::string& s) {
    std::string ans = "";
  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
    //For loop to iterate through string
    for(int i = 0; i < s.size(); ++i)
    {
        //Digits
        if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')){
            ans.push_back(s[i]);
        }
        //Lower-case letter
        else if(s[i] >= 'a' && s[i] <= 'z'){
            char c = s[i] + ('A'-'a');
            ans.push_back(c);
        }
        //Space
        else if(s[i] == ''){
            if(ans.back() != ''){
                ans.push_back('');
            }
        }
        //Punctuation
        else if(s[i] == '.' || s[i] == '?' || s[i] == ';' || s[i] == '!'){
            ans.push_back('.');
        }
    }
}

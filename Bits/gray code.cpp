/* pepcoding
1. The gray code is a binary numeral system where two successive numbers differ in only one bit.
2. Given a non-negative integer n representing the total number of bits in the code, print the 
     sequence of gray code. A gray code sequence must begin with 0.
 
 Example:
 Input: 2
 Output: [0,1,3,2]
 Explanation:
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 [0,2,3,1] is also a valid gray code sequence.
 00 - 0
 10 - 2
 11 - 3
 01 - 1
 */

#include<iostream>
#include<vector>
 using namespace std;
 
 int convert(string binary){
     int multiplier = 1;
     int output = 0;
     for(int i=binary.size()-1;i>=0;i--){
        int digit = binary[i] - '0';
        output+=multiplier*digit;
        multiplier*=2;
     }
     return output;
 }
 
 vector<int> grayCode(int n) {
 	vector<string> base= {"0","1"};
 	
 	
    for(int i=1;i<n;i++){
        vector<string> temp;
        
        for(int j=0;j<base.size();j++){
            temp.push_back("0"+base[j]);
        }
        for(int j=base.size()-1;j>=0;j--){
            temp.push_back("1"+base[j]);
        }
        
        base = temp;
    }
    
    vector<int> output;
    for(int i=0;i<base.size();i++){
        output.push_back(convert(base[i]));
    }
    return output;
 }
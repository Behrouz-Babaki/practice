#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istringstream;
using std::vector;
using std::sort;

struct box {
   vector<int> dimensions;
   int id;
};

int lis(const vector<int>& l);
void printlis(const vector<int>& l, vector<int>& order);
bool fits(const struct box& first, const struct box& second);
void printresult(const vector<struct box>&);
bool comp(const struct box& first, const struct box& second);
bool match(const vector<int>& first, 
   const vector<int> & second,
   int current_position,
   vector<int>& matching);
// void printall(const vector<vector<int> >& boxes);
bool verify(const vector<struct box>& boxes, const vector<int>& order);

int main(void){
   string line;
   getline(cin, line);
   while (!cin.eof()){
      istringstream ss(line);
      int numBox, dim;
      ss >> numBox >> dim;
      vector<struct box > boxes;
      for (int boxCounter = 0; boxCounter < numBox; boxCounter++){
         getline(cin, line);
         istringstream ss2(line);
         vector<int> currentBox;
         for (int dimCounter = 0; dimCounter < dim; dimCounter++){
            int val;
            ss2 >> val;
            currentBox.push_back(val);
         }
         struct box currentBoxStruct;
         currentBoxStruct.dimensions = currentBox;
         currentBoxStruct.id = boxCounter;
         boxes.push_back(currentBoxStruct);
      }
      printresult(boxes);
      getline(cin, line);
   }
   return 0;
}


int lis(const vector<struct box>& l){
   size_t n = l.size();
   vector<int> lisVec(n, 1);
   for (int i = 0; i < n; i++){
      int max = 0;

      for (int j = 0; j < i; j++)
         // Is the order of l[j] and l[i] correct?
         if(fits(l[j],l[i]) && lisVec[j] > max)
            max = lisVec[j];

      lisVec[i] = max + 1;
   }
   
   int lis = 0;
   for (int i = 0; i < n; i++)
      if (lisVec[i] > lis)
         lis = lisVec[i];

   return lis;
}

void printlis(const vector<struct box >& l, vector<int>& order){
   size_t n = l.size();
   vector<int> lisVec(n, 1);
   for (int i = 0; i < n; i++){
      int max = 0;

      for (int j = 0; j < i; j++)
         // Is the order of l[j] and l[i] correct?
         if(fits(l[j],l[i]) && lisVec[j] > max)
            max = lisVec[j];

      lisVec[i] = max + 1;
   }
   
   int lis = 0;
   int position = -1;

   for (int i = 0; i < n; i++)
      if (lisVec[i] > lis){
         position = i;
         lis = lisVec[i];
      }

   cout << lis << endl;
   
   vector<int> sequence;
   sequence.push_back(l[position].id);
   for (int i = position; i>=0; i--)
      if(fits(l[i],l[position])){
            position = i;
            sequence.push_back(l[position].id);
         }
         
   for (vector<int>::reverse_iterator itr = sequence.rbegin();
        itr != sequence.rend(); itr++)
      cout << (*itr)+1 << " "; 
   cout << endl;

   order = sequence;
}

bool fits(const struct box& firstBox, const struct box& secondBox){
   const vector<int>& first = firstBox.dimensions;
   const vector<int>& second = secondBox.dimensions;
   vector<int> matching(first.size(), -1);
   return (match(first,second, 0, matching));
}

/**
 * returns true if first box fits in second box
 */

bool match(const vector<int>& first, 
   const vector<int> & second,
   int current_position,
   vector<int>& matching){
   int length = first.size();
   if (current_position == length)
      return true;
   bool result = false;
   for (int counter = 0; !result && counter < length; counter++)
      if (matching[counter] == -1 && second[counter] > first[current_position])
      {
         matching[counter] = current_position;
         result = match(first, second, current_position + 1, matching);
         if (!result)
            matching[counter] = -1;
      }

   return result;
}

bool comp(const struct box & first, const struct box& second){
   vector<int> v1(first.dimensions);
   sort(v1.begin(), v1.end());
   vector<int> v2(second.dimensions);
   sort(v2.begin(), v2.end());
   
   size_t n = v1.size();
   for (size_t counter = 0; counter < n; counter++)
      if (v1[counter] != v2[counter])
         return (v1[counter] < v2[counter]);

   return true;
}

void printresult(const vector<struct box>& boxes){

   vector<struct box > boxes_copy(boxes);
   sort(boxes_copy.begin(), boxes_copy.end(), comp);

   // for (int i = 0; i < boxes_copy.size(); i++){
   //    for (int j = 0; j < boxes_copy[i].size(); j++)
   //       cout << boxes_copy[i][j] << " ";
   //    cout << endl;
   // }
   

   //   cout << lis(boxes_copy) << endl;
   vector<int> sequence;
   printlis(boxes_copy, sequence);
   if (!verify(boxes, sequence))
      cout << "*********************************************" << endl;
   else 
      cout << "OK" << endl;

}


// void printall(const vector<vector<int> >& boxes){
//    size_t n = boxes.size();
//    for (int i = 0; i<n; i++){
//       for (int j = 0; j < n; j++){
//          if(fits(boxes[i], boxes[j]))
//             cout << i+1 << "<" << j+1 << "\t";
//          else
//             cout << i+1 << "?" << j+1 << "\t";
//       }
//             cout << endl;
//    }
         
// }

bool verify(const vector<struct box>& boxes, const vector<int>& order){
   for (int counter = order.size() -1; counter >0 ; counter --)
      if (!fits(boxes[order[counter]], boxes[order[counter-1]])){
         cout << order[counter]+1 << " does not fit in " << order[counter -1]+1 << endl;
         return false;
      }

   return true;
}

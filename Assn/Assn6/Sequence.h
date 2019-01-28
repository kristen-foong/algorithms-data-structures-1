#include <iostream>
#include <cstring>

using namespace std;

class Sequence{
   private:
      string name;
      string sequence;
      int length;
   public:
      Sequence();
      Sequence(string n, string s);
      int length();
      string getGene();
      string getToLength();
      string makeSequence(int l);
      friend istream& operator >> (istream& inputStream, Sequence&);
      friend istream& operator << (istream& inputStream, Sequence&);
};
void operator ^ (unsigned len1, unsigned len2);
void operator == (string seq1, string seq2);
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Sequence.h"

using namespace std;

int main(){
   Sequence seq1("name1","ACCUAG-"); //creates a sequence
   Sequence seq2("name2","AC-AAG-"); //creates a sequence
   Sequence seq3 = makeSequence(8); // uses makeSequence to make a sequence
   seq1 == seq2; // score should be (1+1+(-1)+(-2)+1+1+0) = 1
   sequence.getGene(); //gets a gene if there is one in the sequence, otherwise returns nothing
}
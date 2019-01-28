#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Sequence.h"

using namespace std;

//input: none
//output:none
//sets the name and sequence to nothing
Sequence::Sequence(){
   Sequence(0,0);
}

//input: the name and the sequence
//output: none
//assigns n to name and s to sequence
Sequence::Sequence(string n, string s){
   name = n;
   sequence = s;
}

//input: none
//output: the length of the sequence
//gets the length of the sequence
int Sequence::length(){
   return sequence.length;
}

//Input: none
//Output: the gene between 'AUG' and 'UGA', 'UAA', or 'UAG'
//gets the gene between 'AUG' and the ending codons
string Sequence::getGene(){
   string gene = "";
   for(int i = 2; i < sequence.length-2; i++){
      if(sequence[i-2] == 'A' && sequence[i-1] == 'U' && sequence[i] == 'G'){
         if(sequence[i] == 'U'){
            if(sequence[i+1] == 'A'){
               if(sequence[i+2] == 'G'){
                  gene += sequence[i];
               }else if(sequence[i+2] == 'A'){
                  gene += sequence[i];
               }
            }else if(sequence[i+1] == 'G'){
               if(sequence[i+2] == 'A'){
                  gene += sequence[i];
               }
            }
         }
      }
   }
   return gene;
}

//input: sequence one and sequence 2
//output: the sequences at their appropriate lengths
//makes the sequences the same length by adding -'s to the end/beginning
string Sequence::getToLength(string seq1, string seq2){
   
}

//input: length
//output: a randomly generated sequence of that length
//makes a sequence to the specified length and returns it
string Sequence::makeSequence(int length){
   srand(time(0));
   string seq = "";
   for(int i = 0; i < length; i++){
      string nucleotide = "ACGU-";
      int r = rand()%5;
      seq += nucleotide[r];
   }
   return seq;
}

//input: sequence one and two
//output: a score of the two sequences
//compares the two sequences and scores them
void operator==(string seq1, string seq2){
   if(seq1.length != seq2.length){
      getToLength(seq1, seq2);
   }
   int score = 0;
   for(int i = 0; i < seq1.length; i++){
      if(seq1[i] == seq2[i]){
         score += 1;
      }else if(seq1[i] == '-' || seq2[i] == '-'){
         if(seq1[i] == '-' && seq2[i] == '-'){
            score += 0;
         }else{
            score += -1;
         }
      }else{
         score += -2;
      }
   }
   cout << score;
}

//input: length 1 and length 2
//output: the length of the longer sequence
//finds the length of the longer sequence and returns it
unsigned operator ^ (int len1, int len2){
   if(len1 > len2){
      return len1;
   }else{
      return len2;
   }
}

//input: inputStream and the sequence
//output: inputStream
//reads in a name and a sequence
istream& operator >> (istream& inputStream, Sequence& seq){
   unsigned seqlen;
   string n;
   inputStream >> n >> seqlen;
   seq.name = n;
   seq.length(seqlen);
   return inputStream;
}

//input: outputStream and sequence
//output: the name and a randomly generated sequence
//prints out the name and sequence
ostream& operator << (ostream& outputStream, Sequence& seq){
   outputStream << seq.name << endl << "> " << seq.sequence;
   return outputStream;
}
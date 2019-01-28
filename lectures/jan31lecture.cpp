#include <iostream>

using namespace std;

/* Quiz review

Part 1)

Multiplications in base case: 2
Recurrence relation:

T(1) = 2
T(n) = 3 + T(n-1) // 3 multiplications in the return, recursive call ONCE (hence one T) and then calling n-1

Part 2)

3 + 3 + T(n-2)
3 + 3 + 3 + T(n-3)
3 + 3 + 3 + 3 + T(n-4)
// see pattern?
(n-1)*3 + T(1)
3(n-1) + 2
3n - 3 + 2
3n-1 // number of operations it does

Part 3)

O(n) because duh drop all constants you fucking useless idiot kristen good god 

*/

/* Midterm format

All written

- Tracing algorithms (what does the code do)
- What is this outcome if you have this input
- Describe what this does in English
- Solve a problem with recursion
- General coding problems eg. write a function that does x
- There will be a question just like the fct question above
- No mult choice, no fill in the blank, etc. 
- Should know the runtimes of all the sorts & searches that have happened. KNOW BIG O & WORST CASE
- Ignore big O for Bucket Sort

*/
//recursively
node *reverse(node *p){
   if(p == nullptr){
      return nullptr;
   }
   node *tail = p->next;
   //one node in the list is already reversed list
   if(tail == nullptr){
      return p;
   }
   node *head = reverse(tail);
   tail->next = p;
   
   p->next = nullptr;
   return head;
}

//iteratively
node*reverseI(node *p){
   node *curr, *next;
   //if p is empty or if there is only one node, return p
   if(p == nullptr || p->next == nullptr){
      
   }
}




//next

class Time{
   public:
      Time(int h, int m, int s);
      Time();
      Time(int h);
      const Time operator - (const Time& t2);
      const Time operator + (const Time& t2);
      bool operator == const
}


const Time Time::operator

bool Time operator

const Time Time:: operator - (const Time& t2){
   int borrow = 0;
   int s = secs - t2.secs;
   if(s<0){
      
   }
}

Time::Time(): hrs(0), mins(0), secs(0){
}

ostream& operator

const Time aMPMSwitch(Time& t){
   return Time(t.hrs, t.mins, t.secs) + 12;
}

int main(){
   Time t1(16,30,0);
   Time t2(18,20,0);
   cout << t1 + t2 << endl;
   cout << t2 - t1 << endl;
   cout << aMPMSwitch(t1) << endl;
   cout << t1 - 3 << endl;
   Time t3 = t1 + Time(1,50,0);
   //dead so dead
}
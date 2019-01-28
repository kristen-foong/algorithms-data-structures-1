
class Money {
   public: 
      Money(unsigned d, unsigned c);
      Money operator + (Monet m1);
      void operator++(int);
      void operator++();
      unsigned getDollars() const {return dollars;}
      unsigned getCents() const {return cents;}
   private:
      unsigned dollars;
      unsigned cents;
}

Money::Money(unsigned d, unsigned c){
   dollars = d;
   cents = c;
}

Money Money::operator + (Money m1){
   unsigned c = m1.getCents() + cents;
   unsigned d = m1.getDollars() + dollars + c/100;
   return Money(d,c%100);
}

void Money::operator++(int){
   unsigned c = cents + 5;
   cents = c%100;
   dollars = dollars + c/100;
}

void Money::operator++(){
   dollars++;
}
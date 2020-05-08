#include <stdio.h>

typedef unsigned long long Set;
void init(Set *set);
void add(Set *set, int i);
void has(Set set, int i);
Set setUnion(Set a, Set b);
Set setIntersect(Set a, Set b);
Set setDifference(Set a, Set b);


int main()
{
  Set a, b, c;
 
  init(&a);
  add(&a, 3);
  add(&a, 5);
  add(&a, 2);

  init(&b);
  add(&b, 3);
  add(&b, 7);
  add(&b, 9);
 printf("%lld\n%lld\n", a, b);
  c = setUnion(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setIntersect(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 11);
  has(c, 7);
  has(c, 9);
 
  c = setDifference(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 10);
 
  return 0;
}

void init(Set *set){
    *set = 0;
}
void add(Set *set, int i){
    Set a = *set & 1LL<<i;
    if(!a)*set += 1LL<<i;
}
void has(Set set, int i){
    printf("set %s %d\n",(set & (1LL<<i))?"has":"does not have" ,i);
}
Set setUnion(Set a, Set b){
    Set c = a|b;
    return c;
}
Set setIntersect(Set a, Set b){
    Set c = a&b;
    return c;
}
Set setDifference(Set a, Set b){
    Set c = a^b;
    return c;
}





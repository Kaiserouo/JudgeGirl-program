typedef struct employee {
  char first_name[32];
  char last_name[32];
  struct employee *boss;
} Employee;

int follow(Employee *emp1, Employee *emp2){
    Employee *last = emp1;
    Employee *now = emp1->boss;
    while(last != now){
        if(!strcmp(now->first_name, emp2->first_name) && !strcmp(now->last_name, emp2->last_name)){
            return 1;
        }
        last = now; 
        now = now->boss;
    }
    return 0;
}
Employee *boss(Employee *emp){
    Employee *last = emp;
    Employee *now = emp->boss;
    while(last != now){
        last = now; 
        now = now->boss;
    }
    return now;
}
int relation(Employee *employee1, Employee *employee2){
    if(follow(employee1, employee2))    return 1;
    else if(follow(employee2, employee1))    return 2;
    else if(boss(employee1) == boss(employee2))  return 3;
    else return 4;
}

// Go and read the main() function 
// Then come back here when you reach the calls to function1() and function2() in main()

int function1(int const & param){			 // reference to const int. Typically an input parameter
   
  // Reading from right to left :
  // param is a reference...
  // a reference to what?
  // param is a reference to a const...
  // a constant what?
  // param is a reference to a const int (we cannot change the value of param)
  
  // Uncomment the line hereafter to get a compile time error
  // param++;
  return 1+param;
}


int function2(int & const param){ // invalid?
  
  // Reading from right to left :
  // param is a constant...
  // a constant what?
  // param is a constant reference...
  // a reference to what?
  // param is a constant reference to an int
  // param is a constant reference to a non constant int (we can change the value of param)

  // IMPORTANT NOTE
  // const reference to a non-const int is invalid in C++ because reference itself can't be const-qualified
  // It does not compile with clang and gcc (I did some testing in compiler explorer). The message says : Const qualifier may not be applied to reference
  // MSVC generates a warning. The message says : C4227 anachronism used. Qualifier on reference are ignored

  param++;
  return 2+param;
}




int main() {
  
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // Some tests with int

  int obj_0;
  
  const int obj_1 = 1;                  // can't change the value
  // Reading from right to left :
  // obj_1 is an int...
  // obj_1 is an int which is constant

  // Uncomment the line hereafter to get a compile time error
  //obj_1 = obj_0;                     // Error : cannot assing to a variable that is const
  



  int const obj_2 = 2;                 // same as const int obj_1
  // Reading from right to left :
  // obj2 is a constant...
  // obj2 is a constant int

  // Uncomment the  line hereafter to get a compile time error
  //obj_2 = obj_0;                      // Error : cannot assing to a variable that is const




  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // Some tests with objects

  struct Object {
    int data_ = 0;
  };

  Object obj0;
  Object obj00;




  const Object* obj1 = &obj0;           // can't change data, can change the poitee
  // Reading from right to left :
  // obj1 is a pointer (the * tells us obj1 is a pointer)
  // a pointer to what?
  // a pointer to an Object...
  // a pointer to an Object which is const (whose value cannot be modified)

  obj1 = &obj00;                        // This is OK, obj1 can point to an other Object
  // Uncomment the line hereafter to get a compile time error
  // obj1->data_ = 42;                  // Error : cannot be modified because it is being accessed through a cont object




  Object const* obj2 = &obj0;          // same as const Object* obj - can't change data, can change the poitee
  // Reading from right to left :
  // obj2 is a pointer (the * tells us this is a pointer)
  // a pointer to what?
  // a pointer to a const...
  // a pointer to a const Object (whose value cannot be modified)

  obj2 = &obj00;                        // This is OK, obj1 can point to an other Object
  // Uncomment the line hereafter to get a compile time error
  // obj2->data_ = 42;                 // Error : cannot be modified because it is being accessed through a cont object




  Object* const obj3 = &obj0;          // can't change pointee, can change the value
  // Reading from right to left :
  // obj3 is constant 
  // a constant what?
  // a constant pointer (the * tells us this is a pointer)
  // a constant pointer to what?
  // a constant pointer to an Object (whose value can be modified)
    
  obj3->data_ = 42;		                 // This is OK
  // Uncomment the line hereafter to get a compile time error
  // obj3 = &obj00;                    // Error : expression must be a modifiable lvalue
  


  const Object* const obj4 = &obj0;  // can't change data nor the pointer
  // Reading from right to left :
  // obj4 is constant 
  // a constant what?
  // a constant pointer (the * tells us this is a pointer)
  // a constant pointer to what?
  // a constant pointer to an Object... 
  // a constant pointer to an Object which is constant

  // Uncomment either line to get a compile time error
  // obj4->data_ = 42;                  // Error 
  // obj4 = &obj00;                     // Error : expression must be a modifiable lvalue




  Object const* const obj5 = &obj0;  // same as const Object* const - can't change data nor the pointer
  // Reading from right to left :
  // obj5 is constant 
  // a constant what?
  // a constant pointer (the * tells us this is a pointer)
  // a constant pointer to what?
  // a constant pointer to a constant 
  // a constant pointer to a constant what?
  // a constant pointer to a constant Object
  
  // Uncomment either line to get a compile time error
  // obj5->data_ = 42;		              // Error 
  // obj5 = &obj00;                     // Error : expression must be a modifiable lvalue



  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // Some tests with function calls

  int result1 = function1(12);
  int result2 = function2(result1);

  
  
  
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // I hope this help :-)
  
  return 0;
}

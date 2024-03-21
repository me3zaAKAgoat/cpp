<h1 align="center"><bold>CPP</bold></h1>
<p align="center">42 cpp modules.</p>

## Headers

#### \<iostream\>

- `std::cin.clear()` resets error state flags.
- `std::cin.ignore()` is used to discard characters from the cin buffer. most often used to clear newlines from the buffer.
- `std::cin.eof()` returns true if the the input stream has reached EOF, false otherwise.
- `std::cin.bad() / std::cin.good()` can be used to check if an error occured while reading the input.
- `std::endl / std::flush` can be used to flush `std::cout`

#### \<iomanip\>

the iomanip header provides a lot of useful input output stream tools such as:

- `std::boolalpha`: Controls the output format of boolean values, displaying them as "true" or "false" instead of 1 or 0.
- `std::hex` and `std::oct`: Changes the base for integer output to hexadecimal or octal, respectively.

## Identifiers

#### **Const member functions**

the `const` identifier if put after the name a member function sets a compilation time guarantee that the function definition does not modify any of the objects attributes.

#### **Public Members**

Public members of a class are accessible from any part of the program, including external code. They can be accessed through an instance of the class or via inheritance in derived classes.

#### **Private Members**

Private members of a class are not accessible from outside the class. They are hidden from external code, including derived classes. Only member functions of the same class can access private members.

#### **Protected Members**

Protected members of a class are similar to private members in that they are not accessible from external code. However, they are accessible to derived classes. This means that if you have a class hierarchy (base class and derived class), the derived class can access the protected members of the base class.

#### **Override**

- Catches errors such mismatch in signature of virtual and concrete function declarations, or lack of virtual function to begin with.
- Also giga good for readability.

## Orthodox Canonical Form

- default constructor.
- copy constructor
  #### syntax
  ```cpp
  MyClass& operator=(const MyClass& other)
  {
  	if (this != &other)
  	{
  		// copy members
  	}
  	return *this;
  }
  ```
  data being the only member.
- copy assignment operator
  #### syntax
  ```cpp
  MyClass(const MyClass& other)
  {
      data = other.data;
  }
  ```
- default destructor.

## Object References

- Pointers are nullable.
- References do not outlive their objects lifetime, once the object is destroyed out of scope the reference becomes invalid and usage of them will lead to undefined behaviour.
  - this mainly comes from the fact that a pointer is a mutable variable that can be given different values or be set to NULL or stay unitiliazed untill needed.
- References can be thought of as an alias through which the object can be accessed.
  - the main usage of references is to allow for a more robust way of passing objects and mutating them inside of a another scope.

## Good practices

- ditch C macros for **static const members** of classes as:
  - they are more type safe.
  - const correctness.
  - they usually convey more information by virtue of being scoped to a class.
  - they are safer to use.
  - theres less "duplication" as macros are just placeholders
- new T[0] does guaraentee the return of a valid pointer unlike C!
- BE WARY OF USAGE OF THE EXIT FUNCTION IN C++, the destructors will not be called before exiting!!!!!

  ```cpp
  int main()
  {
      ClapTrap xd("CT");

      xd.attack("civilians");
      exit(0);
  }
  ```

  this example does not call the destructor, removing the exit will allow the destructor to be called.

## Floating point numbers (IEEE 754)

Floating point numbers are the computer representation of real numbers.

this is the bit representation of a float:

**|s|e|e|e|e|e|e|e|e|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|m|**

#### s : the sign bit.

#### e : the exponent bits.

> **Note**
> the exponent is biased as in whenever you have a positive exponent you should add 127 for single precision representation (1023 for double precision)

#### **m** : the mantissa bits.

> **Note**
> the mantissa always has an assumed hidden 1 at the left most side the mantissa, for efficiency purposes.

`n = (-1)^S * 1.M * 2^E`

## Fixed point representation

`1 * 2^4 + 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0* 2^0 + 1 * 2^-1 = 26.5`

So the number 26.5 would be stored in the Fixed point representation in the following manner :
{
raw bits : 110101
fractional bits : 1
}

The Fixed point representation of real numbers takes advantage of the all the efficient arithmetic and simplicity of integers.

Fixed point numbers have a pre defined precision, have lower memory overhead and deterministc results. But they suffer from lack of range.

## Ad-hoc Polymorphism

Ad-hoc polymorphism refers to the ability of a function or operator to behave differently based on the types of it's arguments. Which is commonly achieved through function overloading.

## Inheritance

### Inheritance Access Specificers

- Public Inheritance: Base class public members remain public in the derived class, protected members remain protected, and private members are inaccessible.
- Protected Inheritance: Base class public and protected members become protected in the derived class, and private members are inaccessible.
- Private Inheritance: Base class members become private in the derived class.

### Method Overriding

- Derived classes can have their own implementation of members of the base class.
- Overriding is achieved by declaring a function with the same name and signature in the derived class.

### Slicing

- Object slicing occrs when assigning a derived class object to a base class object, causing loss of derived class-specific data.

```cpp
int main()
{
	Derived derObj;
	Base basObj = derObj;
}
```

In the code above, the copy assignment causes creation of a new Base object that has no information on the specific members of the derObj.

```cpp
int main()
{
	Derived derObj;
	Base *basePtr = derObj;
	Base& baseRef = derObj;
}
```

Conversly, in this code there's no new object created, and the accessing of members of the derived object is valid because pointers and references maintain a connection to the object's original derived class type.

### Pure Virtual Function

Pure virtual functions are functions that don't have an implementation in their class's scope.

```cpp
	virtual void f()=0;
```

### Abstract Class

An abstract class is a class that contains at least 1 pure virtual function, therefore an absract class cannot be instantiated on its own, but used as a base class for other classes to inherit from.

### Interface

An interface is a class that contains only pure virtual functions and serves as a contract for the set of methods that a class must provide.

### nullptr vs NULL

- nullptr has type std::nullptr_t. It's implicitly convertible to any pointer type. Thus, it'll match std::nullptr_t or pointer types in overload resolution, but not other types such as int.
- the main cause for this update from C is that C's NULL ptr was just 0 the integer which could cause ambiguity for overloaded functions such as:

```cpp
#include <iostream>

void OverloadedFunction(int* ptr)
{
    std::cout << "Received a pointer." << std::endl;
}

void OverloadedFunction(int value)
{
    std::cout << "Received an integer." << std::endl;
}

template<typename T>
void TemplatedFunction(T arg)
{
    OverloadedFunction(arg);
}

int main()
{
    TemplatedFunction(nullptr);  // Calls OverloadedFunction(int*) due to nullptr's type deduction
    TemplatedFunction(NULL);     // Ambiguity arises between pointer and integer overloads
    TemplatedFunction(5);        // Calls OverloadedFunction(int) for an integer argument

    return 0;
}
```

## Type casting

### static_cast

- static casting involves casting between related types in a conform way using the static_cast<T>() function.
- unsafe for conversions of polymorphic class hierarchies because object type may not be knonw until runtime.
- only suitable for upcasting.

### C style casting

- C style casting is outdated, unsafe compared to static casting as the implementation of these casts can vary depending on the context (compiler/architecture).

### dynamic_cast

- dynamic casting provides runtime type checking which makes it more suitable for use within polymorphic class hierarchies.

### const_cast

- allows for modification of constness of variables.

### reinterpret_cast

- allows for low level casting between unrelated types, usually used in low level systems programming and is considered unsafe, as it bypasses the type system.

## STL containers

- STL containers provide multiple data structures with very modular interfaces, you can find types such as MAPS, DOUBLY-LINKED LISTS, LINKED LISTS, DYNAMIC SIZE ARRAYS (vector) and much more.
- the interchangability of interfaces is seen in iterators primarly. iterators are pointers to elements of the containers, through them we can iterate and manipulate items of the container.
- most of STL algorithms work with iterators primarly.

//  Q1: What is a static data member in C++?
// ✅ “It’s a variable declared as static inside a class. Unlike normal variables, it's shared among all objects. There's only one copy of the variable, and it's stored in the class's memory, not individual object memory.”

// 🔹 Q2: Can a static member function access non-static members?
// ❌ No.

// ✅ “Static functions cannot access non-static members because they don’t operate on a specific object — they don’t have access to the this pointer.”

// 🔹 Q3: Why do we define static variables outside the class?
// ✅ “Because memory for static variables is allocated separately from object memory, and only once for the class. So, it needs to be defined outside so the compiler can allocate space.”

// 🔹 Q4: Can you call a static function without creating an object?
// ✅ Yes.

// ✅ “Yes, we can call it using ClassName::FunctionName(), because it belongs to the class itself — not any individual object.”

// 🔹 Q6: Can you use static functions to access private static variables?
// ✅ “Yes, static member functions can access private static variables because they're part of the same class.”

// Q1: What is an array of objects in C++?
// ✅ “It’s like an array of integers or strings, but instead of storing values, it stores objects. You can create multiple instances of a class in a single line using an array.”

// 🔹 Q2: How do static variables behave when used in an array of objects?
// ✅ “The static variable is shared among all the objects, even when stored in an array. There's still only one copy of the variable.”

// 🔹 Q3: Is count truly representing employee number?
// ✅ “Not exactly. Since count is shared, it only tells total number of employees so far, not the number of the current object.”

//  Q1: Can we pass objects as function arguments in C++?
// ✅ “Yes, objects can be passed just like variables. They’re usually passed by value or reference.”

// Q: Can we overload constructors in C++?
// Yes! You can create multiple constructors with different parameters.

// Q: What if we don’t write any constructor?
// C++ provides a default constructor automatically that does nothing.
// But if you define any constructor manually, the default one won’t be generated.

// Q: Can a constructor be private?
// Yes, for design patterns like Singleton, but generally constructors are public.

// Q: Can constructors return a value?
// No! They don’t return anything — not even void.

// 1.Arrow Function -

/* Arrow functions have a more compact syntax compared to traditional function expressions and they are
especially useful when you need to create anonymous functions or when you want to maintain the lexical
value of 'this' */

/*use 1 - Anonymous functions are functions without a name. They are commonly used in situations 
where you need to pass a function as an argument to another function, like in higher-order functions such as 
map, filter, and reduce*/
const add = (a, b) => a + b; //sinle line me return nhi likhne ka need4
/* use2 - Arrow functions, on the other hand, have a lexical this binding, which means 
that the value of this is determined by the surrounding scope in which the arrow function is defined. 
This behavior is especially useful when dealing with object methods or event handlers, 
as it allows you to capture the value of this from the enclosing scope without having to explicitly bind it */
const obj = {
    name: "John",
    sayHello: function () {
      // Using a regular function expression
      setTimeout(function () {
        console.log("Hello, " + this.name); // 'this' refers to the global object (or undefined in strict mode)
      }, 1000);
  
      // Using an arrow function
      setTimeout(() => {
        console.log("Hello, " + this.name); // 'this' refers to the 'obj' object ('John')
      }, 1000);
    },
  };
  obj.sayHello();
// 1.obj ka key say hello ek normal function likho and usme ek arrow function likho
// phir call obj.key();
  // Traditional function expression with 'this'
const obja = {
    value: 42,
    getValue: function () {
      return this.value;
    }
  };
  
  // Arrow function maintaining lexical 'this'
  const objaArrow = {
    value: 42,
    getValue: function () {
      // Using arrow function here maintains the context of 'this'
      return () => this.value;
    }
  };
  
  console.log(obja.getValue()); // Output: 42
  console.log(objaArrow.getValue()()); // Output: 42
  
//                                        ARRAY METHODS -
/*1.Map:
The map() method creates a new array by applying a function to each element of the original array. 
It returns a new array with the same length as the original, where each element is the result 
of applying the function to the corresponding element of the original array. */
const numbers = [1, 2, 3, 4, 5];
const squaredNumbers = numbers.map((num) => num * num);
console.log(squaredNumbers); // Output: [1, 4, 9, 16, 25]
//2.
//The filter() method creates a new array with all elements that pass the test implemented by the provided function.
//It returns a new array containing only the elements for which the function returns true.
const numb = [1, 2, 3, 4, 5];
const evenNumbers = numb.filter((num) => num % 2 === 0);
console.log(evenNumbers); // Output: [2, 4]
//3.
//The reduce() method applies a function to each element of the array to reduce it to a single value.
//It takes an accumulator and the current element as arguments, and the result is carried over to each iteration.
const number = [1, 2, 3, 4, 5];
//accumulator = 0(prevSum) , currentvalue = element of array
const sum = number.reduce((accumulator, currentValue) => accumulator + currentValue, 0)
console.log(sum); // Output: 15 (1 + 2 + 3 + 4 + 5)
//4.
//The forEach() method executes a provided function once for each array element. It does not return anything;
//it simply performs the specified operation on each element of the array.
const numbes = [1, 2, 3, 4, 5];
numbes.forEach((num) => {
  console.log(num * 2);
});
// Output:
// 2
// 4
// 6
// 8
// 10


// In JavaScript, async/await is a modern syntax for working with asynchronous operations and promises.
//  It provides a more readable and synchronous-like way to handle asynchronous code without using callbacks. 
//  The async keyword is used to define an asynchronous function, 
// and the await keyword is used to wait for the completion of a promise inside that function.
//2.
// They use the async keyword before the function declaration, and within the function body, 
// they can use the await keyword to pause the execution of the function until a promise is resolved or rejected.
// As a result, asynchronous functions enable handling asynchronous operations, such as reading from a file,
// making network requests, or performing other time-consuming tasks, without blocking the main
// thread of execution.

//1.Example 1
function fetchUserData() {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        const userData = { name: 'John', age: 30 };
        resolve(userData);
        // reject(new Error('Failed to fetch user data'));
      }, 2000);
    });
  }
  
  // Using async/await

  async function getUserData() {
    try {
      const userData = await fetchUserData();
      console.log(userData);
    } catch (error) {
      console.error(error);
    }
  }
  
  getUserData();
  console.log("next");
  //2.Example 2
  function simulateAPICall(ms) {
    return new Promise((resolve,reject) => {
      setTimeout(() => {
        resolve('API call successful'); //resolve me jo bhejenge usse resolve hoga promise
        //usually send key-value pairs jisko hm data.json() krte hai normally
      }, ms);
    });
  }
  
  async function fetchDataFromAPI() {
    console.log('Start API call');
    const response = await simulateAPICall(2000); // Simulating an API call that takes 2 seconds
    console.log('API response:', response);
    return response;
  }
  
  fetchDataFromAPI();
  console.log('After calling fetchDataFromAPI');

//application of await-
// In JavaScript, the program execution after an await statement within an async function is paused until the
// awaited promise is resolved or rejected. The await keyword can only be used inside an async function, 
// and it is used to wait for the completion of a promise-based asynchronous operation.

// (bas async funtion ke andar ka chij rukta hai -> to remove Callback Hell) (BAKI CHALTE HI H)
//BEST EXAMPLE-

function delay(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

async function asyncFunction() {
  console.log('Start of async function');

  await delay(2000); // Pauses execution for 2 seconds

  console.log('After the await statement');

  await delay(1000); // Pauses execution for another 1 second

  console.log('End of async function');
}

console.log('Before calling asyncFunction');
asyncFunction();
console.log('After calling asyncFunction');

//OUTPUT
// Before calling asyncFunction
// Start of async function
// After calling asyncFunction
// Pauses for 2 seconds
// After the await statement
// Pauses for 1 second
// End of async function


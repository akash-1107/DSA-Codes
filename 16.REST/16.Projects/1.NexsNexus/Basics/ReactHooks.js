//UseState - 
// The useState hook returns an array with two elements: 
// the current state value and a function to update that state.
// const [state, setState] = useState(initialState);
//ye sb JSX hai toh khi bhi javascript use krne ke liye use Curly Braces {count} or {fxn}
import React, { useState } from 'react';

const Counter = () => {
  // Declare a state variable named 'count' with an initial value of 0
  const [count, setCount] = useState(0);

  const increment = () => {
    // Update the 'count' state by increasing it by 1
    setCount(count + 1);
  };

  const decrement = () => {
    // Update the 'count' state by decreasing it by 1
    setCount(count - 1);
  };

  return (
    <div>
      <h2>Counter: {count}</h2>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement}>Decrement</button>
    </div>
  );
};

export default Counter;


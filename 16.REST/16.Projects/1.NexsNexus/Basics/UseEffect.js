//2.UseEffect - Here's a breakdown of the elements:

// The first argument is a function that contains the side effect logic. 
// This function will be executed after every render cycle.
// The optional second argument, dependencies, is an array that holds values. 
// If any of these values change between renders, the effect function will re-run. 
// If this argument is not provided, the effect will run after every render, just like with componentDidUpdate.

// Now, let's look at an example of how to use the useEffect hook to
//  fetch data from an API in a functional component:
import React, { useState, useEffect } from 'react';

const DataFetcher = () => {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    // Function to fetch data from an API
    const fetchData = async () => {
      try {
        const response = await fetch('https://api.example.com/data');
        const data = await response.json();
        setData(data);
        setLoading(false);
      } catch (error) {
        console.error('Error fetching data:', error);
        setLoading(false);
      }
    };

    fetchData(); // Call the fetchData function when the component mounts

    // Optional cleanup function to cancel any pending requests if the component unmounts before the fetch is complete
    return () => {
      // Perform any necessary cleanup here (e.g., aborting ongoing API requests)
    };
  }, []); // Empty dependency array indicates that the effect runs only once, on component mount
  //depency array me jo v value denge uske change pe chalne lagega use effect so empty mtlb ki 
  //bss refresh hone pe chalne do
//only refresh one pe useEffect call mst

  if (loading) {
    return <div>Loading...</div>;
  }


  return (
    <div>
      <h2>Data from API:</h2>
      <pre>{JSON.stringify(data, null, 2)}</pre>
    </div>
  );
};

export default DataFetcher;


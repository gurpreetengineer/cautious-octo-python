function interpolationSearch(arr, target) {
    let low = 0;
    let high = arr.length - 1;
  
    while (low <= high && target >= arr[low] && target <= arr[high]) {
      const pos = Math.floor(
        low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])
      );
  
      if (arr[pos] === target) {
        return pos;
      } else if (arr[pos] < target) {
        low = pos + 1;
      } else {
        high = pos - 1;
      }
    }
  
    return -1; // target not found
  }
  
  // Example usage:
  const arr = [1, 3, 5, 7, 9, 11];
  const target = 7;
  const index = interpolationSearch(arr, target);
  console.log(index); // 3
  
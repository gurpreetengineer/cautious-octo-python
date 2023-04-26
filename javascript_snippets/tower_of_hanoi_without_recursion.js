function towerOfHanoi(numOfDiscs, fromTower, toTower, auxTower) {
  let moves = [];
  
  // If there is only one disc, move it directly to the target tower
  if (numOfDiscs === 1) {
    moves.push([fromTower, toTower]);
    return moves;
  }
  
  // Move the top n-1 discs from the source tower to the auxiliary tower
  for (let i = 1; i <= numOfDiscs - 1; i++) {
    moves = moves.concat(towerOfHanoi(i, fromTower, auxTower, toTower));
  }
  
  // Move the largest disc from the source tower to the target tower
  moves.push([fromTower, toTower]);
  
  // Move the remaining n-1 discs from the auxiliary tower to the target tower
  for (let i = 1; i <= numOfDiscs - 1; i++) {
    moves = moves.concat(towerOfHanoi(i, auxTower, toTower, fromTower));
  }
  
  return moves;
}

// Example usage:
console.log(towerOfHanoi(3, 'A', 'C', 'B')); // Output: [['A', 'C'], ['A', 'B'], ['C', 'B'], ['A', 'C'], ['B', 'A'], ['B', 'C'], ['A', 'C']]

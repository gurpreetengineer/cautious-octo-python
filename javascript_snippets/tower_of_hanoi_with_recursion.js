function towerOfHanoi(n, sourceRod, destinationRod, auxiliaryRod) {
  if (n === 1) {
    console.log(`Move disk 1 from ${sourceRod} to ${destinationRod}`);
    return;
  }
  
  towerOfHanoi(n - 1, sourceRod, auxiliaryRod, destinationRod);
  console.log(`Move disk ${n} from ${sourceRod} to ${destinationRod}`);
  towerOfHanoi(n - 1, auxiliaryRod, destinationRod, sourceRod);
}

// example usage:
towerOfHanoi(3, 'A', 'C', 'B');

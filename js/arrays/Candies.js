//https://www.hackerrank.com/challenges/candies/problem

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', function() {
  inputString = inputString
    .replace(/\s*$/, '')
    .split('\n')
    .map(str => str.replace(/\s*$/, ''));

  main();
});

function readLine() {
  return inputString[currentLine++];
}

// Complete the candies function below.
function candies(n, arr) {
  let can = new Array(n);
  can.fill(1);
  /* Wrong approach, this is one-way approach, below both ways approach works
    for(let i=0;i<n-2;i++){
        let a = arr[i];
        let b = arr[i+1];
        let c = arr[i+2];
        if(b > a && can[i+1]<=can[i]){
            can[i+1] = can[i]+1;
        }
        else if(b < a && can[i+1]>=can[i]){
            can[i] = can[i+1] + 1;
        }
        if(b > c && can[i+1]<=can[i+2]){
            can[i+1] = can[i+2] + 1;
        }
        else if(b < c && can[i+1]>=can[i+2]){
            can[i+2] = can[i+1] + 1;
        }
        
    //console.log(can);
    } */

  for (let i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1]) {
      can[i] = can[i] + can[i - 1];
    }
  }

  for (let i = n - 2; i >= 0; i--) {
    if (arr[i] > arr[i + 1] && can[i] <= can[i + 1]) {
      can[i] = can[i + 1] + 1;
    }
  }
  return can.reduce((acc, el) => el + acc, 0);
}

function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const n = parseInt(readLine(), 10);

  let arr = [];

  for (let i = 0; i < n; i++) {
    const arrItem = parseInt(readLine(), 10);
    arr.push(arrItem);
  }

  const result = candies(n, arr);

  ws.write(result + '\n');

  ws.end();
}

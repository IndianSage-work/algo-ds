//https://www.hackerrank.com/challenges/crush/problem

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString
    .replace(/\s*$/, '')
    .split('\n')
    .map(str => str.replace(/\s*$/, ''));

  main();
});

function readLine() {
  return inputString[currentLine++];
}

// Complete the arrayManipulation function below.
function arrayManipulation(n, queries) {
  let arr = [];
  arr[n - 1] = 0;
  arr.fill(0);
  for (const query of queries) {
    let [a, b, k] = query;
    arr[a - 1] += k;
    arr[b] -= k;
  }
  let max = 0;
  let curr = 0;
  for (const el of arr) {
    curr = curr + el;
    if (curr > max) {
      max = curr;
    }
  }
  return max;
}

function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const nm = readLine().split(' ');

  const n = parseInt(nm[0], 10);

  const m = parseInt(nm[1], 10);

  let queries = Array(m);

  for (let i = 0; i < m; i++) {
    queries[i] = readLine()
      .split(' ')
      .map(queriesTemp => parseInt(queriesTemp, 10));
  }

  let result = arrayManipulation(n, queries);

  ws.write(result + '\n');

  ws.end();
}

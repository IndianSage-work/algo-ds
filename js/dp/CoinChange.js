//https://www.hackerrank.com/challenges/coin-change/problem

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function() {
  inputString = inputString.split('\n');

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

function getWays(n, c) {
  let memo = new Map();
  return countWays(n, c, 0, memo);
}

function countWays(money, coinsArray, idx, memo) {
  if (money === 0) {
    return 1;
  }
  if (idx >= coinsArray.length) {
    return 0;
  }
  let key = `${money}-${idx}`;
  if (memo.has(key)) {
    return memo.get(key);
  }
  let amtWithCoin = 0;
  let ways = 0;
  while (amtWithCoin <= money) {
    let remaining = money - amtWithCoin;
    ways += countWays(remaining, coinsArray, idx + 1, memo);
    amtWithCoin += coinsArray[idx];
  }
  memo.set(key, ways);
  return ways;
}

function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const firstMultipleInput = readLine()
    .replace(/\s+$/g, '')
    .split(' ');

  const n = parseInt(firstMultipleInput[0], 10);

  const m = parseInt(firstMultipleInput[1], 10);

  const c = readLine()
    .replace(/\s+$/g, '')
    .split(' ')
    .map(cTemp => parseInt(cTemp, 10));

  // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

  const ways = getWays(n, c);

  ws.write(ways + '\n');

  ws.end();
}

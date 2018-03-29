const bin = (n, k) => {
  if (0 === k || n === k) {
    return 1;
  }

  return bin(n - 1, k - 1) + bin(n - 1, k);
};

const bin_iter = (n, k) => {
  if (0 === k || n === k) {
    return 1;
  }

  let s = 1;
  for (let i = 1; i <= k; ++i) {
    s *= (n + 1 - i) / i
  }
  return s;
};

const main = () => {
  const [n, k] = [5, 3];
  console.log(`bin(${n}, ${k}) = ${bin(n, k)}`);
  console.log(`bin_iter(${n}, ${k}) = ${bin_iter(n, k)}`);
};

main();

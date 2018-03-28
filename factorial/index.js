const f = (n) => n > 1
  ? f(n - 1) * n
  : 1;

const f_iter = (n) => {
  let s = 1;
  for (let i = 1; i <= n; ++i) {
    s *= i;
  }
  return s;
};

const main = () => {
  for (let i = 0; i <= 10; ++i) {
    console.log(`f(${i}): ${f(i)}, f_iter(${i}): ${f_iter(i)}`);
  }
};

main();

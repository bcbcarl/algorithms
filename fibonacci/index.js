const fib = (n) => {
  if (0 === n) {
    return 0;
  }

  if (1 === n) {
    return 1;
  }

  return fib(n - 1) + fib(n - 2);
};

const fib_iter = (n) => {
  if (0 === n) {
    return 0;
  }

  if (1 === n) {
    return 1;
  }

  let [a, b, c] = [0, 1, 0];
  for (let i = 2; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
};

const fib_math1 = (n) => {
  const SQRT_FIVE = Math.sqrt(5);
  const [a, b, c] = [SQRT_FIVE / 5, (1 + SQRT_FIVE) / 2, (1 - SQRT_FIVE) / 2];
  return parseInt(a * (Math.pow(b, n) - Math.pow(c, n)));
};

const fib_math2 = (n) => {
  const [a, b, c] = [0.447213595499958, 1.618033988749895, -0.6180339887498949];
  return parseInt(a * (Math.pow(b, n) - Math.pow(c, n)));
};

const fib_approx = (n) => {
  const SQRT_FIVE = Math.sqrt(5);
  const phi = (1 + SQRT_FIVE) / 2;
  return Math.round(Math.pow(phi, n) / SQRT_FIVE);
};

const main = () => {
  for (let i = 0; i <= 50; ++i) {
    console.log(
      `n=${i}:`,
      `fib_iter=${fib_iter(i)},`,
      `fib_math1=${fib_math1(i)},`,
      `fib_math2=${fib_math2(i)},`,
      `fib_approx=${fib_approx(i)}`
    );
  }
};

main();

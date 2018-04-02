const gcd = (a, b) => {
  if (0 === a % b) {
    return b;
  }
  return gcd(b, a % b);
};

const gcd_iter = (a, b) => {
  while (b) {
    [a, b] = [b, a % b];
  }
  return a;
};

const main = () => {
  const [a, b] = [18, 32];
  console.log(
    `gcd(${a}, ${b}) = ${gcd(a, b)},`,
    `gcd_iter(${a}, ${b}) = ${gcd_iter(a, b)}`
  );
};

main();

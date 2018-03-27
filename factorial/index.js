const f = (n) => n > 1
  ? f(n - 1) * n
  : 1;


const main = () => {
  for (let i = 0; i <= 10; ++i) {
    console.log(`f(${i}): ${f(i)}`);
  }
};

main();

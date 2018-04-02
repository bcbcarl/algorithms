const ack = (m, n) => {
  if (m) {
    return ack(m - 1, n ? ack(m, n - 1) : 1);
  }
  return n + 1;
};

const main = () => {
  for (let m = 0; m <= 3; ++m) {
    for (let n = 0; n <= 4; ++n) {
      process.stdout.write(`ack(${m}, ${n}) = ${ack(m, n)}\t`);
    }
    process.stdout.write('\n');
  }
};

main();

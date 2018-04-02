const move = (n, pegs) => {
  if (n) {
    let [a, b, c] = pegs;
    move(n - 1, [a, c, b]);
    c.push(a.pop());
    move(n - 1, [b, a, c]);
  }
};

const move_iter = (n, pegs) => {
  // the disks begin on peg 0 and finish on peg 1 or 2
  // according as whether the number of disks is even or odd
  for (let m = 1; m < (1 << n); ++m) {
    const [from, to] = [(m & m - 1) % 3, ((m | m - 1) + 1) % 3];
    pegs[to].push(pegs[from].pop());
    print(from, to, pegs);
  }
};

const print = (from, to, pegs) => {
  console.log(`Move from Peg ${from + 1} to Peg ${to + 1}:`);
  pegs.forEach((x) => console.log(x));
  console.log('=========');
};

const main = () => {
  const n = 3;
  let pegs = [
    Array.from(new Array(n), (val, index) => n - index),
    [],
    []
  ];
  move_iter(n, pegs);
};

main();

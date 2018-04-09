// Heap's algorithm
const perm = (list) => {
  let result = [];

  const generate = (n, list) => {
    if (1 === n) {
      result.push(list.slice());
      return;
    }

    for (let i = 0; i < n - 1; ++i) {
      generate(n - 1, list);
      (n % 2)
      ? [list[0], list[n - 1]] = [list[n - 1], list[0]]
      : [list[i], list[n - 1]] = [list[n - 1], list[i]];
    }
    generate(n - 1, list);
  };

  generate(list.length, list.slice());
  return result;
};

const main = () => {
  const list = [1, 2, 3];
  const result = perm(list);
  console.log(result);
};

main();

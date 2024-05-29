function sum(a, b) {
  return a + b;
}

let x = 2;
let y = 2;

export const Subtitle = () => (
  <h2 style={{ color: "#e5e5e5" }}>
    It's easy like {x} + {y} is {sum(x, y)}
  </h2>
);

//coisas simples ta de boa usar esse método.

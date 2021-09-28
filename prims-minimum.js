process.stdin.resume();
process.stdin.setEncoding("utf-8");

let currentLine = 0;
let inputString = "";

process.stdin.on("data", (raw_data) => {
  inputString += raw_data;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((line) => {
      return line.trim();
    });
  main();
});

function readLine() {
  return inputString[currentLine++];
}

const V = 5; //number of nodes
const INT_MAX = Number.MAX_SAFE_INTEGER;

function main() {
  const graph = [];

  for (let n = 0; n < V; n++) {
    const temp = readLine()
      .split(" ")
      .map((e) => parseInt(e));
    graph.push(temp);
  }
  primMST(graph);
}

function minKey(key, mstSet) {
  let min = INT_MAX;
  let min_index;

  for (let v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min) (min = key[v]), (min_index = v);

  return min_index;
}

function printMST(parent, graph) {
  console.log("Edge \tWeight");
  for (let i = 1; i < V; i++)
    console.log(`${parent[i]} - ${i}\t ${graph[i][parent[i]]}`);
}

function primMST(graph) {
  const parent = new Array(V);
  const key = new Array(V);
  const mstSet = new Array(V);

  // Initialize all keys as INFINITE
  for (let i = 0; i < V; i++) {
    key[i] = INT_MAX;
    mstSet[i] = false;
  }
  key[0] = 0;
  parent[0] = -1; // First node is always root of MST

  for (let count = 0; count < V - 1; count++) {
    const u = minKey(key, mstSet);
    mstSet[u] = true;
    for (let v = 0; v < V; v++)
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        (parent[v] = u), (key[v] = graph[u][v]);
  }

  printMST(parent, graph);
}

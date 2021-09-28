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

const V = 9; //number of nodes
const INT_MAX = Number.MAX_SAFE_INTEGER;

function main() {
  const graph = [];
  for (let n = 0; n < V; n++) {
    const temp = readLine()
      .split(" ")
      .map((e) => parseInt(e));
    graph.push(temp);
  }
  dijkstra(graph, 0);
}

function minDistance(dist, sptSet) {
  // Initialize min value
  let min = INT_MAX,
    min_index;

  for (let v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min) (min = dist[v]), (min_index = v);

  return min_index;
}

function printSolution(dist) {
  console.log("Vertex \t Distance from Source");
  for (let i = 0; i < V; i++) console.log(`${i}\t\t ${dist[i]}`);
}

function dijkstra(graph, src) {
  const dist = new Array(V);
  const sptSet = new Array(V);

  for (let i = 0; i < V; i++) (dist[i] = INT_MAX), (sptSet[i] = false);

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  for (let count = 0; count < V - 1; count++) {
    const u = minDistance(dist, sptSet);

    sptSet[u] = true;

    for (let v = 0; v < V; v++)
      if (
        !sptSet[v] &&
        graph[u][v] &&
        dist[u] != INT_MAX &&
        dist[u] + graph[u][v] < dist[v]
      )
        dist[v] = dist[u] + graph[u][v];
  }
  printSolution(dist);
}

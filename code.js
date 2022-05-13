const input = "I Love Bangladesh";
/*
 * sepearated by " " blank space,
 * Love Bangladesh -> [ 'I', 'Love', 'Bangladesh' ]
 */
const words = input.split(" ");
let reversedWords = [];
/*
 * [first, ...rest] destructers the array
 * Upercase the first char then concatnates with the rest.
 * map(c) map the rest of the char into lowercase
 * returns an array of characters
 */
const capitalize = ([first, ...rest]) => [
    first.toUpperCase(),
    ...rest.map((c) => c.toLowerCase()),
];
/*
 * [...word] turns string to array
 * .reverse() reverses the array
 * [..."Love"].reverse() -> [ 'e', 'v', 'o', 'L' ]
 * join("") concatenates the array to string (arg is an empty separator)
 * push the item back into the reversedWords
 */
for (const word of words) {
    const reversedWord = [...word].reverse();
    const capitalizeWord = capitalize(reversedWord).join("");
    reversedWords.push(capitalizeWord);
}
/*
 * join(" ") concatnates all the words in array with spaces between them
 */
const sentence = reversedWords.join(" ");
/*
 * prints the sentence in console
 */
console.log(sentence);
// compile and run using following command
// tsc --target ES2016 code
// node code
// output: I Evol Hsedalgnab
// live test link
// shorturl.at/lF056

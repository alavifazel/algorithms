/* Key-value sort algorithm */

function keyValueSort(array, maxElement) {
    // Assert maxElement in integer
    var count = Array(maxElement + 1).fill(0);
    var tmp = Array(array.length).fill(0);
    for (const entry of array) {
        count[entry + 1]++;
    }
    for (i = 1; i < count.length; i++) {
        count[i] += count[i - 1];
    }
    for (const entry of array) {
        tmp[count[entry]] = entry;
        count[entry]++;
    }
    return tmp;
}

function keyValueSortMap(map, maxElement) {
    var count = Array(maxElement + 1).fill(0);
    var tmp = Array(map.size).fill(0);
    for (const [key, value] of map.entries()) {
        count[value + 1]++;
    }
    for (i = 1; i < count.length; i++) {
        count[i] += count[i - 1];
    }
    for (const [key, value] of map) {
        tmp[count[value]] = [key, value];
        count[value]++;
    }
    return tmp;
}

let array = [1, 8, 3, 2, 1];
let map = new Map([['string 1', 1], ['string 2', 2], ['string 3', 5], ['string 4', 1], ['string 5', 4]]);

array = keyValueSort(array, 10);
map = keyValueSortMap(map, 10);
console.log(map);

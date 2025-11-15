/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {

    if (n == 0) {
        return arr.slice();
    }
    let flatarr = [];
    for (let i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i])) {
            const nested = flat(arr[i],n-1);
            flatarr.push(...nested);
        } else {
            flatarr.push(arr[i]);
        }
    }

    return flatarr;
};


arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]];
console.log(flat(arr, 1));

function solution(a) {
    const n = a.length;

    const medianIndex = Math.floor((n - 1) / 2);

    return a[medianIndex];
}

console.log(solution([2,4,7]))
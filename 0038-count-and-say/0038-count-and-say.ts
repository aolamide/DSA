function countAndSay(n: number): string {
    if(n === 1) return "1";
    const k = countAndSay(n - 1);
    let result: string = "";

    let count = 1;
    for(let i = 0; i < k.length; i++) {
        if(k[i] === k[i + 1]) count++;
        else {
            result += String(count) + k[i];
            count = 1;
        }
    }

    return result;
};
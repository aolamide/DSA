function closeStrings(word1: string, word2: string): boolean {
    const sortedWord1 = word1.split('').sort().join('');
    const sortedWord2 = word2.split('').sort().join('');
    
    const charsWord1 = Array(26).fill(0);
    const charsWord2 = Array(26).fill(0);
    
    for (const c of word1) {
        charsWord1[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    
    for (const c of word2) {
        charsWord2[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for (let i = 0; i < 26; i++) {
        if ((charsWord1[i] && !charsWord2[i]) || (!charsWord1[i] && charsWord2[i])) {
            return false;
        }
    }

    charsWord1.sort((a, b) => b - a);
    charsWord2.sort((a, b) => b - a);

    for (let i = 0; i < 26; i++) {
        if (charsWord1[i] !== charsWord2[i]) return false;
        if (charsWord1[i] === 0 && charsWord2[i] === 0) break;
    }

    return true;
}

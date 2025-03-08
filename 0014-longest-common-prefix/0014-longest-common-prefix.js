/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length === 1) return strs[0];
    let start = 1;
    let prefix = strs[0].slice(0, start);
    
    while(start <= strs[0].length) {
        for(let i = 1; i < strs.length; i++) {
            if(strs[i].indexOf(prefix) !== 0) {
                return strs[0].slice(0, start - 1);
            }
        }
        start++;
        prefix = strs[0].slice(0, start);
    }
    
    return prefix;
    
};
/**
 * @param {number} n
 * @return {Function} counter
 */


var createCounter = function(n) {
    let cnt=n-1;
    return function counter() {
        return n++;
        
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
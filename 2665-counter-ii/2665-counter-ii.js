/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val2=init;
    let val=init;
    return{
        increment:()=>{
        val++;
        return val;
        
    },
    decrement:()=>{
    val--;
    return val;
        
    },
    reset:()=>{
    val=val2; 
    return val
    }
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let sum=init;
    nums.forEach((index)=>{
       sum=fn(sum,index)
        // console.log(index);
    })
    return sum;
    
};
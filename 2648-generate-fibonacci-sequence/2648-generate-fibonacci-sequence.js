/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let curr = 0;
    let nxt = 1;
    while(true)
    {
        yield curr;
        [curr,nxt]=[nxt,curr+nxt];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
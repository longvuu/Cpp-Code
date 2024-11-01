const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', (st) => {
    rl.question('', (t) => {
        let n = st.length;
        let m = t.length;
        while (st.includes(t)) {
            st = st.split(t).join('');
        }
        console.log(st);
        rl.close();
    });
});

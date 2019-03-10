var fs = require('fs');

fs.readFile('input.txt', function(error, data) {
    if (error) console.error('error:' + error)
    console.log(data.toString());
});

console.log("end ...")

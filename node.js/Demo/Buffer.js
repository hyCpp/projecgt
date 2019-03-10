const buf = Buffer.from('This is my first buffer demo', 'ascii');
console.log(buf.toString());
console.log(buf.toString('hex'))
console.log(buf.toString('base64'))



const buf1 = Buffer.alloc(30)
buf1.write('This is my first buffer demo 2')
console.log(buf1.toString())

const buf2 = Buffer.alloc

const json = JSON.stringify(buf1.toString())
console.log(json.toString())
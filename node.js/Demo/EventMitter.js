var events = require('events');
var eventEmitter = new events.EventEmitter()
eventEmitter.on('some_event', function () {
    console.log('some_event')
});

setTimeout(function () {
    eventEmitter.emit('some_event')
}, 1000);



var fs = require('fs');

var func = function readFunc(error, data) {
    if (error) console.log(error);
    console.log(data.toString());
}

eventEmitter.on('params_event', function (arg1, arg2) {
    console.log('params_event one');
    console.log(arg2);
    fs.readFile('input.txt', arg1);
});


eventEmitter.on('params_event', function (arg1, arg2) {
    console.log('params_event two');
    console.log(arg2);
    fs.readFile('input2.txt', arg1);
});

eventEmitter.emit('params_event', func, 'This is func ptr')



var func1 = function listenTest() {
    console.log('perform one');
}


var func2 = function listenTest() {
    console.log('perform two');
}

eventEmitter.addListener('event', func1);
eventEmitter.addListener('event', func2);

var eventReadNum = eventEmitter.listenerCount('params_event')
var eventTestNum = eventEmitter.listenerCount('event')
console.log('eventReadNum : ' + eventReadNum)
console.log('eventTestNum : ' + eventReadNum)

eventEmitter.removeListener('event', func2);
eventTestNum = eventEmitter.listenerCount('event')
console.log('eventTestNum : ' + eventTestNum)
var events = require("events"); // 引入 events 模块
var eventEmitter = new events.EventEmitter(); // // 创建 eventEmitter 对象

var connectHandler = function connectDemo() { // 创建事件处理程序
    console.log('connect success');
    eventEmitter.emit('data_received'); // 触发 data_received 事件 
}

eventEmitter.on('connectDemo', connectHandler) // 绑定 connection 事件处理程序

eventEmitter.on('data_received', function() { // 使用匿名函数绑定 data_received 事件
    console.log('data_received success')
});

eventEmitter.emit('connectDemo')
console.log('proccess end ...')


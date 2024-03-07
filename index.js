const WillsNodeCAN = require('./build/Release/WillsNodeCAN');

setInterval(() => {
  console.log('test1');
  var result = WillsNodeCAN.ReceivedCANData();
  console.log('test2');
}, 1000);
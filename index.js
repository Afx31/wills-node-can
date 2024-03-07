const testAddon = require('./build/Release/testAddon');
const WillsNodeCAN = require('./build/Release/WillsNodeCAN');

setInterval(() => {
  console.log('test1');
  var result = WillsNodeCAN.ReceivedCANData();
  console.log('test2');
}, 1000);

// Testing
console.log("Hello: ", testAddn.Hello());
console.log("HeresANumber: ", testAddon.HeresANumber());
console.log("AddTenToThisNumber(10): ",   testAddon.AddTenToThisNumber(10));
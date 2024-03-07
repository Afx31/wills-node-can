const WillsNodeCAN = require('./build/Release/WillsNodeCAN');

setInterval(() => {
  console.log('test1');
  var result = WillsNodeCAN.ReceivedCANData();
  console.log('test2');
}, 1000);

// function DumpCANData() {
//   var results = WillsNodeCAN.ReceivedCANData();
//   console.log('CAN output: ');
//   console.log('CAN output: ', results);
//   setTimeout(DumpCANData, 1000);
// }

// DumpCANData();
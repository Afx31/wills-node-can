const Test = require('./build/Release/Test');

console.log('Hello:', Test.Hello());
console.log('HeresANumber:', Test.HeresANumber());
console.log('AddTenToThisNumber(5):', Test.AddTenToThisNumber(5));

const WillsNodeCan = require('./build/Release/WillsNodeCan');

console.log('Hello:', WillsNodeCan.RetrieveCanMessage());